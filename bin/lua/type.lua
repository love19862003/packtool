require("functions")
require("reader")
require("enum")
--基础类型定义
basic_type = {
  ["none"] = { type = 0, reader = reader_none},
  ["int"] = { type = 1, reader = reader_int},
  ["float"] = { type = 2, reader = reader_float},
  ["string"] = { type = 3, reader = reader_string},
  ["bool"] = { type = 4, reader = reader_bool},
  ["enum"] = { type = 5, reader = read_enum_value},
  ["self_enum"] = { type = 6, reader = reader_self_enum},
}

muti_type = {
  basic = 0,  --基础类型
  array = 1,  --数组形式
  group = 2,  --多维数组形式
}


function isEnumType(type)
  return type == basic_type["enum"].type
end


-- 读取类型的基础类型
local function get_basic_type(name)
  local index = basic_type[name]
  if index == nil  and enum_type[name] ~= nil then
    return basic_type.self_enum.type
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
  return get_muti_type(muti), get_basic_type(name)
 else
  return muti_type.basic, get_basic_type(type_name)
 end
end

-- 读取数值
function read_data(type_name, muti, self_enum)
  local t = basic_type[type_name]
  if t ~= nil then
    return t.reader(type_name, muti, self_enum)
  else
    return nil
  end
end



