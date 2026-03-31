/**
    Filename: PTR_PROH_PARMPTR_ASSGN_S.c
    Vuln: PTR_PROH_PARMPTR_ASSGN_S
    SourceLine: -1
    SinkLine: 16
    Comment: 禁止对参数指针进行赋值
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int PTR_PROH_PARMPTR_ASSGN_S_BAD(unsigned int *pa)
{
    static unsigned int i = 10;
    i = i + 1;
    pa = &i;    //缺陷点：违背规则对参数指针进行赋值
    return i;
}

unsigned int PTR_PROH_PARMPTR_ASSGN_S_GOOD(unsigned int *pa)
{
    static unsigned int i = 10;
    i = i + 1;
    unsigned int a = *pa;    //修复点：进行使用
    return i;
}