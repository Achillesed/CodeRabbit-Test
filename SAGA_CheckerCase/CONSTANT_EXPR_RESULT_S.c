/**
    Filename: CONSTANT_EXPR_RESULT_S.c
    Vuln: CONSTANT_EXPR_RESULT_S
    SourceLine: -1
    SinkLine: 14
    Comment: 操作数不影响结果
*/

#include <stdio.h>
#include <stdlib.h>

void CONSTANT_EXPR_RESULT_S_BAD(int a)
{
    if ((a & 0x10) == 1)    //缺陷点：无论 a 取何值，a & 0x10 的结果只能是 0 或 16（即 0x10），所以不可能与 1 相等，表达式恒为常量 0
    {
        /* do something */
    }
}

void CONSTANT_EXPR_RESULT_S_GOOD(int a)
{
    if ((a & 0x10) == 0)    //修复点：可能与 0 相等，取可能的值
    {
        /* do something */
    }
}