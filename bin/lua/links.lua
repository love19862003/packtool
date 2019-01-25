--表的多键索引相关
gtable_links = {}


--[[
link结构
struct{
  name = head1_head2_...
  heads = {head ...}
}
--]]


-- 增加索引
function add_table_link(name, linkstr)
  gtable_links[name] = gtable_links[name] or {}
  linkstr = string.gsub(linkstr, " ", "")
  local heads = string.split(linkstr, ",")
  local link = {name = table.concat(heads, "_"), heads = heads}
  table.insert(gtable_links[name], link)
end

--获取表的多键索引
function get_table_link(name)
  return gtable_links[name]
end

--检查表格多链接索引是否合法
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
        er("表"..name.."link中字段"..h.."不存在")
        return false
      else
        if not checkKeyType(head.muti_type, head.basic_type) then 
          -- head type not allow to be a link 
          er("表"..name.."联合索引中字段"..h.."类型不能做link")
          return false
        end
      end      
    end
  end
  return true
end

--获取有在多键索引中的自定义枚举所在表格列表 
function get_link_enum_tables()
  local res = {}
  
  for name, links in pairs(gtable_links) do 
      local t = g_tables[name]
      for _, link in pairs(links) do 
        for  _, h in pairs(link.heads) do 
          local head = t:getHead(h) 
          if isSelfEnumType(head.basic_type) then 
             local en = get_enum(head.type_basic_name)
             if en then 
              if en.table ~= "" then 
                res[en.table] = true
              else
                res[common_enum_name()] = true
              end
             end
          end
        end
      end
  end 
  
  return res
end