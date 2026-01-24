/**
    Filename: UNINIT_VAR_S.c
    Vuln: UNINIT_VAR_S
    SourceLine: -1
    SinkLine: 19
    Comment: 使用未初始化变量
*/
#include <stdio.h>
#include <stdlib.h>
int getValue();

int UNINIT_VAR_S_BAD(int flag) 
{
    int ret;
    if (flag > 0) 
    {
        ret = flag;
    } 
    return ret;   //缺陷点：ret 变量未初始化
}

int UNINIT_VAR_S_GOOD(int flag) 
{
    int ret = getValue();
    if (flag > 0) 
    {
        ret = flag;
    } 
    return ret;   //修复点
}

