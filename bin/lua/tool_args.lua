g_args = {}

function set_tool_args(args)
  g_args = args
end

function all_config_name()
  return g_args.all_config_name
end

function common_define_name()
  return g_args.common_define_name
end

function common_group_name()
  return g_args.common_group_name
end

function common_enum_name()
  return g_args.common_enum_name
end

function tail_config_name()
  return g_args.tail_config_name
end

function out_dir() 
  return g_args.out_dir
end

function version()
  return g_args.version
end

function next_table_id()
  return g_args.next_table_id
end

function version_table_id()
  return g_args.version_table_id
end

function name_space()
   return g_args.name_space
end

function proto_type()
  return g_args.proto_type 
end