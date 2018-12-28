--自定义枚举
enum_type = {

}

function get_enum(name)
  --Dump.data(enum_type[name])
  return enum_type[name]
end


-- 自定义枚举类型
-- 读取枚举名字
function read_enum_name(str)
  local str1, str2 = string.split2(str, "%.")
  enum_type[str] = enum_type[str] or {}
  enum_type[str].full_name = str
  if str2 == nil then 
    enum_type[str].table = ""
    enum_type[str].name = str
    return "", str
  else
    enum_type[str].table = str1
    enum_type[str].name = str2
    return str1, str2
  end
end

-- 读取枚举值
function read_enum_value(name, str, comment)
  local str1, str2 = string.split2(str, "=")
  enum_type[name] = enum_type[name] or {}
  if str2 == nil then 
    return "", 0, ""
  else
    local value =  tonumber(str2)
    enum_type[name].values = enum_type[name].values or {}
    table.insert(enum_type[name].values, {str1, value, comment})
    return str1, value
  end
end

--检测枚举值
function check_enum_value(name, value)
  if not enum_type[name] then
   return false
  end
  
  --Dump.data(enum_type[name].values)
  for _, v in pairs(enum_type[name].values) do 
    if type(value) == "number" and value == v[2] then
      return true
    end
    
    if type(value) == "string" and value == v[1] then
      return true
    end
  end
  
  return false
end

--枚举的名字
function proto_enum_name(name, group)
  local en = enum_type[name]
  local key = en.name
  if en.table ~= "" then
    key = en.table..tail_config_name.."."..key
  end 
  if group then
     if en.table ~= "" then
       return en.table..tail_config_name.."."..common_group_name..en.name
      else
       return common_group_name..en.name
     end
  else
     if en.table ~= "" then
       return en.table..tail_config_name.."."..en.name
      else
       return en.name
     end
  end
end

--自定义枚举类型
function write_message_enum(name, space)
  local en = enum_type[name]
  local str = add_space(space)
  local res = str .. "enum "..en.name .. "{\n"..str
  for _, v in pairs(en.values) do
    res = res..str.." "..v[1] .. " = ".. v[2] ..";//"..v[3].."\n" 
  end
  res = res.."\n"..str.."};"
  res = res..str.."message " .. common_group_name..en.name.. "{\n"
  res = res..str.." repeated " .. en.name.. " array = 1; \n"..str.."}\n" 
  return res
end
