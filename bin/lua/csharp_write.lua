--生成csharp管理类
local writeFile = nil
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

--csharp目录
local function proto_csharp_path()
  return out_dir() .. "\\csharp\\"
end
--csharp 访问接口
local function csharp_head_fun_name(name)
  --return string.upper(string.sub(name, 1, 1))..string.sub(name, 2)
  local res = string.split(name, "_")
  local r = ""
  for _, str in pairs(res) do 
    r = r .. string.upper(string.sub(str, 1, 1))..string.sub(str, 2)
  end
  return r
end

--类型转换
local function csharp_types(head)
  local basic_type = get_basic_type_by_id(head.basic_type)
  if isSelfEnumType(basic_type.type) then 
    local en = get_enum(head.type_basic_name)
    if en.table ~= nil and en.table ~= "" then
      return name_space().."."..en.table .. tail_config_name() .. ".Types." .. en.name 
    else
      return name_space().."."..en.name
    end
  end
  
  
  local res =  basic_type.key
  if res == "int32" then return "int" end
  return res
end

--多索引类型定义
local function csharp_link_name(tname, link)
  return tname .. "_link_" .. link.name .. "_type"
end
--多索引字典定义
local function csharp_link_name_dir(tname, link)
  return "m_"..csharp_link_name(tname, link) .. "_dir"
end

--初始化成员
local function write_csharp_init_member(tab)
  local tabName = tab:name()
  local typeName = tabName..tail_config_name()
  local indexType = csharp_types(tab:getIndexHead())
  write(string.format("m_%s = new Dictionary<%s, %s>();",tabName, indexType, typeName))
  write(string.format("m_optional_%s = new %s();", tabName, typeName))
  local links = get_table_link(tabName)
  if links  then 
     for _, link in pairs(links) do 
      write(string.format("%s= new Dictionary<%s, %s>();", csharp_link_name_dir(tabName, link), csharp_link_name(tabName, link), typeName))
     end
  end
end
--表需要的成员定义
local function write_csharp_tables_member(tab)
  local tabName = tab:name()
  local typeName = tabName..tail_config_name()
  local indexType = csharp_types(tab:getIndexHead())
  
  write(string.format("private Dictionary<%s, %s> m_%s;", indexType, typeName, tabName))
  write(string.format("private %s m_optional_%s;", typeName, tabName))
  local links = get_table_link(tabName)
  if links  then 
    write("// table "..tabName .. " links")
    for _, link in pairs(links) do 
       local args = {}
       local argsName = {}
       for _, h in pairs(link.heads) do 
          local lh = tab:getHead(h)
          local csharptype = csharp_types(lh)
          table.insert(args, csharptype.." "..lh.name)
          table.insert(argsName, lh.name)
       end
       local structName = csharp_link_name(tabName,link)
       write("struct " .. structName)
       write("{")
       indent()
       
       --构造函数
       write("public " .. structName .."(" .. table.concat(args, ", ") .. "){") 
       indent()
       for _, n in pairs(argsName) do 
        write(string.format("%s_ = %s;", n, n))
       end
       outdent()
       write("}")
       
       --比较类
       write("public class EqualityComparer : IEqualityComparer<" .. structName .. ">{")
       indent()
       -- Equals
       write(string.format("public bool Equals(%s l, %s r){", structName, structName))
       indent()
       for _, n in pairs(argsName) do 
        write(string.format("if(l.%s_ != r.%s_){return false;}", n, n))
       end
       write("return true;")
       outdent()
       write("}")
       
       -- hash
       write(string.format("public int GetHashCode(%s obj){", structName))
       indent()
       write("string str = null;")
       for _, n in pairs(argsName) do 
        write(string.format("str +=obj.%s_.ToString();", n))
       end
       write("return str.GetHashCode();")
       outdent()
       write("}")
       
       outdent()
       write("}")
       
       
       for _, n in pairs(args) do 
        write("public "..n.."_;")
       end
       outdent()
       write("}")
       
       write(string.format("private Dictionary<%s, %s> %s;", structName, typeName, csharp_link_name_dir(tabName, link)))
    end
  end
    
end

