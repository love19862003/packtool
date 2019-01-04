local writeFile = nil
local indent_space = 0
--cpp目录
local function proto_cpp_path()
  return out_dir() .. "\\cpps\\"
end

-- 获取cpp types
local function cpp_types(head)
  local basic_type = get_basic_type_by_id(head.basic_type)
  if isSelfEnumType(basic_type.type) then 
    local en = get_enum(head.type_basic_name)
    return en.table .. "::" .. en.name 
  end
  return basic_type.cpp_type
end

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

--表接口声明
local function write_cpp_tables_interface_def(tab)
    local tabName = tab:name()
    local typeName = tabName..tail_config_name()
    local indexType = cpp_types(tab:getIndexHead())
    write("// table "..tabName .. " interfaces")
    write(string.format("const %s& %s(const %s& index) const;", typeName, tabName, indexType))
    write(string.format("bool has_%s(const %s& index) const;", tabName, indexType))
    write(string.format("bool %s(const std::function<bool(const %s&)>& call) const;", tabName, typeName))
    
    local links = get_table_link(tabName)
    if links  then 
      write("// table "..tabName .. " links")
      for _, link in pairs(links) do 
         local args = {}
         for _, h in pairs(link.heads) do 
            local lh = tab:getHead(h)
            local cpptype = cpp_types(lh)
            table.insert(args, "const "..cpptype.."& "..lh.name)
         end
         write(string.format("const %s& %s_by_%s(%s) const;", typeName, tabName, link.name, table.concat(args, ", ")))
      end
    end
    
    write("")
end

--表成员声明
local function write_cpp_tables_members(tab)
  local tabName = tab:name()
  local typeName = tabName..tail_config_name()
  local indexType = cpp_types(tab:getIndexHead())
  write(string.format("std::map<%s, %s> m_%s;", indexType, typeName, tabName))
  local links = get_table_link(tabName)
  if links  then 
    write("// table "..tabName .. " links")
    for _, link in pairs(links) do 
       local args = {}
       for _, h in pairs(link.heads) do 
          local lh = tab:getHead(h)
          local cpptype = cpp_types(lh)
          table.insert(args, cpptype)
       end
       write(string.format("typedef std::tuple<%s> %s_type;", table.concat(args, ", "), link.name))
       write(string.format("std::map<%s_type, %s> m_%s_link_%s;",link.name, indexType, tabName, link.name))
    end
  end
end

--成员函数的实现
local function write_cpp_tables_interface(tab)
  local tabName = tab:name()
  local typeName = tabName..tail_config_name()
  local indexType = cpp_types(tab:getIndexHead())
  local mgrClsName = out_file_name().."::Impl::"
  write("// table "..tabName .. " interfaces")
  write(string.format("const %s& %s%s(const %s& index) const{", typeName, mgrClsName, tabName, indexType))
  indent()
  write("try{")
  indent()
  write(string.format("return m_%s.at(index);", tabName))
  outdent()
  write(string.format("}catch(...){ return %s::default_instance();}", typeName))
  outdent()
  write("}")
  
  -- has
  write(string.format("bool %shas_%s(const %s& index) const{", mgrClsName, tabName, indexType))
  indent()
  write("try{")
  indent()
  write(string.format("return m_%s.count(index) > 0;", tabName))
  outdent()
  write("}catch(...){ return false;}")
  outdent()
  write("}")
  
  
  -- for each
  write(string.format("bool %s%s(const std::function<bool(const %s&)>& call) const{", mgrClsName, tabName, typeName))
  indent()
  write(string.format("for(auto& pair : m_%s){", tabName))
  indent()
  write("if(call(pair.second)){return true;}")  
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
          local cpptype = cpp_types(lh)
          table.insert(args, "const "..cpptype.."& "..lh.name)
          table.insert(argsName, lh.name)
       end
       write(string.format("const %s& %s%s_by_%s(%s) const{", typeName,mgrClsName, tabName, link.name, table.concat(args, ", ")))
       indent()
       write(string.format("const %s_type %s_value = std::make_tuple(%s);", link.name, link.name ,table.concat(argsName, ", ")))
       write(string.format("const auto& it = m_%s_link_%s.find(%s_value);", tabName, link.name, link.name))
       write(string.format("if(it != m_%s_link_%s.end()){return  %s(it->second);}", tabName, link.name, tabName))
       write(string.format("else{ return %s::default_instance();}", typeName))
       outdent()
       write("}")
    end
  end
  write("")
end

