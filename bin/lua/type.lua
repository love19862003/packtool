require("functions")
require("reader")
require("writer")
require("enum")
--基础类型定义
g_basic_type = {
  ["none"] = { 
      type = 0,
      reader = reader_none, 
      writer = write_none,
      key = "",
      },
  ["int"] = { 
      type = 1, 
      reader = reader_number, 
      writer = write_field,
      key = "int32",
      },
  ["float"] = {
      type = 2, 
      reader = reader_number,
      writer = write_field,
      key = "float",
      },
  ["string"] = { 
      type = 3, 
      reader = reader_string, 
      writer = write_field,
      key = "string",
      },
  ["bool"] = { 
      type = 4, 
      reader = reader_bool,
      writer = write_field,
      key = "bool",
      },
  ["enum"] = { 
      type = 5, 
      reader = read_enum_value,
      writer = write_none,
      key = "enum",
      },
  ["self_enum"] = {
      type = 6, 
      reader = reader_self_enum,
      writer = write_field_enum,
      key = "self_enum",
      },

}

local read_function = {}
local write_function = {}

for _, v in pairs(g_basic_type) do 
  read_function[v.type] = v.reader
  write_function[v.type] = v.writer
end
   

g_muti_type = {
  basic = 0,  --基础类型
  array = 1,  --数组形式
  group = 2,  --多维数组形式
}


function isEnumType(type)
  return type == g_basic_type["enum"].type
end

function isNoneType(type)
  return type == g_basic_type["none"].type
end

function isSelfEnumType(type)
  return type == g_basic_type["self_enum"].type
end

-- g_muti_type
function isSingleType(type)
  return type == g_muti_type.basic
end

function isArrayType(type)
  return type == g_muti_type.array
end

function isGroupType(type)
  return type == g_muti_type.group
end

--检测类型是否能做表的索引
function checkKeyType(muti, type)
  if muti ~= g_muti_type.basic then 
    return false
  end
  
  if isNoneType(type) or isEnumType(type) then 
    return false
  end
  
  return type <= g_basic_type["self_enum"].type 
end

--根据g_basic_type获取定义
function get_basic_type_by_id(type)
  for k, v in pairs(g_basic_type) do 
    if type == v.type then 
      return v
    end
  end
  return nil
end


-- 读取类型的基础类型
local function get_basic_type(name)
  local index = g_basic_type[name]
  if index == nil  then
    if g_enum_type[name] ~= nil then
      return g_basic_type.self_enum.type
    else
      return g_basic_type["none"].type
    end
  else
    return index.type
  end
end

-- 读取类型的多维属性
local function get_muti_type(type)
  return g_muti_type[type] or g_muti_type.basic
end

-- 读取类型
function read_type(type_name_str)
 local type_name = type_name_str
 local r1, r2, muti, name = string.find(type_name, "^(%a+)<(.+)>$")
 if r1 ~= nil then 
  return get_muti_type(muti), get_basic_type(name), name
 else
  return g_muti_type.basic, get_basic_type(type_name), type_name
 end
end

-- 写入类型
function write_type(basic, muti, type_name, op)
  local call = write_function[basic]
  if call ~= nil then 
    return call(muti, type_name, op)
  else
    return nil
  end
end

-- 读取数值local field = read_data(value, head.basic_type, head.muti_type, head.type_basic_name)
function read_data(value,head)
  local call = read_function[head.basic_type]
  if call ~= nil then
    return call(value, head)
  else
    return nil
  end
end





