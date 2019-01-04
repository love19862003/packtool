--表的结构
require("functions")
g_tables = {}
Table = class("Table")
local table_index_head_id = 1
--初始化
function Table:init(layout)
  self.layout = layout
  self.heads = {}
  self.records = {}
  self.depends = {}
  self.links = {}
  self.table_index = layout.table_index
  self.depend_common = false
end

--增加表头
function Table:addHead(head)
  if self.heads[head.index] ~= nil then 
    return false
  end
  self.heads[head.index] = head
  return true
end

--增加表记录
function Table:addRecord(record)
  if self.records[record.index] ~= nil then 
    return false
  end
  self.records[record.index] = record
  return true
end

--获取表记录
function Table:getRecord(index)
  return self.records[index]
end

--增加多键索引
function Table:addLink(link)
  self.links[link.name] = link
end

--获取表头
function Table:getHead(index)
  if type(index) == "number" then 
    return self.heads[index]
  end
  
  if type(index) == "string" then 
    for k, v in pairs(self.heads) do 
      if v.name == index then 
        return v
      end
    end
  end
  print("get head from table:" ..self.table .. " by args:" .. index)
  return nil
end
--获取索引表头
function Table:getIndexHead()
  return self.heads[table_index_head_id]
end

--根据列获取表头
function Table:getColHead(col)
  for k, v in pairs(self.heads) do 
      if v.column == col then 
        return v
      end
  end
  return nil
end

--获取结构
function Table:getLayout() 
  return self.layout
end

--获取依赖的表格信息
function Table:getDepends()
  return self.depends
end

--增加依赖表格
function Table:addDepends(t)
  for _, v in pairs(self.depends) do 
    if v == t then 
      return 
    end
  end
  table.insert(self.depends, t)
end

--设置依赖common
function Table:setDependCommon()
  self.depend_common = true
end

--获取表名字
function Table:name()
  return self.layout.table
end

--获取表的索引ID
function Table:getTableIndex()
  return self.layout.table_index
end

--获取一个新的表头的结构信息
function Table:getHeadLayout(headname)
  if not self.layout.layouts[headname]  then
      self.layout.layouts[headname] = { head_index = self.layout.next_index, name = headname }
      self.layout.next_index = self.layout.next_index + 1
      if self.layout.layouts[headname].head_index == table_index_head_id then 
        self.layout.index_name = headname
      end
  end
  
  local isIndexHead = self.layout.layouts[headname].head_index == table_index_head_id
  return self.layout.layouts[headname].head_index , isIndexHead
end
