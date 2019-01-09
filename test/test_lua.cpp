#include "litlua.h"
#include "pbc-lua.h"

void run_test(){
  lua_State* L = luaL_newstate();
  LitSpace::openLuaLibs(L);
  LitSpace::openLuaLib(L, "protobuf.c", luaopen_protobuf_c);
  LitSpace::dofile(L, "./test_lua.lua");
  lua_close(L);
}