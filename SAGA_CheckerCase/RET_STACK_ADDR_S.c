/**
    Filename: RET_STACK_ADDR_S.c
    Vuln: RET_STACK_ADDR_S
    SourceLine: -1
    SinkLine: 17
    Comment: 返回栈变量的地址
*/

#include <stdio.h>
#include <stdlib.h>
#define STR_MAX 16

char* RET_STACK_ADDR_S_BAD() 
{
    char name[STR_MAX];
    /* do something */
    return name;     //缺陷点：返回局部变量地址
}

char* RET_STACK_ADDR_S_GOOD() 
{
    char* name = malloc(sizeof(char)*STR_MAX);
    if(!name) return "bad";
    /* do something */
    return name;    // 修复点：返回堆上的地址
}