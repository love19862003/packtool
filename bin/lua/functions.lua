function class(classname, super)
    local superType = type(super)
    local cls

    if superType ~= "function" and superType ~= "table" then
        superType = nil
        super = nil
    end

    if superType == "function" or (super and super.__ctype == 1) then
        -- inherited from native C++ Object
        cls = {}

        if superType == "table" then
            -- copy fields from super
            for k,v in pairs(super) do cls[k] = v end
            cls.__create = super.__create
            cls.super    = super
        else
            cls.__create = super
            cls.ctor = function() end
        end

        cls.__cname = classname
        cls.__ctype = 1

        function cls.new(...)
            local instance = cls.__create(...)
            -- copy fields from class to native object
            for k,v in pairs(cls) do instance[k] = v end
            instance.class = cls
            instance:ctor(...)
            return instance
        end

    else
        -- inherited from Lua Object
        if super then
            cls = {}
            setmetatable(cls, {__index = super})
            cls.super = super
        else
            cls = {ctor = function() end}
        end

        cls.__cname = classname
        cls.__ctype = 2 -- lua
        cls.__index = cls

        function cls.new(...)
            local instance = setmetatable({}, cls)
            instance.class = cls
            instance:ctor(...)
            return instance
        end
    end

    return cls
end

function add_space(count)
  if count >=1 then 
    return " " .. add_space(count - 1)
  else 
    return ""
  end
end

function io.exists(path)
    local file = io.open(path, "r")
    if file then
        io.close(file)
        return true
    end
    return false
end

function io.readfile(path)
    local file = io.open(path, "r")
    if file then
        local content = file:read("*a")
        file:close()
        return content
    end
    return nil
end


function io.writefile(path, content, mode)
    mode = mode or "w+b"
    local file = io.open(path, mode)
    if file then
        if file:write(content) == nil then 
          io.close(file)
          return false 
        end
        io.close(file)
        return true
    else
        return false
    end
end

function io.pathinfo(path)
    local pos = string.len(path)
    local extpos = pos + 1
    while pos > 0 do
        local b = string.byte(path, pos)
        if b == 46 then -- 46 = char "."
            extpos = pos
        elseif b == 47 then -- 47 = char "/"
            break
        end
        pos = pos - 1
    end

    local dirname = string.sub(path, 1, pos)
    local filename = string.sub(path, pos + 1)
    extpos = extpos - pos
    local basename = string.sub(filename, 1, extpos - 1)
    local extname = string.sub(filename, extpos)
    return {
        dirname = dirname,
        filename = filename,
        basename = basename,
        extname = extname
    }
end

function io.filesize(path)
    local size = false
    local file = io.open(path, "r")
    if file then
        local current = file:seek()
        size = file:seek("end")
        file:seek("set", current)
        io.close(file)
    end
    return size
end

function table.nums(t)
    local count = 0
    for k, v in pairs(t) do
        count = count + 1
    end
    return count
end

function table.is_array(t)
  if type(t) ~= "table" then return false end
  local n = #t
  for k, v in pairs(t) do
    if type(k) ~= "number"  then return false end
    if k > n then return false end 
  end
  return true
end

