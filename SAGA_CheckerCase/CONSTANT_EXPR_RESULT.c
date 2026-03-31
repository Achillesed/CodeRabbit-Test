/**
    Filename: CONSTANT_EXPR_RESULT.c
    Vuln: CONSTANT_EXPR_RESULT
    SourceLine: -1
    SinkLine: 14
    Comment: 常量表达式结果
*/

#include <stdio.h>
#include <stdlib.h>

void CONSTANT_EXPR_RESULT_BAD(int a)
{
    if (a == 0 && a == 1)   //缺陷点：此表达式恒为 false
    {
        /* do something */
    }
}

void CONSTANT_EXPR_RESULT_GOOD(int a)
{
    if (a == 0 || a == 1)   //修复点
    {
        /* do something */
    }
}