g_oldData = nil


local function table_string(tab)
  local str = "{"
   
  for k, v in pairs(tab) do 
    if type(k) == "string" then 
      str = str .. " " .. k .. "="
    end
    
    if type(v) == "string"  then 
      str = str .. v
    else
      if type(v) == "table" then 
        str = str .. table_string(v)
      else
        str = str .. v
      end
    end
    
    str = str .. ","
  end  
   
  str = str .. "}"
  return str
end

local function value_print(value) then
  if type(value) == "table" then 
    return table_string(value)
  else
    if nil == value  then return "" end
    return .."" value
  end
end


local function compare_record(r, r1)
  local str = ""
  local record = {}
  local keySTR = function( kk )
    if type(kk) == "string" then 
      return  " "..kk..":"
    else
      return  " index:"..kk..":"
    end
  end
  
  
  for k, v  in pairs(r)  do 
  
    if r1[k] == nil then 
      str = str .. keySTR(k) ..  value_print(v)
    else
      
      if type(v) ~= type(r1[k]) then 
        str = str .. keySTR(k) .. "{" .. value_print(r1[k]) .. "->" .. value_print(v) .. "}"
      else
        
        if type(v) == "table" then 
          local str2 = compare_record(v, r1[k])
          if string.len(str2) > 0 then 
            str = str .. keySTR(k) .. "{"..str2 .. "}"
          end
        else
          if v ~= r1[k] then 
            str = str .. keySTR(k) .. "{" .. (r1[k] or  "") .. " ->" .. v .. "}"
          end
        
        end
        
      end
      
    end
    
    record[k] = true
  end
  
  
  if type(r1) == "table" then 
    for k, v in pairs(r1) do 
      if not record[k] then 
        str = "del:" .. value_print(v)
      end
    end
  end
  
  return str

end


local writeFile = nil
--写入文件
local function write(str)
  if writeFile == nil then 
    assert(false)
    return 
  end
  
  writeFile:write(add_space(indent_space))
  writeFile:write(str)
  writeFile:write("\n")
end



local function compare_table(t, ot, name)
  local tRecord = {}
  
  if ot == nil then 
    write("........ add new table:" .. name)
    for k, v in pairs(t) do 
      write(name .." add [" .. k.."] = " .. value_print(v))
    end
    write("......................." .. name)
  end
  
  
  local printEnd = false
  for k, v in pairs(t) do 
    if ot[k] ~= nil then 
      local str = compare_record(v, ot[k])
      if string.len(str) > 0 then 
        write(name .. " record[" .. k.. "] modify ".. str .. "")
        printEnd = true
      end
    else
      write(name .. " add record[" .. k .. "] = " .. value_print(v))
      printEnd = true
    end
    
    tRecord[k] = true
  end
  
  
  for k, v in pairs(ot) do 
    if not tRecord[k] then 
      write(name .. " remove record[" .. k .. "]=".. value_print(v))
      printEnd = true
    end
  end
  
  if printEnd then 
    write( ".................." .. name)
  end
  
end


function compare_read_old_data()
  g_oldData = readPackageData() or {}
  -- remove old files and datas 
  -- load last layout
  --
end

function compare_package()
  local data = readPackageData()
  
end