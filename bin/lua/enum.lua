--自定义枚举
g_enum_type = {

}

function get_enum(name)
  --Dump.data(g_enum_type[name])
  return g_enum_type[name]
end


-- 自定义枚举类型
-- 读取枚举名字
function read_enum_name(str)
  --print("read_enum_name "..str)
  local str1, str2 = string.split2(str, "%.")
  g_enum_type[str] = g_enum_type[str] or {}
  g_enum_type[str].full_name = str
  if str2 == nil then 
    g_enum_type[str].table = ""
    g_enum_type[str].name = str
    return "", str
  else
    g_enum_type[str].table = str1
    g_enum_type[str].name = str2
    return str1, str2
  end
end

-- 读取枚举值
function read_enum_value(name, str, comment)
  local str1, str2 = string.split2(str, "=")
  g_enum_type[name] = g_enum_type[name] or {}
  if str2 == nil then 
    return "", 0, ""
  else
    local value =  tonumber(str2)
    g_enum_type[name].values = g_enum_type[name].values or {}
    table.insert(g_enum_type[name].values, {str1, value, comment})
    return str1, value
  end
end

--检测枚举值
function check_enum_value(name, value)
  if not g_enum_type[name] then
   return false
  end
  
  --Dump.data(g_enum_type[name].values)
  for _, v in pairs(g_enum_type[name].values) do 
    if type(value) == "number" and value == v[2] then
      return true
    end
    
    if type(value) == "string" and value == v[1] then
      return true
    end
  end
  
  return false
end

