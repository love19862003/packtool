--表的结构
require("functions")
g_tables = {}
Layout = class("Layout")
--缓存的结构数据
function Layout:init(name)
  self.table = name
  self.key_index = 1
  self.next_index = 1
  self.type_name = ""
  self.layouts = {}
end

Table = class("Table")
--初始化
function Table:init(layout, index)
  self.layout = layout
  self.heads = {}
  self.records = {}
  self.depends = {}
  self.links = {}
  self.table_index = index
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
  return self.table_index
end