function table.keys(t)
    local keys = {}
    for k, v in pairs(t) do
        keys[#keys + 1] = k
    end
    return keys
end

function table.values(t)
    local values = {}
    for k, v in pairs(t) do
        values[#values + 1] = v
    end
    return values
end

function table.merge(dest, src)
    for k, v in pairs(src) do
        dest[k] = v
    end
end

function table.clone(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end
        local new_table = {}
        lookup_table[object] = new_table
        for index, value in pairs(object) do
          new_table[_copy(index)] = _copy(value)
        end
        return setmetatable(new_table, getmetatable(object))
    end
    return _copy(object)
end


function text_value(value)
  if type(value) ==  "boolean" then
    if value then 
      return "true"
    else 
      return "false"
    end
  end
      
  if type(value) ==  "string" then  
    return "\""..value.."\""
  else 
    return value
  end
end

function text_object(obj)
  if type(obj) ==  "table" then 
    return text_table(obj)
  else
    return text_value(obj)
  end
  
  
end

function text_table(tab)
  if type(tab) ~=  "table" then 
    return ""
  end
  local indent = " "
  local out = "{"
  if table.is_array(tab) then
    for key, value  in pairs(tab)  do
     if type(value) ==  "table" then 
        out = out .. text_table(value)
      else  
        out = out..text_value(value)
      end
      out = out ..","
    end
  else
    for key, value  in pairs(tab)  do
      if tonumber(key) ~= nil  then 
        out = out..indent.."[\""..key.."\"] = "
      else
        out = out..indent..key.." = "
      end
      
     if type(value) ==  "table" then 
        out = out .. text_table(value)
      else  
        out = out..text_value(value)
      end
      out = out ..","
    end
  end
  out = out.."}"
  return out
  
end

local function file_table(tab, cc, file)
  if type(tab) ~= "table" then return end
  local indent = add_space(cc)
  
  if table.is_array(tab) then 
    for key, value  in pairs(tab)  do
     if type(value) ==  "table" then 
        file:write("{")
        file_table(value, 1 , file)
        file:write("}")
      else  
        file:write(text_value(value))
      end
      file:write(" ,")
      if cc <= 0 then 
        file:write("\n")
      end
    end
  else
    for key, value  in pairs(tab)  do
      if tonumber(key) ~= nil  then 
        file:write(indent.."[\""..key.."\"] = ")
      else
        file:write(indent..key.." = ")
      end
      
      if type(value) ==  "table" then 
        file:write("{")
        file_table(value, 1 , file)
        file:write("}")
      else  
        file:write(text_value(value))
      end
      file:write(" ,")
      if cc <= 0 then 
        file:write("\n")
      end
    end
  end
end

function table.save(name, tab, info)
 local file = io.open(info,"w+")
 file:write("local ".. name .. " = {\n") 
 file_table(tab, 0, file)
 file:write("}\n")
 file:write("return "..name)
 file:close() 
end



--[[--

insert list.

**Usage:**

    local dest = {1, 2, 3}
    local src  = {4, 5, 6}
    table.insertList(dest, src)
    -- dest = {1, 2, 3, 4, 5, 6}
    dest = {1, 2, 3}
    table.insertList(dest, src, 5)
    -- dest = {1, 2, 3, nil, 4, 5, 6}


@param table dest
@param table src
@param table beginPos insert position for dest
]]
function table.insertList(dest, src, beginPos)
    beginPos = tonumber_(beginPos)
    if beginPos == nil then
        beginPos = #dest + 1
    end
    
    local len = #src
    for i = 0, len - 1 do
        dest[i + beginPos] = src[i + 1]
    end
end

--[[
search target index at list.

@param table list
@param * target
@param int from idx, default 1
@param bool useNaxN, the len use table.maxn(true) or #(false) default:false
@param return index of target at list, if not return -1
]]
function table.indexOf(list, target, from, useMaxN)
    local len = (useMaxN and #list) or table.maxn(list)
    if from == nil then
        from = 1
    end
    for i = from, len do
        if list[i] == target then
            return i
        end
    end
    return -1
end

function table.indexOfKey(list, key, value, from, useMaxN)
    local len = (useMaxN and #list) or table.maxn(list)
    if from == nil then
        from = 1
    end
    local item = nil
    for i = from, len do
        item = list[i]
        if item ~= nil and item[key] == value then
            return i
        end
    end
    return -1
end

function table.removeItem(list, item, removeAll)
    local rmCount = 0
    for i = 1, #list do
        if list[i - rmCount] == item then
            table.remove(list, i - rmCount)
            if removeAll then
                rmCount = rmCount + 1
            else 
                break
            end
        end
    end
end

function string.htmlspecialchars(input)
    for k, v in pairs(string._htmlspecialchars_set) do
        input = string.gsub(input, k, v)
    end
    return input
end
string._htmlspecialchars_set = {}
string._htmlspecialchars_set["&"] = "&amp;"
string._htmlspecialchars_set["\""] = "&quot;"
string._htmlspecialchars_set["'"] = "&#039;"
string._htmlspecialchars_set["<"] = "&lt;"
string._htmlspecialchars_set[">"] = "&gt;"

function string.nl2br(input)
    return string.gsub(input, "\n", "<br />")
end

function string.text2html(input)
    input = string.gsub(input, "\t", "    ")
    input = string.htmlspecialchars(input)
    input = string.gsub(input, " ", "&nbsp;")
    input = string.nl2br(input)
    return input
end
function string.split2(str, delimiter)
  local s, e = string.find(str, delimiter)
  if nil ~= s then 
    local str1 = string.sub(str, 1, s-1)
    local str2 = string.sub(str, e+1, string.len(str))
    --print("split2[".. str .. "] to [".. str1.."]["..str2.."] \n")
    return str1, str2
  else
    return str, nil
  end
end
function string.split(str, delimiter)
    if (delimiter=='') then return false end
    local pos,arr = 0, {}
    -- for each divider found
    for st,sp in function() return string.find(str, delimiter, pos, true) end do
        table.insert(arr, string.sub(str, pos, st - 1))
        pos = sp + 1
    end
    table.insert(arr, string.sub(str, pos))
    return arr
end

function string.split3(str, delimiter1, delimiter2)
    if (delimiter1=='' or delimiter2 == '') then return false end
    local t = string.split(str, delimiter1)
    local t2 = {}
    for _, v in pairs(t) do 
      table.insert(t2, string.split(v, delimiter2))
    end
    return t2
end


function string.ltrim(str)
    return string.gsub(str, "^[ \t\n\r]+", "")
end

function string.rtrim(str)
    return string.gsub(str, "[ \t\n\r]+$", "")
end

function string.trim(str)
    str = string.gsub(str, "^[ \t\n\r]+", "")
    return string.gsub(str, "[ \t\n\r]+$", "")
end

function string.ucfirst(str)
    return string.upper(string.sub(str, 1, 1)) .. string.sub(str, 2)
end

--[[--
@ignore
]]
local function urlencodeChar(c)
    return "%" .. string.format("%02X", string.byte(c))
end

function string.urlencode(str)
    -- convert line endings
    str = string.gsub(tostring(str), "\n", "\r\n")
    -- escape all characters but alphanumeric, '.' and '-'
    str = string.gsub(str, "([^%w%.%- ])", urlencodeChar)
    -- convert spaces to "+" symbols
    return string.gsub(str, " ", "+")
end

function string.utf8len(str)
    local len  = #str
    local left = len
    local cnt  = 0
    local arr  = {0, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc}
    while left ~= 0 do
        local tmp = string.byte(str, -left)
        local i   = #arr
        while arr[i] do
            if tmp >= arr[i] then
                left = left - i
                break
            end
            i = i - 1
        end
        cnt = cnt + 1
    end
    return cnt
end



