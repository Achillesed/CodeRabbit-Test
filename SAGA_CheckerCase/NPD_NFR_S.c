/**
    Filename: NPD_NFR_S.c
    Vuln: NPD_NFR_S
    SourceLine: -1
    SinkLine: 19
    Comment: 函数NULL返回值解引用
*/

#include <stdio.h>
#include <stdlib.h>

static int *return_Null_func()
{
    return NULL;
}
void NPD_NFR_S_BAD()
{
        int *a = return_Null_func();
        *a = 1;     //缺陷点：函数可能返回null，在此处进行解引用
}

void NPD_NFR_S_GOOD()
{
        int *a = return_Null_func();
        if(!a) return;
        *a = 1;     //修复点：解引用前进行了判空检查
}
