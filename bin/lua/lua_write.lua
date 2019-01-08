local writeFile  = nil
local indent_space = 0
--增加空格
local function indent()
  indent_space =  indent_space + 1
end

--减少空格
local function outdent()
  indent_space = indent_space - 1
  assert(indent_space >= 0)
end 


local function luaPath()
  return out_dir() .. "/lua_out/"
end
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

function write_lua_out()
  writeFile = assert(io.open(luaPath() .. out_file_name()..".lua", "w+"))
  
  write("local function ReadOnlyTable(table)")
  write(" return setmetatable({}, {")
  write("   __index = table,")
  write("   __len = function(t) return #table end,")
  write("   __ipairs = function(t) return ipairs(table) end,")
  write("   __pairs = function(t) return pairs(table) end,")
  write("   __newindex = function(t, key, value) error(\"Attempt to modify read-only table\") end,")
  write("});")
  write("end")

  
  write("function protobuf_lua_tables(protobuf, pbs_path, data_file)")
  indent()
  write("for line in io.lines(pbs_path .. \"registerList.txt\") do")
  indent()
  write("protobuf.register_file(pbs_path .. line.. \".pb\")")
  outdent()
  write("end")
  write("local message = \"" .. name_space() .. "." .. all_config_name() .. tail_config_name() .. "\"")
  write("local file = assert(io.open(data_file, \"rb\"))")
  write("local buffer = file:read(\"*all\")")
  write("file:close()")
  write("local data = assert(protobuf.decode(message, buffer), \"decode failed\")")
  write("local res = {}")
  write("local res.version = data.version")
  for tname, tab in pairs(g_tables) do 
    local resname = "res."..tname
    write(resname .. " = {}")
    local links = get_table_link(tname)
    if links then
      for _, link in pairs(links) do 
        write("res." ..  tname .. "_by_"..link.name .. " = {}")
      end
    end
    
    
    write("for _, v in pairs(data."..tname..") do")
    indent()
    local h = tab:getIndexHead()
    write(resname.."[v."..h.name.."] = ReadOnlyTable(v)" )
    
     if links then 
      for _, link in pairs(links) do 
        local link_res_name = tname .. "_by_"..link.name
        local link_tmp_table = "res."..link_res_name
        for nc, n in pairs(link.heads) do 
          link_tmp_table = link_tmp_table .. "[v."..n .. "]"
          if nc < #link.heads then
            write(link_tmp_table .. " = " .. link_tmp_table .. " or {}")
          else
            write(link_tmp_table .. " = ReadOnlyTable(" .. resname.."[v."..h.name.."])")
          end
        end
        
      end
      
      
    end
    outdent()
    write("end")
    write(resname .. " = ReadOnlyTable("..resname..")")
  end
  write("return res")
  outdent()
  write("end")
  
  writeFile:close()
end