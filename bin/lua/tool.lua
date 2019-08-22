--API
package.path = package.path..";./lua/?.lua"
package.cpath  = package.cpath ..";./lua/?.dll"
require("dump_object")
require("functions")
require("layout")
require("check_data")
require("cpp_write")
require("sql_write")
require("lua_write")
require("csharp_write")
require("proto_write")
require("compare_data")
require("type")
require("links")
require("tables")
require("tool_args")



local read_table_record = {} -- 当前读取的记录

-- 创建新的表格
function new_table(name)
  local layout = get_table_layout(name)
  local t = Table.new()
  t:init(layout)
  g_tables[t:name()] = t
  dg("发现表格:"..name)
end


-- 增加表格头
function table_head(table_name, column, headname, typename, comment)
  local mt, basic, basic_name = read_input_type(typename)
  if isNoneType(basic) then 
    return true
  end
  
  local t = g_tables[table_name]
  if not t then 
    return false
  end
  
  local index, isIndexHead = t:getHeadLayout(headname)
  
  local head = {
                  basic_type = basic,
                  muti_type = mt,
                  column = column,
                  comment = comment,
                  table = table_name,
                  type_name = typename,
                  type_basic_name = basic_name,
                  name = headname,
                  index = index
                }
   
  if isIndexHead and not checkKeyType(mt, basic) then 
    -- error with index
    er(table_name .. " 表索引列没找到或者表的索引列类型不匹配，请检查列:"..headname.."类型")
    return false;
  end
  
  if isSelfEnumType(head.basic_type) then 
     local en = get_enum(head.type_basic_name)
     if en.table ~= "" then 
       if en.table ~=  head.table then t:addDepends(en.table) end
     else
      t:addDepends(common_enum_name())
     end
  else
      if isGroupType(head.muti_type) or isSelfCommonType(head.basic_type) then
        t:setDependCommon()
      end
  end
  dg("表:"..table_name.. " 增加字段:".. head.name .. " index:"..head.index.. " 基础类型:"..basic_name.." 组合类型:"..(table.find_key(g_muti_type, mt) or "nil"))
  return t:addHead(head)
end

-- 重置数据记录
function reset_read_table_record()
  read_table_record = {index = "", fields = {}, vaild = false} 
end

-- 增加数据读取字段
function add_read_fields(name, column, value)
  local t = g_tables[name]
  if not t then return false end
  local head = t:getColHead(column)
  if not head then return true end
  
  
  local g = get_basic_type_by_id(head.basic_type)
  local field = g.reader(value, head) 
 
  local indexHead = t:getIndexHead()
  if head.index == indexHead.index then 
    read_table_record.index = field
    if value == "" then
      read_table_record.vaild = false
      return false 
    else
      read_table_record.vaild = true
    end
  end
  
  --Dump.info(field, value)
  read_table_record.fields[head.index] = field
  return true
end

-- 检测数据是否读完
function read_record_end()
  return read_table_record.index == "" or read_table_record.index == nil or read_table_record.vaild == false
end

--增加数据到表格
function add_record(name)
  local t = g_tables[name]
  if not t then return false end
  if read_table_record.vaild == true  then
    t:addRecord(read_table_record)
    reset_read_table_record()
  end
  return true
end

-- dump
function dump_tables()
  --Dump.info(g_enum_type)
  --for k, v in pairs(g_tables) do 
     --Dump.info(v.heads, k.." heads")
     --Dump.info(v.records, k.." records")
     --Dump.info(v.depends, k.." depends")
     --Dump.info(v.links, k.." links")
  --end
end

function save_configs()
  --保存proto文件，打包数据以及生成c++代码
  dg("导出protobuf...")
  write_proto()
  dg("导出csharp管理文件...")
  write_csharp()
  --保存历史结构文件
  dg("保存表的结构信息...")
  save_layout()
  --比较新老版本的数据差异，并写入log
  dg("对比表格的数据变化...")
  compare_package()
  --保存sql
  dg("导出SQL文件...")
  sql_writer()
  --输出pbc测试接口
  dg("导出pbc加载文件...")
  write_lua_out()
  
end

function er(info)
  error_info(info)
end

function dg(info)
  debug_info(info)
end

