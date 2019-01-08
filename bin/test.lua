dofile("./lua/dump_object.lua")
local protobuf = dofile("./lua/protobuf.lua")
dofile("./export/lua_out/AllConfigs.lua")
local pbsPath = "./export/pbs/"
local dataPath = "./export/data/AllConfigs.bin"


local data = protobuf_lua_tables(protobuf, pbsPath, dataPath)
Dump.info(data.monster["9"])
Dump.info(data.monster["1"])
Dump.info(data.monster["2"])
Dump.info(data.monster["3"])
Dump.info(data.monster["4"])
Dump.info(data.monster["5"])
Dump.info(data.monster["6"])

assert(data.monster["9"])
assert(data.monster["1"])
assert(data.monster["2"])
assert(data.monster["3"])
assert(data.monster["4"])
assert(data.monster["5"])
assert(data.monster["6"])


Dump.info(data.role[1])
Dump.info(data.role[2])
Dump.info(data.role[3])
Dump.info(data.role[4])
Dump.info(data.role[5])
Dump.info(data.role[6])
Dump.info(data.role[7])

Dump.info(data.role[1].camp_array)

assert(data.role[1])
assert(data.role[2])
assert(data.role[3])
assert(data.role[4])
assert(data.role[5])
assert(data.role[6])
assert(data.role[7])