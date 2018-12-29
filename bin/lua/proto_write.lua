local function proto_path() 
  return out_dir() .. "\\proto\\"
end

local function proto_lua_path() 
  return out_dir() .. "\\lua\\"
end

local function proto_type_syntax()
  if proto_type() == 0 then
    return "syntax = \"proto2\";\n";
  end
  
  if proto_type() == 1 then 
    return "syntax = \"proto3\";\n";
  end
  return ""
end

local function proto_optional()
   if proto_type() == 0 then
    return "optional ";
  end
  
  return ""
end

local function proto_name_space()
  if string.len(name_space()) > 0 then 
    return "package "..name_space()..";\n"
  else
    return ""
  end
end

--基础类型的多维数组定义
local function write_message_basic(basic_info, space)
  local str = add_space(space) 
  local res = str.."message " .. common_group_name()..basic_info.key
  res =  res .."{\n" ..str.." repeated " .. basic_info.key.. " array = 1; \n"..str.."}\n"  
  return res
end

--普通字段
function write_proto_field(head, space)
  local optional = proto_optional()
  local muti = head.muti_type
  local basic = head.basic_type
  local basic_type = get_basic_type_by_id(basic)
  local key = basic_type.key
  local str = add_space(space) 
  if muti == g_muti_type.basic then
    str = str..optional .. key.." "
  end
  
  if muti == g_muti_type.array then
     str = str.."repeated ".. key.." "
  end
  
  if muti == g_muti_type.group then 
      str = str.."repeated "..common_group_name().. key.." "
  end
  
  str = str .. head.name.." = "..head.index..";//"..head.comment.."\n"
  
  return str
end

--枚举字段
function write_proto_field_enum(head, space)
  local optional = proto_optional()
  local str = add_space(space) 
  local muti = head.muti_type
  local enumName = head.type_basic_name
  if muti == g_muti_type.basic then
    str = str.. optional .. proto_enum_name(enumName, head.table).." "
  end
  
  if muti == g_muti_type.array then
     str = str.."repeated ".. proto_enum_name(enumName, head.table).." "
  end
  
  if muti == g_muti_type.group then 
    str = str.."repeated "..proto_enum_name(enumName, head.table, true) .." "
  end
  
  str = str .. head.name.." = "..head.index..";//"..head.comment.."\n"
  return str
end


-- common
local function write_proto_common()
  local msg = {}
  for k, v in pairs(g_basic_type) do 
    if k ~= "none" and k ~= "enum" and k ~= "self_enum" then
     table.insert(msg, write_message_basic(v, 0)) 
    end
  end
  return table.concat(msg, "\n")
end


--枚举的名字
function proto_enum_name(name,t, group)
  local en = g_enum_type[name]
  if group then
     if en.table ~= "" and en.table ~= t then
       return en.table..tail_config_name().."."..common_group_name()..en.name
      else
       return common_group_name()..en.name
     end
  else
     if en.table ~= "" and en.table ~= t then
       return en.table..tail_config_name().."."..en.name
      else
       return en.name
     end
  end
end

--自定义枚举类型
local function write_message_enum(name, space)
  local en = g_enum_type[name]
  local str = add_space(space)
  local res = str .. "enum "..en.name .. "{\n"
  for _, v in pairs(en.values) do
    res = res..str.." "..v[1] .. " = ".. v[2] ..";//"..v[3].."\n" 
  end
  res = res.."\n"..str.."};\n"
  res = res..str.."message " .. common_group_name()..en.name.. "{\n"
  res = res..str.." repeated " .. en.name.. " array = 1; \n"..str.."}\n" 
  return res
end
--全局枚举定义
local function write_global_enum()
  local msg = {} 
  for k, v in pairs(g_enum_type) do 
    if v.table == "" then
      table.insert(msg, write_message_enum(k, 0))
    end
  end
  return table.concat(msg, "\n")
end

--表格自定义枚举
local function write_table_enum(name, space)
  local msg = {} 
  for k, v in pairs(g_enum_type) do
    if name == v.table then 
      table.insert(msg, write_message_enum(k, space))
    end
  end
  return table.concat(msg, "\n")
end

