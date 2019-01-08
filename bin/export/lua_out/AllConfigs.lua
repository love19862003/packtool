local function ReadOnlyTable(table)
 return setmetatable({}, {
   __index = table,
   __len = function(t) return #table end,
   __ipairs = function(t) return ipairs(table) end,
   __pairs = function(t) return pairs(table) end,
   __newindex = function(t, key, value) error("Attempt to modify read-only table") end,
});
end
function protobuf_lua_tables(protobuf, pbs_path, data_file)
 for line in io.lines(pbs_path .. "registerList.txt") do
  protobuf.register_file(pbs_path .. line.. ".pb")
 end
 local message = "Pro.GameConfig"
 local file = assert(io.open(data_file, "rb"))
 local buffer = file:read("*all")
 file:close()
 local data = assert(protobuf.decode(message, buffer), "decode failed")
 local res = {}
 res.version = data.version
 res.role = {}
 for _, v in pairs(data.role) do
  res.role[v.id] = ReadOnlyTable(v)
 end
 res.role = ReadOnlyTable(res.role)
 res.monster = {}
 res.monster_by_job_level_sub = {}
 for _, v in pairs(data.monster) do
  res.monster[v.id] = ReadOnlyTable(v)
  res.monster_by_job_level_sub[v.job] = res.monster_by_job_level_sub[v.job] or {}
  res.monster_by_job_level_sub[v.job][v.level] = res.monster_by_job_level_sub[v.job][v.level] or {}
  res.monster_by_job_level_sub[v.job][v.level][v.sub] = ReadOnlyTable(res.monster[v.id])
 end
 res.monster = ReadOnlyTable(res.monster)
 return res
end
