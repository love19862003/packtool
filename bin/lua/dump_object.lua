Dump = {}
function Dump.object_info(obj)
    local meta = getmetatable(obj)
    if meta ~= nil then
        Dump.metainfo(meta)
    else
        print("no object infomation !!")
    end
end

function Dump.metainfo(meta)
    if meta ~= nil then
        local name = meta["__name"]
        if name ~= nil then
            Dump.metainfo(meta["__parent"])
            print("<"..name..">")
            for key,value in pairs(meta) do 
                if not string.find(key, "__..") then 
                    if type(value) == "function" then
                        print("\t[f] "..name..":"..key.."()") 
                        elseif type(value) == "userdata" then
                        print("\t[v] "..name..":"..key)
                    end
                end
            end
        end
    end
end


function Dump.baseinfo(obj)
    local meta = getmetatable(obj)
    if meta ~= nil then
        Dump.me(meta)
    else
        print("no object infomation !!")
    end
end

function Dump.me(meta)
  Dump.info(meta)
  Dump.baseinfo(meta)
end
function Dump.info(obj, info)
  if nil ~= info then  print(info.."_________________")end
  print_table(obj, 0)
  if nil ~= info then  print(info.."_________________")end
end
function print_table(t, i)
  if nil == t then return end
  local indent =""
  for j = 0, i do 
    indent = indent.."   "
  end
  for k, v in pairs(t) do 
    if (type(v) == "table") then -- type(v) 当前类型时否table 如果是，则需要递归，
      if type(k) == "number" then 
        print(indent.."[")
      else
        print(indent..k..":[")
      end
      print_table(v, i + 1) -- 递归调用
      print(indent.."]")
    else -- 否则直接输出当前值
      if (type(v) == "userdata" or type(v) == "function") then 
        print(indent..k..":\""..type(v).."\"")
      else
        if type(v) == "boolean" then
          if v then 
            print(indent..k..":\"true\"")
          else
            print(indent..k..":\"false\"")
          end
        else
          print(indent..k..":\""..v.."\"")
        end
      end
    end
  end
end
function Dump.file(obj, info)
  local file = io.open(info,"w+")
  file_table(obj, 0, file)
  file:close(file)
end
function DumpFile( obj, filePath )
  local file = io.open(filePath,"w+")
  file_table(obj, 0, file)
  file:close(file)
end
function file_table(t, i, file)
  local indent =""
  for j = 0, i do 
    indent = indent.."   "
  end
  if(type(t) ~= "table") then 
     if(type(t) == "boolean") then
        if true == t  then file:write(indent..i..":\"true\"\n") else file:write(indent..i..":\"false\"\n") end
      else
        file:write(indent..i..":\""..t.."\"\n")
      end
    return 
  end
  
  for k, v in pairs(t) do 
    if (type(v) == "table") then -- type(v) 当前类型时否table 如果是，则需要递归，
      file:write(indent..k..":[\n")
      file_table(v, i + 1, file) -- 递归调用
      file:write(indent.."]\n")
    else -- 否则直接输出当前值
      if(type(v) == "boolean") then
        if true == v  then file:write(indent..k..":\"true\"\n") else file:write(indent..k..":\"false\"\n") end
      elseif type(v) == "function" or type(v) == "userdata" then
         file:write(indent..k..":\""..type(v).."\"\n")
      else
        file:write(indent..k..":\""..v.."\"\n")
      end
    end
  end
end


function Dump.data(obj, info)
  if nil ~= info then  print(info.."_________________")end
  Dumptable(obj, 0)
  if nil ~= info then  print(info.."_________________")end
end
function Dumptable(t, i)
  if nil == t then return end
  local indent =""
  for j = 0, i do 
    indent = indent.."   "
  end
  for k, v in pairs(t) do 
    if (type(v) == "table") then -- type(v) 当前类型时否table 如果是，则需要递归，
       if type(k) == "number" then 
         print(indent..""..k..":[")
       else
         print(indent..""..k..":[")
       end
     
      print_table(v, i + 1) -- 递归调用
      print(indent.."]")
    else -- 否则直接输出当前值
      if (type(v) == "userdata" or type(v) == "function") then 
        print(indent..k..":\""..type(v).."\"")
      else
        if type(v) == "boolean" then
          if v then 
            print(indent..k..":\"true\"")
          else
            print(indent..k..":\"false\"")
          end
        else
          print(indent..k..":\""..v.."\"")
        end
      end
    end
  end
end