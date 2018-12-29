package.path = package.path..";./lua/?.lua"
require("dump_object")
require("type")
require("links")
require("tables")
require("tool_args")
require("proto_write")

local read_table_record = {}
local key_index_id = 1
local global_table_index = 2

function new_table(name)
  local layout = Layout.new()
  layout:init(name)
  local t = Table.new()
  t:init(layout, global_table_index)
  global_table_index = global_table_index + 1
  g_tables[t:name()] = t
end

function table_head(table, column, headname, typename, comment)
  local mt, basic, basic_name = read_type(typename)
  if isNoneType(basic) then 
    return true
  end
  
  local t = g_tables[table]
  if not t then 
    return false
  end
  
  local layout = t:getLayout()
  if not layout then 
    return false
  end
  local index = nil
  if layout.layouts[headname] then 
    index = layout.layouts[headname].head_index
  else
    index = layout.next_index
    layout.layouts[headname] = index
    layout.next_index = layout.next_index + 1
  end
  
  local head = {
                  basic_type = basic,
                  muti_type = mt,
                  column = column,
                  comment = comment,
                  table = table,
                  type_name = typename,
                  type_basic_name = basic_name,
                  name = headname,
                  index = index
                }
   
  if head.index == key_index_id and not checkKeyType(mt, basic) then 
    -- error with index
    return false;
  end
  
  if isSelfEnumType(head.basic_type) then 
     local en = get_enum(head.type_basic_name)
     if en.table ~= "" then 
       if en.table ~=  head.table then t:addDepends(en.table) end
     else
      t:addDepends(common_enum_name())
     end
  else
      if isGroupType(head.muti_type) then
        t:setDependCommon()
      end
  end
  
  return t:addHead(head)
end

function check_table_link(name)
  local links = gtable_links[name]
  local t = g_tables[name]
  if not t then return true end
  if nil == links then return true end
  
  for _, link in pairs(links) do 
    for _, h in pairs (link.heads) do 
      local head = t:getHead(h)
      if not head then 
        -- not found head h
        return false
      else
        if not checkKeyType(head.muti_type, head.basic_type) then 
          -- head type not allow to be a link 
          return false
        end
      end      
    end
  end
  return true
end


function reset_read_table_record()
  read_table_record = {index = "", fields = {}} 
end

function add_read_fields(name, column, value)
  local t = g_tables[name]
  if not t then return false end
  local head = t:getColHead(column)
  if not head then return true end
  
  local field = read_data(value, head)
  if head.index == key_index_id then 
    read_table_record.index = field
    if value == "" then return false end
    --Dump.info(field, value)
  end
  
  --Dump.info(field, value)
  read_table_record.fields[head.index] = field
  return true
end

function read_record_end()
  return read_table_record.index == "" or read_table_record.index == nil
end

function add_record(name)
  local t = g_tables[name]
  if not t then return false end
  if read_table_record.index ~= "" then
    t:addRecord(read_table_record)
    reset_read_table_record()
  end
  return true
end

function dump_tables()
  --Dump.info(g_enum_type)
  for k, v in pairs(g_tables) do 
     --Dump.info(v.heads, k.." heads")
      --Dump.info(v.records, k.." records")
     --Dump.info(v.depends, k.." depends")
     --Dump.info(v.links, k.." links")
  end
end

