local json = require("json")
local function sqlPath()
  return out_dir() .. "/sql/"
end

local writeFile  = nil

--写入文件
local function write(str)
  if writeFile == nil then 
    assert(false)
    return 
  end
  
  writeFile:write(str)
  writeFile:write("\n")
end

--sql none
function sql_none()
  return nil
end
--sql content none
function sql_content_none(head, record)
  return nil
end

-- 数值
function sql_content(head, record)
  if g_muti_type.basic == head.muti_type then
    if type(record) == "table" then 
      er(text_object(head))
    end
    
    if type(record) == "boolean" then 
      if record then return "'1'" else return "'0'" end
    end
    
    if nil == record then 
      print( head.name  .. " " .. head.basic_type)
    end
    
    return "'" .. record .. "'"
  end
  
  return sql_content_json(head, record)
 
end

--结构定义
function sql_int(head)
  if g_muti_type.basic == head.muti_type then
    return "`"..head.name.."` int(11) NOT NULL DEFAULT '0'"
  end
  
  return sql_json(head)
end

--结构定义
function sql_float(head)
  if g_muti_type.basic == head.muti_type then
    return "`"..head.name.."` float(11,4) NOT NULL DEFAULT '0.0'"
  end
  return sql_json(head)
end
--结构定义
function sql_bool(head)
  if g_muti_type.basic == head.muti_type then
    return "`"..head.name.."` tinyint(4) NOT NULL DEFAULT '0'"
  end
  return sql_json(head)
end
--结构定义
function sql_string(head)
  if g_muti_type.basic == head.muti_type then
    return "`"..head.name.."` varchar(512) NOT NULL DEFAULT ''"
  end
  return sql_json(head)
end
--结构定义
function sql_self_enum(head)
  if g_muti_type.basic == head.muti_type then
    return "`"..head.name.."` varchar(255) NOT NULL DEFAULT ''"
  end  
  return sql_json(head)
end
--结构定义
function sql_json(head)
  return "`"..head.name.."` json"
end
--结构定义
function sql_content_json(head, r)
   return "'"..json.encode(r).."'"
end
--获取表的头的MySQL定义
local function sql_table_field(tab)
  local headFields = {}
  for _, h in pairs(tab.heads) do 
    local basic = get_basic_type_by_id(h.basic_type)
    local f = basic.writer_sql.field(h)
    if f then 
      table.insert(headFields, f)
    end
  end
  
  local head = tab:getIndexHead()
  table.insert(headFields,  "PRIMARY KEY(`" .. head.name .. "`)")
  return headFields
end

--MySQL索引
local function sql_table_links(tab)
  local name = tab:name()
  local linkFiels = {}
  local links = get_table_link(name)
  if links then 
    for _, link in pairs(links) do 
      local sql = "UNIQUE KEY `" .. link.name  
      sql = sql .."` (`"..table.concat(link.heads, "`,`") .. "`) USING HASH"
      table.insert(linkFiels, sql)
    end
  end
  return linkFiels
end
--内容
local function sql_table_field_record(tab, record)
  local res = {heads = {}, record = {}}
  for _, h in pairs(tab.heads) do 
    local basic = get_basic_type_by_id(h.basic_type)
    
    if nil  == record.fields[h.index] then 
      print(tab:name())
    end
    
    local f = basic.writer_sql.content(h, record.fields[h.index])
    if f then 
      table.insert(res.heads, h.name)
      table.insert(res.record, f)
    end
  end
  return res
end

--单个表格的结构和记录
local function sql_table_write(tname, tab)
  writeFile = assert(io.open( sqlPath() .. tname .. ".sql", "w+"))
  write("--------------------------------------------")
  write("---- table " .. tname .. " version:" .. version().. " ----")
  write("--------------------------------------------")
  
  write("SET FOREIGN_KEY_CHECKS=0;")
  write("DROP TABLE IF EXISTS `" .. tname .. "`;")
  write("CREATE TABLE `"..tname.."`(")
    
  local fields = sql_table_field(tab)
  local link = sql_table_links(tab)
  for _, v in pairs(link) do 
    table.insert(fields, v)
  end

  write(table.concat(fields, ",\n"))
  write(")ENGINE=InnoDB DEFAULT CHARSET=utf8;") 
  
  write("--------------------------------------")
  write("---- record for" .. tname .. "----------")
  write("--------------------------------------")
  
  for _, r in pairs(tab.records) do 
    local res = sql_table_field_record(tab, r)
    write("INSERT INTO `"..tname.."` (`".. table.concat(res.heads, "`,`").."`) VALUES("..table.concat(res.record, ",")..");")
  end
  
  writeFile:close()
end

--输出.sql文件
function sql_writer()
  for tname, tab in pairs(g_tables) do 
    sql_table_write(tname, tab)
  end
  
  writeFile = assert(io.open( sqlPath() .. all_config_name() .. ".sql", "w+"))
  
  for tname, tab in pairs(g_tables) do 
    local buffer = io.readfile(sqlPath().. tname .. ".sql")
    if buffer then
      write(buffer)
    end
  end
  writeFile:close()
end