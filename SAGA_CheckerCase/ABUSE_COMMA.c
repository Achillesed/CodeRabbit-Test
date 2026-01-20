/**
    Filename: ABUSE_COMMA.c
    Vuln: ABUSE_COMMA
    SourceLine: -1
    SinkLine: 16
    Comment: 滥用了逗号运算符
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates a for-loop where the comma operator in the loop condition produces unintended behavior.
 *
 * The condition `a < 10, b < 10` evaluates only `b < 10` for loop continuation, so `a < 10` does not affect iteration.
 */
void ABUSE_COMMA_BAD()
{

    int a,b;
    for(a = 0, b = 0; a < 10, b < 10; a++, b++)   // 缺陷点:布尔表达式a < 10, b < 10中，a < 10没有意义
    {
        /* do something */
    }

}
/**
 * Iterate two integer counters in lockstep while both are less than 10 using a logical conjunction.
 *
 * Initializes `a` and `b` to 0 and increments both on each iteration; the loop continues only while
 * both `a < 10` and `b < 10`, avoiding misuse of the comma operator in the loop condition.
 */
void ABUSE_COMMA_GOOD()
{

    int a,b;
    for(a = 0, b = 0; a < 10 && b < 10; a++, b++)   // 修复点：使用逻辑运算符 && 修正布尔表达式
    {
        /* do something */
    }

}