--成员函数的实现
local function write_cpp_tables_interface_impl(tab)
  local tabName = tab:name()
  local typeName = tabName..tail_config_name()
  local indexType = cpp_types(tab:getIndexHead())
  local mgrClsName = out_file_name().."::"
  write("// table "..tabName .. " interfaces")
  write(string.format("const %s& %s%s(const %s& index) const{", typeName, mgrClsName, tabName, indexType))
  indent()
  write(string.format("return m_impl->%s(index);",  mgrClsName, tabName)) 
  outdent()
  write("}")
  
  -- has接口
  write(string.format("bool %shas_%s(const %s& index) const{", mgrClsName, tabName, indexType))
  indent()
  write(string.format("return m_impl->has_%s(index);", tabName)) 
  outdent()
  write("}")
  
  
  -- for each 接口
  write(string.format("bool %s%s(const std::function<bool(const %s&)>& call) const{", mgrClsName, tabName, typeName))
  indent()
  write(string.format("return m_impl->%s(call);", tabName))   
  outdent()
  write("}")
  
  --links  
  local links = get_table_link(tabName)
  if links  then 
    write("// table "..tabName .. " links")
    for _, link in pairs(links) do 
       local args = {}
       local argsName = {}
       for _, h in pairs(link.heads) do 
          local lh = tab:getHead(h)
          local cpptype = cpp_types(lh)
          table.insert(args, "const "..cpptype.."& "..lh.name)
          table.insert(argsName, lh.name)
       end
       write(string.format("const %s& %s%s_by_%s(%s) const{", typeName,mgrClsName, tabName, link.name, table.concat(args, ", ")))
       indent()
       write(string.format("return m_impl->%s_by_%s(%s);", tabName, link.name ,table.concat(argsName, ", ")))
       outdent()
       write("}")
    end
  end
  write("")
end

-- c++管理类.h
function write_cpp_header()
  local protoCppPath = proto_cpp_path()
  local mgrclsName = out_file_name()
  -- out_file_name().h 
  writeFile = assert(io.open(protoCppPath .. mgrclsName .. ".h", "w+"))
  write("/************************************************")
  write("* file ".. mgrclsName .. ".h")
  write("* date "..tostring(os.date()).."")
  write("*")
  write("* author wufan")
  write("* Contact: love19862003@163.com")
  write("*")
  write("* brief") 
  write("*")
  write("* TODO: long description")
  write("*")
  write("* note")
  write("*************************************************/")
  write("#pragma once")
  write("#include <memory>")
  write("#include <functional>")
 
 
  local includeEnumTable = get_link_enum_tables()
  for k,_ in pairs(includeEnumTable) do 
     write("#include \"" ..k..tail_config_name()..".pb.h\"" )
  end
  
  write("namespace "..name_space().. " {")
  indent()
  for k,_ in pairs(g_tables) do 
      local clsName = k..tail_config_name()
      write(" class ".. clsName .. ";")
  end
  outdent()
  write("}")
  
  
  -- modify class

  write("namespace "..name_space().. " {\n")
  indent()
  write("class "..mgrclsName .. " {")
  write("public:")
  indent()
  
  write(mgrclsName .. "();")
  write("~"..mgrclsName .. "()")
  write("bool init(const std::string& files);")
  write("bool init(const char* bytes, size_t len);")
  write("bool reload();")
  write("const std::string& fileName() const;")
  write("const std::string& version() const;")
  
  for k, tab in pairs(g_tables) do 
    write_cpp_tables_interface_def(tab)
  end
  outdent()
  write("private:")
  indent()
  write(string.format("%s (const %s&) = delete;", mgrclsName, mgrclsName))
  write(string.format("%s& operator = (const %s&) = delete;", mgrclsName, mgrclsName))
  write("class Impl;")
  write("std::unique_ptr<Impl> m_impl;")
  outdent()
  write("}; //"..mgrclsName)
  outdent()
  write("}//"..name_space().."\n")
  writeFile:close()
end

