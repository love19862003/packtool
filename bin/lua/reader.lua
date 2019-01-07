--读取excel的数据相关
--去掉空格
local function replace_basic(str)
  str = string.gsub(str, " ", "")
  return str
end

--去掉数组相关的标识
local function replace_array(str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "%]", "")
  str = string.gsub(str, "%[", "")
  return str
end

--去掉数组相关的标识
local function replace_group(str)
  --print("replace_group:"..str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "%],%[", "|")
  str = string.gsub(str, "%]", "")
  str = string.gsub(str, "%[", "")
  --print("replace_group:"..str)
  return str
end

local function replace_super_group(str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "%],%[", "|")
  str = string.gsub(str, "%},%{", "#")
  str = string.gsub(str, "%]", "")
  str = string.gsub(str, "%[", "")  -- {[],[]},{}
  str = string.gsub(str, "%}", "")
  str = string.gsub(str, "%{", "") 
  return str
end


--读取数组
local function read_array(value)
   value = replace_array(value)
   if value == "" then 
    return  {}
   end
   local res = string.split(value, ",")
   return res
end 

--读取二维数组
local function read_group(value)
  value = replace_group(value)
  if value == "" then 
    return  { }
  end
  local r = string.split3(value, "|" ,",")
  local res = {}
  for _, a in pairs(r) do
      local arr = {}
      for k, v in pairs(a) do
        table.insert(arr, v)
      end      
      table.insert(res, {array = arr})
  end
  --Dump.info(res, value)
  return res
end

local function read_super_group(value)
  value = replace_super_group(value)
  if value == "" then 
    return  { }
  end
  local r = string.split3(value, "#" ,"|")
  local res = {}
  for _, a in pairs(r) do
      local arr = {}
      for k, v in pairs(a) do
        local t = string.split(v, ",")
        if v == "" then t = {} end
        table.insert(arr, t)
      end      
      table.insert(res, {array = arr})
  end
  return res
end

--无效类型读取
function reader_none(str, muti)
  return nil
end

--读取基础类型
local function reader_basic(str, head)
  --print(str)
  local muti = head.muti_type
  if muti == g_muti_type.basic then
    str = replace_basic(str)
    return str
  end
  if muti == g_muti_type.array then
    return read_array(str)
  end
  
  if muti == g_muti_type.group then 
    return read_group(str)
  end
end

--读取数字
function reader_number(str, head)
  local tal = reader_basic(str, head)
  if type(tal) ~= "table" then 
    tal = tonumber(tal) or 0
  else
    for k, v in pairs(tal) do
        if type(v) == "table" then
          for k1, v2 in pairs(v.array) do 
            v.array[k1] = tonumber(v2) or 0
          end
        else
          tal[k] = tonumber(v) or 0
        end
    end
  end
  return tal
  
end

--读取字符串
function reader_string(str, head)
  str = string.gsub(str, "\"", "\\\"")
  str = string.gsub(str, "\n", "\\\n")
  str = string.gsub(str, "\t", "\\\t")
  return reader_basic(str, head)
 
end

--检测是否能转成bool
local function toboolean(tal)
   if tonumber(tal) then tal = tonumber(tal) > 0 end 
   if tal == "true" then tal = true end
   if tal == "false" then tal = false end
   if type(tal) ~= "boolean" then tal = false end
   return tal
end

--读取boolean
function reader_bool(str, head)
  local tal = reader_basic(str, head)
  if type(tal) ~= "table" then 
    return toboolean(tal)
  else
    for k, v in pairs(tal) do
        if type(v) == "table" then
          for k1, v2 in pairs(v.array) do 
            v.array[k1] = toboolean(v2)
          end
        else
          tal[k] = toboolean(v)
        end
    end
  end
  return tal
  
end

--读取自定义枚举
function reader_self_enum(str, head)
  if g_enum_type[head.type_basic_name] == nil then 
    return nil
  end
 
  local tal = reader_basic(str, head)
  --Dump.info(tal, str)
  if type(tal) ~= "table" then 
    if not check_enum_value(head.type_basic_name,tal) then
      print(tal)
      assert(false)
      return nil
    end
  else
     for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v.array) do 
          if not check_enum_value(head.type_basic_name,v2) then
            print(v2)
            assert(false, v2)
            return nil
          end
        end
      else
        if not check_enum_value(head.type_basic_name,v) then
          print(v)
          assert(false, v)
          return nil
        end
      end
    end
  end
  return tal
end




--
local function reader_coordinate_table(t)
  local tal = {}
  tal.x = tonumber(t[1]) or 0
  tal.y = tonumber(t[2]) or 0
  tal.z = tonumber(t[3]) or 0
  tal.o = tonumber(t[4]) or 0
  return tal  
end
function reader_coordinate(str, head)
  str = string.gsub(str, "\"", "\\\"")
  str = string.gsub(str, "\n", "\\\n")
  str = string.gsub(str, "\t", "\\\t")
  local muti = head.muti_type
  local tal = {}
  if muti == g_muti_type.basic then
    local t = read_array(str)
    tal = reader_coordinate_table(t)
  end
  
  if muti == g_muti_type.array then
    local t = read_group(str)
    for _, v in pairs(t) do 
      if v.array ~= nil then 
        table.insert(tal,  reader_coordinate_table(v.array))
      end
    end
  end
  
  if muti == g_muti_type.group then 
    local group =  read_super_group(str)
    for _ , g in pairs(group) do 
      if g.array then 
        local record = { array = {}}
        for _, v in pairs(g.array) do 
          table.insert(record.array, reader_coordinate_table(v))
        end
        table.insert(tal, record)
      end
    end
    
   
  end
  
  --assert(false)
 -- Dump.info(tal, value)
  return tal
end

--
local function reader_int5_table(t)
  local tal = {}
  tal.value1 = tonumber(t[1]) or 0
  tal.value2 = tonumber(t[2]) or 0
  tal.value3 = tonumber(t[3]) or 0
  tal.value4 = tonumber(t[4]) or 0
  tal.value5 = tonumber(t[5]) or 0
  return tal  
end
function reader_int5(str, head)
  str = string.gsub(str, "\"", "\\\"")
  str = string.gsub(str, "\n", "\\\n")
  str = string.gsub(str, "\t", "\\\t")
  local muti = head.muti_type
  local tal = {}
  if muti == g_muti_type.basic then
    local t = read_array(str)
    tal = reader_int5_table(t)
  end
  
  if muti == g_muti_type.array then
    local t = read_group(str)
    for _, v in pairs(t) do 
      if v.array ~= nil then 
        table.insert(tal,  reader_int5_table(v.array))
      end
    end
  end
  
  if muti == g_muti_type.group then 
    local group =  read_super_group(str)
    for _ , g in pairs(group) do 
      if g.array then 
        local record = { array = {}}
        for _, v in pairs(g.array) do 
          table.insert(record.array, reader_int5_table(v))
        end
        table.insert(tal, record)
      end
    end
    
   
  end
  
  --assert(false)
 -- Dump.info(tal, value)
  return tal
end


