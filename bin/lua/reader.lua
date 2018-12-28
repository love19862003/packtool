local function replace_basic(str)
  str = string.gsub(str, " ", "")
  return str
end

local function replace_array(str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "%]", "")
  str = string.gsub(str, "%[", "")
  return str
end

local function replace_group(str)
  print("replace_group:"..str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "%],%[", "|")
  str = string.gsub(str, "%]", "")
  str = string.gsub(str, "%[", "")
  print("replace_group:"..str)
  return str
end

function reader_none(str, muti)
  return nil
end

function reader_number(str, muti)
  local tal = {}
  if muti == muti_type.basic then
    str = replace_basic(str)
    if str == "" then str = "0" end
    tal = {str}
  end
  
  if muti == muti_type.array then
    str = replace_array(str)
    tal = string.split(str, ",")
    if str == "" then tal = {} end
    --Dump.data(tal, "reader_int")
  end
  
  if muti == muti_type.group then 
   -- print("................."..str)
    str = replace_group(str)
   -- print("................."..str)
    tal = string.split3(str, "|" ,",")
    --Dump.data(tal, "reader_int")
    if str == "" then tal = {} end
  end
  
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v) do 
          if tonumber(v2) == nil then
            print(v2)
            return nil
          end
        end
      else
        if tonumber(v) == nil then
          print(v)
          return nil
        end
      end
  end
  
  return tal
  
end



function reader_string(str, muti)
  str = string.gsub(str, "\"", "\\\"")
  str = string.gsub(str, "\n", "\\\n")
  str = string.gsub(str, "\t", "\\\t")
  local tal = {}
  if muti == muti_type.basic then
    str = replace_basic(str)
    tal = {str}
  end
  
  if muti == muti_type.array then
    str = replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    str = replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
  return tal
end

function reader_bool(str, muti)
  local tal = {}
  if muti == muti_type.basic then
    str = replace_basic(str)
    if str == "" then str = "false" end
    tal = {str}
  end
  
  if muti == muti_type.array then
    str = replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    str = replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
   
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v) do 
          if tonumber(v2) ~= nil or v2 == "true" or v2 == "false" then
          else
            return nil
          end
        end
      else
        if tonumber(v2) ~= nil or v2 == "true" or v2 == "false" then
          return nil
        end
      end
  end
  
  return tal
  
end

function reader_self_enum(str, muti, name)
  if enum_type[name] == nil then 
    return nil
  end
  
  local tal = {}
  if muti == muti_type.basic then
    str = replace_basic(str)
    tal = {str}
  end
  
  if muti == muti_type.array then
    str = replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    str = replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
  
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v) do 
          if not check_enum_value(name,v2) then
            return nil
          end
        end
      else
        if not check_enum_value(name,v) then
          return nil
        end
      end
  end
  
  return tal
end

function reader_coordinate(str, muti)
  str = string.gsub(str, "\"", "\\\"")
  str = string.gsub(str, "\n", "\\\n")
  str = string.gsub(str, "\t", "\\\t")
  local tal = {}
  if muti == muti_type.basic then
    str = replace_basic(str)
    tal = {str}
  end
end