-- c++管理类.cpp 
function write_cpp_content()
  local mgrclsName = out_file_name()  
  local protoCppPath = proto_cpp_path()
  writeFile = assert(io.open(protoCppPath .. mgrclsName .. ".cpp", "w+"))
  write("/************************************************")
  write("* file ".. mgrclsName .. ".cpp")
  write("* date "..tostring(os.date()).."")
  write("*")
  write("* author wufan")
  write("* Contact: love19862003@163.com")
  write("*")
  write("* brief") 
  write("*")
  write("* TODO: long description")
  write("*")
  write("* note")
  write("*************************************************/")
  write("#include <memory>")
  write("#include <map>")
  write("#include <fstream>")
  write("#include <tuple>")
  write(string.format("#include \"%s.h\"", mgrclsName))
  write(string.format("#include \"%s%s.pb.h\"", all_config_name(), tail_config_name()))
  write("namespace "..name_space().."{")
  indent()
  
  write("class "..mgrclsName.. " ::Impl{")
  write("public:")
  indent()
  
  write("bool init(const std::string& file){")
  indent()
  write("m_fileName = file;")
  write("clear();")
  write("std::ifstream ifile(file.data(), std::ios::binary | std::ios::in);")
  write(string.format("auto ptr = make_shared<%s%s>();", all_config_name(), tail_config_name()))
  write("bool res = ptr->ParseFromIstream(ifile);")
  write("ifile.close();")
  write("if(!res){return res;}")
  write("fill(ptr);")
  write("return true;")
  outdent()  
  write("}")
  
  
  write("bool init(const char* bytes, size_t len){")
  indent()
  write("m_fileName.clear();")
  write("clear();")
  write(string.format("auto ptr = make_shared<%s%s>();", all_config_name(), tail_config_name()))
  write("bool res = ptr->ParseFromArray(bytes, len);")
  write("if(!res){return res;}")
  write("fill(ptr);")
  write("return true;")
  outdent()
  write("}")
  
  write("bool reload(){return init(m_fileName);}")
  
  
  write("void clear(){")
  indent()
  for k, tab in pairs(g_tables) do 
    local tabName = tab:name()
    local typeName = tabName..tail_config_name()
    local indexType = cpp_types(tab:getIndexHead())
    write(string.format("m_%s.clear();", tabName))
    
    local links = get_table_link(tabName)
    if links  then 
      write("// table "..tabName .. " links")
      for _, link in pairs(links) do 
         local args = {}
         for _, h in pairs(link.heads) do 
            local lh = tab:getHead(h)
            local cpptype = cpp_types(lh)
            table.insert(args, cpptype)
         end
         write(string.format("m_%s_link_%s.clear();", tabName, link.name))
      end
    end
  end  
  outdent()
  write("}")
  
  write(string.format("void fill(const std::shared_ptr< %s%s >& ptr){", all_config_name(), tail_config_name()))
  indent()
  write("m_version = ptr->version();")
  
  for k, tab in pairs(g_tables) do 
    local tabName = tab:name()
    local typeName = tabName..tail_config_name()
    local indexHead = tab:getIndexHead()
    local indexType = cpp_types(indexHead)
    write(string.format("for(auto& v : ptr->%s()){", tabName))
    indent()
    write(string.format("m_%s[v.%s()] = v;", tabName, indexHead.name))
    
    local links = get_table_link(tabName)
    if links  then 
      write("// table "..tabName .. " links")
      for _, link in pairs(links) do 
         local args = {}
         for _, h in pairs(link.heads) do 
            local lh = tab:getHead(h)
            local cpptype = cpp_types(lh)
            table.insert(args, "v."..lh.name.."()")
         end
         
         write(string.format("%s_type %s_value = std::make_tuple(%s);", link.name, link.name,  table.concat(args, ", ")))
         write(string.format("m_%s_link_%s[%s_value] = v.%s();", tabName, link.name,link.name, indexHead.name))
      end
    end
    outdent()
    write("}") 
  end 
  outdent()
  write("}")
  
  
  write("const std::string& fileName() const{return m_fileName;}")
  write("const std::string& version() const{return m_version;}")
  for k, tab in pairs(g_tables) do 
    write_cpp_tables_interface_def(tab)
  end
  
  outdent()
  write("private:")
  indent()
  write("std::string m_version;")
  write("std::string m_fileName;")
  
  for k, tab in pairs(g_tables) do 
    write_cpp_tables_members(tab)
  end
  outdent()
  write("};//".. mgrclsName .."::Impl")
  
  -- Impl tables interfaces
  for k, tab in pairs(g_tables) do 
    write_cpp_tables_interface(tab)
  end
  
  write(string.format("%s::%s():m_impl(new Impl()){}", mgrclsName, mgrclsName))
  write("")
  write(string.format("%s::~%s(){ m_impl.reset();}", mgrclsName, mgrclsName))
  write("//init by file")
  
  write(string.format("bool %s::init(const std::string& file){return m_impl->init(file);}", mgrclsName))
  write("//init by bytes")
  write(string.format("bool %s::init(const char* bytes, size_t len){return m_impl->init(bytes, len);}", mgrclsName))
  write("//reload") 
  write(string.format("bool %s::reload(){return m_impl->reload();}", mgrclsName))
  write("//file")  
  write(string.format("const %s::std::string& fileName() const{return m_impl->fileName();}", mgrclsName))
  write("//version")
  write(string.format("const %s::std::string& version() const{return m_impl->version();}", mgrclsName))
  
  
  for k, tab in pairs(g_tables) do 
    write_cpp_tables_interface_impl(tab)
  end
 
  outdent()
  write("}//"..name_space().."\n")
  writeFile:close()
  writeFile = nil
end