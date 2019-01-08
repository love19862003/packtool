#include "litlua.h"
#include "pbc-lua.h"

int main(){
  lua_State* L = luaL_newstate();
  LitSpace::openLuaLibs(L);
  LitSpace::openLuaLib(L, "protobuf.c", luaopen_protobuf_c);
  LitSpace::dofile(L, "./test.lua");
  lua_close(L);
}