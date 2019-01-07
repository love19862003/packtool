-- 数据检测相关
g_checks = {}
local g_check_types = {
  _NONE_ = 0 ,
  _ENUM_ = 1 ,
  _HEAD_ = 2 ,
  _NUMBER_ = 3,
}

local function check_path()
  return  out_dir() .. "/info/check_condition.lua" 
end

--去掉空格
local function replace(str)
  return string.gsub(str, " ", "")
end

--获取需要检测的表和对应的字段 table.head_name
local function check_table_head(str)
  local name, h = string.split2(str, "%.")
  if not name or not h then 
    return nil, nil
  end
  
  local tab = g_tables[name] 
  if not tab then return nil, nil end
  
  local head = tab:getHead(h)
  if not head then return nil, nil end
  
  return name, head
end

-- 检测枚举是否存在
-- en.name  envalue
local function en_value_check(name, str)
  local n = tonumber(str) or str
  local res, v = check_enum_value(name, n)
  if not res then return nil, nil end
  if not v then 
    return name, nil
  end
  return name, v[1] 
end

--获取对应的枚举和值
--[en_name[.en_value]]
--table.ensubname.envalue or table.ensubname 
--global_enname.envalue or global_enname
local function check_en_value(str)
  local list = string.split(str, "%.")
  local len = #list
  if len == 1 and get_enum(list[1]) ~= nil then
     return list[1], nil
  end
  
  if len == 2 then 
      local en, value =  en_value_check(list[1], list[2])
      if en ~= nil then
        return en, value
      end
  end
  
  if len >= 3 then 
    local en, value = en_value_check(list[1].."."..list[2], list[3])
    if en ~= nil then
        return en, value
    end
  end
  
  return nil, nil 
  
end

--检测数据的类型和定义
local function check_value_args(index, str)
  local con = {type = g_check_types._NONE_, index = index}
  local tab, head = check_table_head(str)
  -- 在另外一张表里查找
  if tab ~= nil and head ~= nil then 
    con.type = g_check_types._HEAD_
    con.head = {table = tab, index = head.index}
  else 
    --在自定义枚举里查找
    local en, value  = check_en_value(str)
    if en ~= nil then 
      con.type = g_check_types._ENUM_
      con.en = {name = en, value = value}
    else
    --转成成数字
      local value1 = tonumber(str)
      if value1 ~= nil or str == "num" then 
        con.type = g_check_types._NUMBER_
        con.number = value1
      end
    end
  end
  return con  
end

--检测单个条件定义
local function check_value_con(value, con)
  if not con then return true end
  
  if con.type == g_check_types._NONE_ then return true end
  
  if con.type == g_check_types._ENUM_ then
    local en, str = check_enum_value(con.en.name, value)
    if not en  or ( con.en.value ~= nil and con.en.value ~= str)then 
      return false
    end
    
    return true
  end
  
  if con.type == g_check_types._NUMBER_ then 
    if type(value) ~= "number" then 
      --print( value .. " " ..type(value)) 
      return false 
    end 
   
    if con.number ~= nil and con.number ~= value then 
       --print((con.number or "nil").. " ".. value)
      return false 
    end
    
    return true
  end
  
  if con.type == g_check_types._HEAD_ then 
    local tab = g_tables[con.head.table]
    for _, r in pairs(tab.records) do 
      if r.fields[con.head.index] == value then 
        return true
      end
    end
  end
  return false
end

--检测数据条件的解析
-- {check1},{check2},{check3}
-- check = {}
local function check_content_reader(content)
  content = replace(content)
  content = string.gsub(content, " ", "")
  content = string.gsub(content, "%],%[", "|")
  content = string.gsub(content, "%]", "")
  content = string.gsub(content, "%[", "")
  
  local r = string.split3(content, "|" ,",")
  local g = {}
  for _, sub in pairs(r) do 
    local arr_con = {}
    for k , av in pairs(sub) do 
      local con = check_value_args(k, av) 
      table.insert(arr_con, con)
    end
    table.insert(g, arr_con)
  end
  return g
end

--保存数据验证信息
local function save_check_config()
  table.save("g_checks", g_checks, check_path())
end

