require("functions")
g_tables = {}
Layout = class("Layout")
function Layout:init(name)
  self.table = name
  self.key_index = 1
  self.next_index = 1
  self.type_name = ""
  self.layouts = {}
end

Table = class("Table")
function Table:init(layout, index)
  self.layout = layout
  self.heads = {}
  self.records = {}
  self.depends = {}
  self.links = {}
  self.table_index = index
  self.depend_common = false
end

function Table:addHead(head)
  if self.heads[head.index] ~= nil then 
    return false
  end
  self.heads[head.index] = head
  return true
end

function Table:addRecord(record)
  if self.records[record.index] ~= nil then 
    return false
  end
  self.records[record.index] = record
  return true
end

function Table:getRecord(index)
  return self.records[index]
end

function Table:addLink(link)
  self.links[link.name] = link
end

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

function Table:getColHead(col)
  for k, v in pairs(self.heads) do 
      if v.column == col then 
        return v
      end
  end
  return nil
end

function Table:getLayout() 
  return self.layout
end

function Table:getDepends()
  return self.depends
end

function Table:addDepends(t)
  for _, v in pairs(self.depends) do 
    if v == t then 
      return 
    end
  end
  table.insert(self.depends, t)
end

function Table:setDependCommon()
  self.depend_common = true
end

function Table:name()
  return self.layout.table
end

function Table:getTableIndex()
  return self.table_index
end

