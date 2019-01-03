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
  --print("replace_group:"..str)
  str = string.gsub(str, " ", "")
  str = string.gsub(str, "%],%[", "|")
  str = string.gsub(str, "%]", "")
  str = string.gsub(str, "%[", "")
  --print("replace_group:"..str)
  return str
end

local function read_array(value)
   value = replace_array(value)
   if value == "" then 
    return  {}
   end
   local res = string.split(value, ",")
   return res
end 

local function read_group(value)
  value = replace_group(value)
  if value == "" then 
    return  { }
  end
  local r = string.split3(value, "|" ,",")
  local res = {}
  for _, a in pairs(r) do
      local arr = {}
      for k, v in pairs(a) do
        table.insert(arr, v)
      end      
      table.insert(res, {array = arr})
  end
  --Dump.info(res, value)
  return res
end

function reader_none(str, muti)
  return nil
end

local function reader_basic(str, head)
  --print(str)
  local muti = head.muti_type
  if muti == g_muti_type.basic then
    str = replace_basic(str)
    return str
  end
  if muti == g_muti_type.array then
    return read_array(str)
  end
  
  if muti == g_muti_type.group then 
    return read_group(str)
  end
end

function reader_number(str, head)
  local tal = reader_basic(str, head)
  if type(tal) ~= "table" then 
    tal = tonumber(tal) or 0
  else
    for _, v in pairs(tal) do
        if type(v) == "table" then
          for _, v2 in pairs(v.array) do 
            v2 = tonumber(v2) or 0
          end
        else
          v = tonumber(v) or 0
        end
    end
  end
  return tal
  
end



function reader_string(str, head)
  str = string.gsub(str, "\"", "\\\"")
  str = string.gsub(str, "\n", "\\\n")
  str = string.gsub(str, "\t", "\\\t")
  return reader_basic(str, head)
 
end

local function toboolean(tal)
   if tonumber(tal) then tal = tonumber(tal) > 0 end 
   if tal == "true" then tal = true end
   if tal == "false" then tal = false end
   if type(tal) ~= "boolean" then tal = false end
   return tal
end

function reader_bool(str, head)
  local tal = reader_basic(str, head)
  if type(tal) ~= "table" then 
    return toboolean(tal)
  else
    for _, v in pairs(tal) do
        if type(v) == "table" then
          for _, v2 in pairs(v.array) do 
            v2 = toboolean(v2)
          end
        else
          v = toboolean(v)
        end
    end
  end
  return tal
  
end

function reader_self_enum(str, head)
  if g_enum_type[head.type_basic_name] == nil then 
    return nil
  end
 
  local tal = reader_basic(str, head)
  --Dump.info(tal, str)
  if type(tal) ~= "table" then 
    if not check_enum_value(head.type_basic_name,tal) then
      print(tal)
      assert(false)
      return nil
    end
  else
     for _, v in pairs(tal) do
      if type(v) == "table" then
        for _, v2 in pairs(v.array) do 
          if not check_enum_value(head.type_basic_name,v2) then
            print(v2)
            assert(false, v2)
            return nil
          end
        end
      else
        if not check_enum_value(head.type_basic_name,v) then
          print(v)
          assert(false, v)
          return nil
        end
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
  if muti == g_muti_type.basic then
    str = replace_basic(str)
    tal = {str}
  end
end

