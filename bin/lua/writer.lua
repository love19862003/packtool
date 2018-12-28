function write_none()

end
--空格
function add_space(count)
  if count >=1 then 
    return " " .. space(count - 1)
  else 
    return ""
  end
end

--基础类型的多维数组定义
function write_message_basic(basic, space)
  local basic_info = get_basic_type_by_id(basic)
  if basic_info == nil then 
    return nil
  end
  
  local str = add_space(space) 
  local res = str.."message " .. common_group_name..basic_info.key
  res =  res .."{\n" ..str.." repeated " .. basic_info.key.. " array = 1; \n"..str.."}\n"  
  return res
end

--普通字段
function write_field(muti, basic, optional)
  local key = basic_type[basic].key
  if muti == muti_type.basic then
    str = optional .. key.." "
  end
  
  if muti == muti_type.array then
     str = "repeated ".. key.." "
  end
  
  if muti == muti_type.group then 
      str = "repeated "..common_group_name.. key.." "
  end
  
  return str
end

--枚举字段
function write_field_enum(muti, enumName, optional)
  local str = ""
  if muti == muti_type.basic then
    str = optional .. proto_enum_name(enumName).." "
  end
  
  if muti == muti_type.array then
     str = "repeated ".. proto_enum_name(enumName).." "
  end
  
  if muti == muti_type.group then 
    str = "repeated "..proto_enum_name(enumName, true) .." "
  end
  
  return str
end



function write_common(array_tail, group_tail)
  local t = {}
  
end