--输出表格proto文件
function write_proto_table(name)
  local tab = g_tables[name]
  if not tab then return end
  local protoPath = proto_path()
  local clsName = name..tail_config_name()
  local tabFile =  assert(io.open(protoPath .. clsName .. ".proto", "w+"))
  tabFile:write(proto_type_syntax())
  tabFile:write(proto_name_space())
 
  
  local depends = tab:getDepends()
  for _, de in pairs(depends) do 
    tabFile:write("import \""..de..tail_config_name()..".proto\";\n")
  end
  
  if tab.depend_common then
    tabFile:write("import \""..common_group_name()..".proto\";\n")
  end
  
  tabFile:write("message "..clsName .. "{\n")
  tabFile:write(write_table_enum(name, 2))
  
  local heads = tab.heads
  
  for k, head in pairs(heads) do 
    tabFile:write(write_type(head, 2))
    --if isSelfEnumType(head.basic_type) then 
    --  tabFile:write(write_proto_field_enum(head, 2))
    --else
    --  tabFile:write(write_proto_field(head, 2))
    --end
  end  
  tabFile:write("}\n")
  tabFile:close()
end
--计算表格的依赖顺序
local function check_reg_depends(name, reg)
  for _, v in pairs(reg) do
      if v == name then
        return reg
      end
  end
    
  local tab =  g_tables[name]
  if tab  then 
    local depends = tab:getDepends()
    for _, v in pairs(depends) do
      
      if v ~= common_enum_name() then
        print(name.." depends ".. v)
        check_reg_depends(v, reg)
      end
    end
    
    for _, v in pairs(reg) do
      if v == name then
        assert(false, "reg table list error with name "..name)
        return nil
      end
    end
    
    table.insert(reg, name)
  end
  return reg
end

--输出所有的proto文件
function write_proto()
  local protoPath = proto_path()
  local commonFile = assert(io.open(protoPath .. common_group_name() .. ".proto", "w+"))
  commonFile:write(proto_type_syntax())
  commonFile:write(proto_name_space())
  commonFile:write(write_proto_common())  
  commonFile:close()
  
  local globalEnumFile = assert(io.open(protoPath .. common_enum_name()..tail_config_name() .. ".proto", "w+")) 
  globalEnumFile:write(proto_type_syntax())
  globalEnumFile:write(proto_name_space())
  globalEnumFile:write(write_global_enum())
  globalEnumFile:close()
  
  --write table
  for k, _ in pairs(g_tables) do
    write_proto_table(k)  
  end
  
  local mgrClsName = all_config_name()..tail_config_name()
  local mgrFile = assert(io.open(protoPath .. mgrClsName .. ".proto", "w+"))
  mgrFile:write(proto_type_syntax())
  mgrFile:write(proto_name_space())
  mgrFile:write("import \""..common_enum_name()..tail_config_name()..".proto\";\n")
  mgrFile:write("import \""..common_group_name()..".proto\";\n")
  
  local regList = {}
  for k, _ in pairs(g_tables) do
    check_reg_depends(k, regList)  
  end
  
  for _, v in pairs(regList) do 
     mgrFile:write("import \""..v..tail_config_name()..".proto\";\n")
  end
  
  mgrFile:write("message "..mgrClsName .. "{\n")
  mgrFile:write(add_space(2)..proto_optional().."string version = 1;\n")
  
  local tmp = {}
  for k, t in pairs(g_tables) do
    tmp[t:getTableIndex()] = k
  end
  for k, v in pairs(tmp) do
    local clsName = v..tail_config_name()
    mgrFile:write(add_space(2).."repeated "..clsName.." "..v.." = "..k..";\n")  
  end
  mgrFile:write("}\n")
  mgrFile:close()
  
end

-- 输出lua的格式文件
local function write_proto_table_lua( t)
   local trs = t.records
   local clsName = t:name()..tail_config_name()
   local file = assert(io.open(proto_lua_path() .. t:name() .. ".lua", "w+"))
   file:write("local ".. clsName .. " = {\n")    
   
   for _, r in pairs (trs) do 
      file:write(" {\n")
      for _, h in pairs(t.heads) do 
        local out =  text_object(r.fields[h.index])
        --print(type(out))
        file:write("  "..h.name .. " =".. out .. ",\n")
      end
      file:write(" },\n")
   end
  
   file:write("}\n")
   file:write("return "..clsName) 
   file:close()
end

-- 输出所有表格的lua
function write_proto_lua()
  for k, t in pairs(g_tables) do
    write_proto_table_lua(t)
  end
end