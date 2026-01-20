/**
    Filename: NPD_COMMON_S.cpp
    Vuln: NPD_COMMON_S
    SourceLine: -1
    SinkLine: 15
    Comment: 空指针解引用
*/

#include <stdio.h>
void NPD_COMMON_S_BAD(int a,int *p)
{
    p = NULL;
    if(a > 2)
    {
        *p = 2;   //缺陷点：指针 p 为 NULL，此处产生了空指针解引用缺陷
    }
}

void NPD_COMMON_S_GOOD(int a,int *p)
{ 
    if(!p) return;
    if(a > 2)
    {
        *p = 2;   //修复点：确保指针 p 不为 NULL
    }
}