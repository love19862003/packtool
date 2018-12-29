gtable_links = {}

function add_table_link(name, linkstr)
  gtable_links[name] = gtable_links[name] or {}
  linkstr = string.gsub(linkstr, " ", "")
  local heads = string.split(linkstr, ",")
  local link = {name = table.concat(heads, "_"), heads = heads}
  table.insert(gtable_links[name], link)
end