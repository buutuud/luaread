#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int main(){
    lua_State *L = luaL_newstate();
    int result=2;
    luaL_dofile(L,"m.lua");
    lua_getglobal(L,"add");
    lua_pushinteger(L,1);
    lua_pushinteger(L,2);
    lua_pcall(L,2,1,0);
    result = lua_tointeger(L,-1);
    printf("%d\n",result);
    lua_close(L);
    return 0;
}
