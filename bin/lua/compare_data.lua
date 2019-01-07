--数据新老版本的比较相关
g_oldData = nil  -- 上个版本的数据信息

--结构文件目录
local function layout_path()
  return  out_dir() .. "/info/" 
end

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

local function value_print(value) 
  if type(value) == "table" then 
    return table_string(value)
  else
    if nil == value  then return "" end
    return "".. value
  end
end

--比较2条记录
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
  if writeFile == nil or str == nil then 
    assert(false)
    return 
  end
  
  writeFile:write(add_space(indent_space))
  writeFile:write(str)
  writeFile:write("\n")
end


--比较2个表格
local function compare_table(t, ot, name)
  local tRecord = {}
  
  if ot == nil then 
    write("........ 添加新表:" .. name)
    for k, v in pairs(t) do 
      write(name .." 新表记录 [" .. k.."] = " .. value_print(v))
    end
    write("......................." .. name)
  end
  
  
  local printEnd = false
  for k, v in pairs(t) do 
    if ot[k] ~= nil then 
      local str = compare_record(v, ot[k])
      if string.len(str) > 0 then 
        write(name .. " 记录[" .. k.. "] 修改 ".. str .. "")
        printEnd = true
      end
    else
      write(name .. " 增加记录 [" .. k .. "] = " .. value_print(v))
      printEnd = true
    end
    
    tRecord[k] = true
  end
  
  
  for k, v in pairs(ot) do 
    if not tRecord[k] then 
      write(name .. " 删除记录 [" .. k .. "]=".. value_print(v))
      printEnd = true
    end
  end
  
  if printEnd then 
    write( ".................." .. name)
  end
  
end


--重新初始化表格数据
local function resort_table_data(data, layout)
  if not data or not layout then return nil end
  local index_name = layout.index_name;
 
  local res = {}
  for _, v in pairs(data) do 
    local k = v[index_name]
    if nil ~= k then 
      res[k] = v
    end
  end
  return res
end

--读取上个版本的表格数据
function compare_read_old_data()
  g_oldData = readPackageData() or {}
  for tab_name , layout  in pairs (g_layout_history) do 
    if type(layout) == "table" then 
      g_oldData[tab_name] = resort_table_data(g_oldData[tab_name], layout)
    end
  end
end

--比较上个版本和最新版本的数据
function compare_package()
  local data = readPackageData()
  for tab_name , layout  in pairs (g_layout_current) do 
    if type(layout) == "table" then 
      data[tab_name] = resort_table_data(data[tab_name], layout)
    end
  end
  
  writeFile = assert(io.open(layout_path().. "/last.log", "w+"))
  write("----------------------------------------------")
  write("配置表更新时间:" .. os.date())
  write("版本号从 :" .. (g_oldData.version or " none ") .. " 到:".. data.version)
  local tags = {}
  tags.version = true
  for k, v in pairs(data) do 
    if not tags[k]  then 
      compare_table(v, g_oldData[k], k)
      tags[k] = true
    end
  end
  
  for k , v in pairs(g_oldData) do 
    if not tags[k]  then 
      write("...........................")
      write("删除表格 : " .. k)
      tags[k] = true
    end
  end
  write("----------------------------------------------")
  writeFile:close()
  writeFile = nil
  
  local buffer1 = io.readfile(layout_path().. "/last.log")
  local buffer2 = io.readfile(layout_path().. "/history.log")
  writeFile = assert(io.open(layout_path().. "/history.log", "w+"))
  write(buffer1 or "")
  write(buffer2 or "")
  writeFile:close()
  writeFile = nil
end