--类型定义
require("functions")
require("reader")
require("writer")
require("enum")
--需要新增自定义类型的话，
--需要补充reader  writer checker  writer_proto_common writer_sql等等几个函数
--基础类型定义
g_basic_type = {
  ["none"] = { 
      type = 0,
      reader = reader_none,               -- 读取函数
      writer = write_none,                -- proto字段
      checker = check_none,               -- 数据检查时候方式
      key = "",                           -- protobuf 关键字
      cpp_type = nil,                     -- cpp 关键字
      writer_proto_common = write_none,   -- 自定义类型输出函数  
      writer_sql = {
        field = sql_none, 
        content = sql_content_none
        }                                 -- sql文件生成时候对应的结构函数和内容函数
      },
  ["int"] = { 
      type = 1, 
      reader = reader_number, 
      writer = write_proto_field,
      checker = check_number,
      key = "int32",
      cpp_type = "int",
      writer_proto_common = write_proto_message_basic,
      writer_sql = {field = sql_int, content = sql_content}
      },
  ["float"] = {
      type = 2, 
      reader = reader_number,
      writer = write_proto_field,
      checker = check_number,
      key = "float",
      cpp_type = "float",
      writer_proto_common = write_proto_message_basic,
      writer_sql = {field = sql_float, content = sql_content}
      },
  ["string"] = { 
      type = 3, 
      reader = reader_string, 
      writer = write_proto_field,
      checker = check_none,
      key = "string",
      cpp_type = "std::string",
      writer_proto_common = write_proto_message_basic,
      writer_sql = {field = sql_string, content = sql_content}
      },
  ["bool"] = { 
      type = 4, 
      reader = reader_bool,
      writer = write_proto_field,
      checker = check_number,
      key = "bool",
      cpp_type = "bool",
      writer_proto_common = write_proto_message_basic,
      writer_sql = {field = sql_bool, content = sql_content}
      },
  ["enum"] = { 
      type = 5, 
      reader = read_enum_value,
      writer = write_none,
      checker = check_none,
      key = "enum",
      cpp_type = nil,
      writer_proto_common = write_none,
      writer_sql = {field = sql_none, content = sql_content_none}
      },
  ["self_enum"] = {
      type = 6, 
      reader = reader_self_enum,
      writer = write_proto_field_enum,
      checker = check_number,
      key = "self_enum",
      cpp_type = nil,
      writer_proto_common = write_none,
      writer_sql = {field = sql_self_enum, content = sql_content}
      },
  ["coordinate"] = {
      type = 7,
      reader = reader_coordinate,
      writer = write_proto_field,
      checker = check_coordinate,
      key = "ProCoordinate",
      cpp_type = "ProCoordinate",
      writer_proto_common = write_proto_common_coordinate,
      writer_sql = {field = sql_json, content = sql_content_json}
  },
  
  ["int5"] = {
      type = 8,
      reader = reader_int5,
      writer = write_proto_field,
      checker = check_int5,
      key = "ProInt5",
      cpp_type = "ProInt5",
      writer_proto_common = write_proto_common_int5,
      writer_sql = {field = sql_json, content = sql_content_json}
  },

}
 

g_muti_type = {
  basic = 0,  --基础类型
  array = 1,  --数组形式
  group = 2,  --多维数组形式
}

--是否是要定制枚举类型
function isEnumType(type)
  return type == g_basic_type["enum"].type
end

--是否是无效类型
function isNoneType(type)
  return type == g_basic_type["none"].type
end

--是否是自定义枚举类型
function isSelfEnumType(type)
  return type == g_basic_type["self_enum"].type
end

-- 是否是单个基础类型
function isSingleType(type)
  return type == g_muti_type.basic
end

--是否是数组
function isArrayType(type)
  return type == g_muti_type.array
end

--是否是二维数据
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

-- 读取类型 int  array<int> group<int> bool 
function read_input_type(str)
 local type_name = str
 local r1, r2, muti, name = string.find(type_name, "^(%a+)<(.+)>$")
 if r1 ~= nil then 
  return get_muti_type(muti), get_basic_type(name), name
 else
  return g_muti_type.basic, get_basic_type(type_name), type_name
 end
end




