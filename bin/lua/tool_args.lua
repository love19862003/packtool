g_args = {}

--上一次的数据


function execute_tool()
  return "protoc"
end
--全局参数
function set_tool_args(args)
  g_args = args
  
  load_layout_history()
  compare_read_old_data()
end

--输出类名
function all_config_name()
  return g_args.all_config_name
end

--common类名
function common_define_name()
  return g_args.common_define_name
end

--group的前缀
function common_group_name()
  return g_args.common_group_name
end

--全局枚举类名
function common_enum_name()
  return g_args.common_enum_name
end

--类后缀
function tail_config_name()
  return g_args.tail_config_name
end

--输出目录
function out_dir() 
  return g_args.out_dir
end

--版本信息
function version()
  return g_args.version
end

--包名
function name_space()
   return g_args.name_space
end

--输出的proto的类型
function proto_type()
  return g_args.proto_type 
end

--输出管理类的名
function out_file_name()
  return g_args.out_file_name
end

