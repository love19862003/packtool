local function replace_basic(str)
  str = string.gsub(str, " ", "")
end

local function replace_array(str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "]", "")
  str = string.gsub(str, "[", "")
end

local function replace_group(str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "],[", "|")
  str = string.gsub(str, "]", "")
  str = string.gsub(str, "[", "")
end

function reader_none(str, muti)
  return nil
end

function reader_int(str, muti)
  local tal = {}
  if muti == muti_type.basic then
    replace_basic(str)
    if str == "" then str = "0" end
    tal = {str}
  end
  
  if muti == muti_type.array then
    replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
  
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v1) do 
          if tonumber(v2) == nil then
            return nil
          end
        end
      else
        if tonumber(v) == nil then
          return nil
        end
      end
  end
  
  return tal
  
end

function reader_float(str, muti)
  local tal = {}
  if muti == muti_type.basic then
    replace_basic(str)
    if str == "" then str = "0" end
    tal = {str}
  end
  
  if muti == muti_type.array then
    replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
  
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v1) do 
          if tonumber(v2) == nil then
            return nil
          end
        end
      else
        if tonumber(v) == nil then
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
    replace_basic(str)
    tal = {str}
  end
  
  if muti == muti_type.array then
    replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
  return tal
end

function reader_bool(str, muti)
  local tal = {}
  if muti == muti_type.basic then
    replace_basic(str)
    if str == "" then str = "false" end
    tal = {str}
  end
  
  if muti == muti_type.array then
    replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
   
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v1) do 
          if tonumber(v2) == nil or v2 ~= "true" or v2 ~= "false" then
            return nil
          end
        end
      else
        if tonumber(v) == nil or v ~= "true" or v ~= "false" then
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
    replace_basic(str)
    tal = {str}
  end
  
  if muti == muti_type.array then
    replace_array(str)
    tal = string.split(str, ",")
  end
  
  if muti == muti_type.group then 
    replace_group(str)
    tal = string.split3(str, "|" ,",")
  end
  
  
  for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v1) do 
          if enum_type[name].values[v2] == nil then
            return nil
          end
        end
      else
        if enum_type[name].values[v] == nil then
          return nil
        end
      end
  end
  
  return tal
end