--检测数据的合法性
local function table_record_field_signal_basic_check(tab, head, v, signal_check)
    local type = get_basic_type_by_id(head.basic_type)
    if type.checker then 
      return type.checker(v, signal_check)
    else
      return true
    end
end

--检测单个数据
local function table_record_field_signal_check(tab, head, value, check)
  if nil == check then return true end
  for _, signal_check in pairs(check) do 
    if table_record_field_signal_basic_check(tab, head, value, signal_check) then 
      return true
    end
  end
  er("数据检测错误 表:" .. tab:name() .. " 检测条件:" .. text_object(check) .. " 字段:".. head.name .. " 值:"..text_object(value))
  return false
end

--单记录的单个字段的数据检查
local function table_record_field_check(tab, index, value, check)
  local head = tab:getHead(index)
  if not head then return false end
  if isSingleType(head.muti_type) then  
    return table_record_field_signal_check(tab, head, value, check)  
  end 
  if isArrayType(head.muti_type) then 
    for _, v in pairs(value) do 
      if not table_record_field_signal_check(tab, head, v, check) then 
        return false
      end
    end
  end
  if isGroupType(head.muti_type) then 
    for _, g in pairs(value) do
      for _, v  in pairs(g.array) do
        if not table_record_field_signal_check(tab, head, v, check) then 
          return false
        end
      end
    end
  end
  
  return true
end

--表格内单挑记录的数据检查规范
local function table_record_check(tab, record, check)
  local res = true
  for i, v in pairs(record.fields) do 
    if check[i] ~= nil then
      local c =  table_record_field_check(tab, i,v, check[i]) 
      local head = tab:getHead(i)
      if not c then
        er("数据检查发现错误表格:" .. tab:name() .. " 记录ID:" .. record.index .. " 字段:".. head.name .. " 值:"..text_object(v))
        res = false
      end
    end
  end  
  return res
end
--检测表格内所有记录是否符合数据检查规范
local function table_check(tab, check)
  local res = true
  for _, r in pairs(tab.records) do 
    if not table_record_check(tab, r, check) then 
      res = false
    end
  end
  return res
end

-- 不需要检测
function check_none(value, signal_check)
  return true
end

--检测数字
function check_number(value, signal_check)
  for _, c in pairs(signal_check) do 
    if check_value_con(value, c) then 
      return true
    end
  end
  
  print("check_number value ".. text_object(value) .. " con:".. text_object(signal_check))
  return false
end

--检测自定义坐标
function check_coordinate(value, signal_check)
  local res = true
  if not check_value_con(value.x, signal_check[1]) then
    res = false
  end
    
  if not check_value_con(value.y, signal_check[2]) then
    res = false
  end
  
  if not check_value_con(value.z, signal_check[3]) then
    res = false
  end
  
  if not check_value_con(value.o, signal_check[4]) then
    res = false
  end
  return res
end

--检测自定义int5
function check_int5(value, signal_check)
  local res = true
  if not check_value_con(value.value1, signal_check[1]) then
    res = false
  end
    
  if not check_value_con(value.value2, signal_check[2]) then
    res = false
  end
  
  if not check_value_con(value.value3, signal_check[3]) then
    res = false
  end
  
  if not check_value_con(value.value4, signal_check[4]) then
    res = false
  end
  
   if not check_value_con(value.value5, signal_check[5]) then
    res = false
  end
  return res
end


-- 增加表格的针对表head的检测
function add_check_field(s, content)
  s = replace(s)
  content = replace(content)
  
  local tab, head  = check_table_head(s)
  if not tab or not head then return end
  local check = check_content_reader(content)
  local index = head.index
  g_checks[tab] = g_checks[tab] or {table = tab, check = {}, heads = {}}
  g_checks[tab].check[index] = check 
  g_checks[tab].heads[index] = head.name
end
-- 检测数据
function check_data()
  save_check_config()
  for _, en in pairs(g_enum_type) do 
    if en.table ~= "" and nil == g_tables[en.table] then 
      er("检测到枚举定义错误:" .. en.full_name, "没有找到表格:"..en.table)
      return false
    end
  end
  
  local res = true
  for name, tab in pairs(g_tables) do 
    if nil ~= g_checks[name] then 
      if not table_check(tab, g_checks[name].check) then 
        res = false
      end
    end
  end
  return res
end