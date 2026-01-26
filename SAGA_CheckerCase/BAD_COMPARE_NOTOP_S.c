/**
    Filename: BAD_COMPARE_NOTOP_S.c
    Vuln: BAD_COMPARE_NOTOP_S
    SourceLine: -1
    SinkLine: 14
    Comment: 非正常值与逻辑否定运算符做了比较
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates a flawed comparison where the logical NOT is applied to `x` before the equality test.
 *
 * @param x Left operand; `!x` is evaluated and then compared to `y`, which can lead to unintended results due to operator precedence.
 * @param y Right operand compared against the result of `!x`.
 */
void BAD_COMPARE_NOTOP_S_BAD(int x, int y) 
{
    if (!x == y)    //缺陷点：运算优先级先进行 !x 在做比较 可能是用户意料之外的
    {
        /* do something */
    }
}

/**
 * Execute the inner block when the two integer values are not equal.
 *
 * Evaluates whether x and y differ and runs the enclosed statements only if x != y.
 *
 * @param x First integer to compare.
 * @param y Second integer to compare.
 */
void BAD_COMPARE_NOTOP_S_GOOD(int x, int y) 
{
    if (!(x == y))    //修复点：使用括号明确优先级
    {
        /* do something */
    }
}