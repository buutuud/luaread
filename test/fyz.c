#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int fyz_sort(lua_State *L){
    int n = lua_gettop(L);
    int m = n;
    int i=0,j=0;
    lua_createtable(L,n,0);
    while (n>0){
        int max = luaL_checknumber(L,1);
        j = 1;
        for(i=2;i<=n;i++){
            int tmp = luaL_checknumber(L,i);
            if(tmp > max){
                max = tmp;
                j = i; 
            }
        }
        //lua_pushnumber(L,max);
        lua_pushnumber(L,max);
        lua_rawseti(L,-2,n);
        lua_remove(L,j);
        n--;
    }
    return 1;
}

static const luaL_Reg fyzlib[] = {
    {"sort",  fyz_sort},
    {NULL, NULL}
};

LUAMOD_API int luaopen_fyz(lua_State *L){
    luaL_newlib(L,fyzlib);
    return 1;
}