--访问表成员函数的实现
local function write_csharp_tables_interface(tab)
  local tabName = tab:name()
  local typeName = tabName..tail_config_name()
  local indexType = csharp_types(tab:getIndexHead())

  local optional_error = string.format("m_optional_%s", tabName)
   
  
  write("// table "..tabName .. " interfaces")
  write(string.format("public %s %s(%s index){", typeName, tabName, indexType))
  indent()
  write("try{")
  indent()
  write(string.format("return m_%s[index];", tabName))
  outdent()
  write(string.format("}catch(KeyNotFoundException){ return  %s;}", optional_error))
  outdent()
  write("}")
  
  -- has
  write(string.format("public bool has_%s(%s index){", tabName, indexType))
  indent()
  write(string.format("return m_%s.ContainsKey(index);", tabName))
  outdent()
  write("}")
  
  
  -- for each
  write(string.format("public bool %s( %sDeleGate call){", tabName, tabName))
  indent()
  write(string.format("foreach(var pair in m_%s){", tabName))
  indent()
  write("if(call(pair.Value)){return true;}")  
  outdent()
  write("}")
  write("return false;")
  outdent()
  write("}")
   
  local links = get_table_link(tabName)
  if links  then 
    write("// table "..tabName .. " links")
    for _, link in pairs(links) do 
       local args = {}
       local argsName = {}
       for _, h in pairs(link.heads) do 
          local lh = tab:getHead(h)
          local csharptype = csharp_types(lh)
          table.insert(args, csharptype.." "..lh.name)
          table.insert(argsName, lh.name)
       end
       write(string.format("public %s %s_by_%s(%s){", typeName, tabName, link.name, table.concat(args, ", ")))
       indent()
       write("try{")
       indent()
       write(string.format("return %s[new %s(%s)];", csharp_link_name_dir(tabName, link), csharp_link_name(tabName, link), table.concat(argsName, ", ") ))
       outdent()
       write(string.format("}catch(KeyNotFoundException){ return %s;}", optional_error))
       outdent()
       write("}")
    end
  end
  write("")
end

-- csharp 管理类生成
function write_csharp()
  local path = proto_csharp_path() .. out_file_name() .. ".cs"
  local gameConfName =  all_config_name() .. tail_config_name()
  writeFile = assert(io.open(path, "w+"))
  
  write("// <auto-generated> ")
  write("//     Generated by the protocol buffer compiler.  DO NOT EDIT!")
  write("//     source:" ..  out_file_name() .. ".cs")
  write("// </auto-generated>")

  write("using System.IO;")
  write("using System.Collections.Generic;")
  for k,_ in pairs(g_tables) do 
      local clsName = k..tail_config_name()
      write("using ".. clsName .. " = global::"..name_space().."."..clsName .. ";")
  end
  write("using ".. gameConfName .." = global::"..name_space().."."..gameConfName .. ";")
  write("namespace ".. name_space() .. "{")
  indent()
  
  for k,_ in pairs(g_tables) do 
      local clsName = k..tail_config_name()
      write("public delegate bool ".. k .. "DeleGate("..clsName .. " c);")
  end
  
  write("class ".. out_file_name())
  write("{")
  indent()
  
  --构造函数
  write("public ".. out_file_name() .. "(){")
  indent()
  write("m_version = \"" .. version() .. "\";" )
  for _,t in pairs(g_tables) do 
    write_csharp_init_member(t)
  end
  outdent()
  write("}")
  
  -- 初始化函数
  write("public bool init(string file){")
  indent()
  write("FileStream fs = new FileStream(file, FileMode.Open);" )
  write("if (null == fs) return false;")
  write(gameConfName.." g = " .. gameConfName .. ".Parser.ParseFrom(fs);")
  write("return fill(g);")
  outdent()
  write("}")
  
  -- 初始化函数
  write("public bool init(byte[] buffers){")
  indent()
  write("if (null == buffers) return false;")
  write(gameConfName.." g = " .. gameConfName .. ".Parser.ParseFrom(buffers);")
  write("return fill(g);")
  outdent()
  write("}")
  
  -- version
  write("public string version(){ return m_version;}")
  write("private string m_version;")
  
  -- fill
  write(string.format("public bool fill(%s g){", gameConfName))
  indent()
  write("clear();")
  write("m_version = g.Version;")
  for k, t in pairs(g_tables) do 
    local typeName = k .. tail_config_name()
    write(string.format("for(int i = 0; i < g.%s.Count; ++i){", csharp_head_fun_name(k)))
    indent()
    write(string.format("%s r = g.%s[i];", typeName, csharp_head_fun_name(k)))
    local indexhead = t:getIndexHead()
    write(string.format("m_%s[r.%s] = r;", k, csharp_head_fun_name(indexhead.name)))
    
    local links = get_table_link(k)
    if links  then 
       for _, link in pairs(links) do 
        local argsName = {}
        for _, h in pairs(link.heads) do 
          local lh = t:getHead(h)
          table.insert(argsName, "r."..csharp_head_fun_name(lh.name))
        end
        write(string.format("%s[new %s(%s)]= r;", csharp_link_name_dir(k, link), csharp_link_name(k, link), table.concat(argsName, ", ")))
       end
    end
    
    outdent()
    write("}")
  end
  write("return true;")
  outdent()
  write("}")
  
  
  -- clear
  write("private void clear(){")
  indent()
  for k, t in pairs(g_tables) do 
    write(string.format("m_%s.Clear();", k))
    local links = get_table_link(k)
    if links  then 
     for _, link in pairs(links) do 
      write(string.format("%s.Clear();", csharp_link_name_dir(k, link)))
     end
    end
  end
  outdent()
  write("}")
  
  for k, t in pairs(g_tables) do 
    write_csharp_tables_member(t)
    write_csharp_tables_interface(t)
  end
  
  --class
  outdent()
  write("}")
  
  
  --namespace
  outdent()
  write("}")
  
  writeFile:close()
end

