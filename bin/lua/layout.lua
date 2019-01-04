require("functions")
g_layout_history = {}
g_layout_current = {}

--结构文件目录
local function layout_path()
  return  out_dir() .. "/info/table_layout.lua" 
end

--下一个表的ID
local function next_table_index()
  local index = g_layout_current.next_table_index or 2
  if index == 2 then 
    g_layout_current.next_table_index = index
  end
  
  g_layout_current.next_table_index = g_layout_current.next_table_index + 1
  return index
end

--读取历史结构文件
function load_layout_history()
  local layoutFile = io.open(layout_path())
  if not layoutFile then return end
  layoutFile:close()
  g_layout_history = dofile(layout_path())
  g_layout_current = table.clone(g_layout_history)
  g_layout_history = ReadOnlyTable(g_layout_history)
end

--获取一个表的结构
function get_table_layout(name)
  if not g_layout_current[name] then 
    local layout = {}
    layout.table = name
    layout.key_index = 1
    layout.next_index = 1
    layout.index_name = ""
    layout.layouts = {}
    layout.table_index = next_table_index()
    g_layout_current[name] = layout
  end
  return g_layout_current[name]
end

--保存结构文件
function save_layout()
  for k, tab in pairs(g_tables) do 
    g_layout_current[k] = tab:getLayout()
  end
  
  table.save("g_layout_history", g_layout_current, layout_path())
end


