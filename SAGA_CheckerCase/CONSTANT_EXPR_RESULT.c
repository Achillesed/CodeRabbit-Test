/**
    Filename: CONSTANT_EXPR_RESULT.c
    Vuln: CONSTANT_EXPR_RESULT
    SourceLine: -1
    SinkLine: 14
    Comment: 常量表达式结果
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates a conditional that is always false because it tests mutually exclusive equalities.
 *
 * @param a Integer value evaluated by the condition.
 */
void CONSTANT_EXPR_RESULT_BAD(int a)
{
    if (a == 0 && a == 1)   //缺陷点：此表达式恒为 false
    {
        /* do something */
    }
}

/**
 * Execute the guarded action when the input is 0 or 1.
 *
 * @param a Integer value checked; the function's body executes if `a` equals 0 or 1.
 */
void CONSTANT_EXPR_RESULT_GOOD(int a)
{
    if (a == 0 || a == 1)   //修复点
    {
        /* do something */
    }
}