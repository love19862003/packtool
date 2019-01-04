--proto文件目录
local function proto_path() 
  return out_dir() .. "/proto/"
end

local function proto_des_path() 
  return out_dir() .. "/pbs/"
end

--proto导出lua文件目录
local function proto_lua_path() 
  return out_dir() .. "/lua/"
end

local function proto_data_path()
  return out_dir() .. "/data/"
end

--proto版本标识
local function proto_type_syntax()
  local type = proto_type()
  if type == 0 then
    return "syntax = \"proto2\";\n";
  end
  
  if type == 1 then 
    return "syntax = \"proto3\";\n";
  end
  print(type)
  assert(false,type)
  return ""
end

--proto关键字 optional
local function proto_optional()
   if proto_type() == 0 then
    return "optional ";
  end
  
  return ""
end

--proto命名空间
local function proto_name_space()
  if string.len(name_space()) > 0 then 
    return "package "..name_space()..";\n"
  else
    return ""
  end
end

--基础类型的多维数组定义
function write_proto_message_basic(basic_info, space)
  local str = add_space(space) 
  local res = str.."message " .. common_group_name()..basic_info.key
  res =  res .."{\n" ..str.." repeated " .. basic_info.key.. " array = 1; \n"..str.."}\n"  
  return res
end

-- 新增类型
function write_proto_common_coordinate(basic_info, space)
  local str = add_space(space)
  local op = " "..proto_optional()
  local res = str .. "message "..basic_info.key .. "{"
  res = res .. "\n" .. str .. op .." float x = 1;" 
  res = res .. "\n" .. str .. op .." float y = 2;"
  res = res .. "\n" .. str .. op .." float z = 3;"
  res = res .. "\n" .. str .. op .." float o = 4;"
  res = res .. "\n}\n"
  return res  .. write_proto_message_basic(basic_info, space)
end

-- common proto文件定义
local function write_proto_common()
  local msg = {}
  for k, v in pairs(g_basic_type) do 
    if k ~= "none" and k ~= "enum" and k ~= "self_enum" then
      print(k)
     table.insert(msg, v.writer_proto_common(v, 0) )
    end
  end
  return table.concat(msg, "\n")
end

--枚举的名字
local function proto_enum_name(name,t, group)
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

-- 写入类型
local function write_proto_type(head, space)
  local g = get_basic_type_by_id(head.basic_type)
  local call = g.writer
  if call ~= nil then 
    return call(head, space)
  else
    --Dump.info(head)
    assert(false)
    return nil
  end
end

--输出表格proto文件
local function write_proto_table(name)
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
    tabFile:write(write_proto_type(head, 2))
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

-- 输出lua的格式文件
local function write_proto_table_lua( t)
   local trs = t.records
   local clsName = t:name()..tail_config_name()
   local res = {}
   for _, r in pairs (trs) do 
      local record = {}
      for _, h in pairs(t.heads) do 
        record[h.name] = r.fields[h.index]
      end
      table.insert(res, record)
   end
   table.save(clsName, res, proto_lua_path()..t:name()..".lua", -1)
   return res
end

-- 输出所有表格的lua
local function write_proto_lua()
  local data = {}
  data.version = version()
  for k, t in pairs(g_tables) do
    print(k)
    data[k] = write_proto_table_lua(t)
  end
  return data
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
  
  -- lua tables
  local data = write_proto_lua()
  
  -- 输出c++管理类
  write_cpp_header()
  write_cpp_content()
  
  --输出打包后的数据和文件
  genratorProto()
  saveProtoData(regList, data)
  save_layout()
end



--local lfs = require("lfs")
--生成导出数据
local function execute_proto(file)
  local protoPath = proto_path()
  local pbsPath = proto_des_path()
  
  local cmd1 = execute_tool() .." " .. "--proto_path="..protoPath.." --cpp_out="..protoPath.." "..protoPath..file..".proto"
  local cmd2 = execute_tool() .." " .. "--proto_path="..protoPath.." --descriptor_set_out="..pbsPath..file..".pb" .." "..protoPath..file..".proto"
  os.execute(cmd1)
  os.execute(cmd2)
end

--生成导出的PB文件和代码
function genratorProto()
  execute_proto(common_group_name())
  execute_proto(common_enum_name()..tail_config_name())
  for k, t in pairs(g_tables) do
    execute_proto(k..tail_config_name())
  end
  execute_proto(all_config_name()..tail_config_name())
end

--读取打包后的数据
local protobuf = require "protobuf"
function readPackageData()
  local pbsPath = proto_des_path()
  local registerListFile = io.open(pbsPath.."registerList.lua")
  if not registerListFile then return nil end
  
  registerListFile:close()
  local regList = dofile(pbsPath.."registerList.lua")
  
  for _, v in pairs(regList) do 
   protobuf.register_file(pbsPath .. v .. ".pb")
  end
  
  local message = name_space() .. "." .. all_config_name() .. tail_config_name()
  local file = assert(io.open(proto_data_path () .. out_file_name() .. ".bin", "rb"))
  if nil == file then return nil end
  local buffer = file:read("*all")
  local data = assert(protobuf.decode(message, buffer), "decode failed")
  file:close()
 
  return data
end

--生成PBC需要的文件注册顺序序列
local function registerProtobuf(regList)
   local pbsPath = proto_des_path()
   local tab = {}
   
   protobuf.register_file(pbsPath .. common_enum_name()..tail_config_name() .. ".pb")
   protobuf.register_file(pbsPath .. common_group_name() .. ".pb")
   for _, v in pairs(regList) do 
    protobuf.register_file(pbsPath .. v..tail_config_name() .. ".pb")
   end
   protobuf.register_file(pbsPath .. all_config_name()..tail_config_name() .. ".pb")
   
   -- save to lua
   table.insert(tab, common_enum_name()..tail_config_name())
   table.insert(tab, common_group_name())
   for _, v in pairs(regList) do 
    table.insert(tab, v..tail_config_name())
   end
   table.insert(tab, all_config_name()..tail_config_name())
   table.save("registerList", tab, pbsPath .. "registerList.lua")

   -- save to txt
   local ifile = assert(io.open(pbsPath .. "registerList.txt", "wb"))
   for _, v in pairs(tab) do 
    ifile:write(v.."\n")
   end
   ifile:close()
end

--输出打包数据并保存二进制文件
function saveProtoData(regList, data)
  registerProtobuf(regList)
  local message = name_space() .. "." .. all_config_name() .. tail_config_name()
  local buffer = protobuf.encode(message, data)
  assert(buffer)
  local file = assert(io.open(proto_data_path () .. out_file_name() .. ".bin", "wb"))
  file:write(buffer)
  file:close()
  
  --比较新老版本的数据差异，并写入log
  compare_package()
end





