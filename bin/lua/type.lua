require("functions")
require("reader")
require("writer")
require("enum")
--基础类型定义
basic_type = {
  ["none"] = { type = 0, reader = reader_none, writer = write_none},
  ["int"] = { type = 1, reader = reader_number, writer = write_none},
  ["float"] = { type = 2, reader = reader_number, writer = write_none},
  ["string"] = { type = 3, reader = reader_string, writer = write_none},
  ["bool"] = { type = 4, reader = reader_bool, writer = write_none},
  ["enum"] = { type = 5, reader = read_enum_value, writer = write_none},
  ["self_enum"] = { type = 6, reader = reader_self_enum, writer = write_none},
  --["coordinate"] = { type = 7, reader = reader_coordinate},
}


read_function = {}

for _, v in pairs(basic_type) do 
  read_function[v.type] = v.reader
end
   

muti_type = {
  basic = 0,  --基础类型
  array = 1,  --数组形式
  group = 2,  --多维数组形式
}


function isEnumType(typen)
  return type == basic_type["enum"].type
end

function isNoneType(type)
  return type == basic_type["none"].type
end

function isSelfEnumType(type)
  return type == basic_type["self_enum"].type
end

-- muti_type
function isSingleType(type)
  return type == muti_type.basic
end

function isArrayType(type)
  return type == muti_type.array
end

function isGroupType(type)
  return type == muti_type.group
end

function checkKeyType(muti, type)
  if muti ~= muti_type.basic then 
    return false
  end
  
  if isNoneType(type) or isEnumType(type) then 
    return false
  end
  
  return type <= basic_type["self_enum"].type 
end



-- 读取类型的基础类型
local function get_basic_type(name)
  local index = basic_type[name]
  if index == nil  then
    if enum_type[name] ~= nil then
      return basic_type.self_enum.type
    else
      return basic_type["none"].type
    end
  else
    return index.type
  end
end

-- 读取类型的多维属性
local function get_muti_type(type)
  return muti_type[type] or muti_type.basic
end

-- 读取类型
function read_type(type_name)
 local r1, r2, muti, name = string.find(type_name, "^(%a+)<(%a+)>$")
 if r1 ~= nil then 
  return get_muti_type(muti), get_basic_type(name), name
 else
  return muti_type.basic, get_basic_type(type_name), type_name
 end
end

-- 读取数值
function read_data(value, basic, muti, type_name)
  local t = read_function[basic]
  if t ~= nil then
    return t(value, muti, type_name)
  else
    return nil
  end
end



