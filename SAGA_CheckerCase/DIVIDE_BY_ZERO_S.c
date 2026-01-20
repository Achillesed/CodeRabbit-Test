/**
    Filename: DIVIDE_BY_ZERO_S.c
    Vuln: DIVIDE_BY_ZERO_S
    SourceLine: -1
    SinkLine: 24
    Comment: 除零错误
*/

#include <stdio.h>
#include <stdlib.h>
int getvalue();
/**
 * Demonstrates an unsafe division that may divide by zero.
 *
 * Calls getvalue() to obtain an integer and performs `10 / a` unconditionally,
 * printing the result. If `a` is zero, this results in a runtime divide-by-zero.
 */
void DIVIDE_BY_ZERO_S_BAD()
{
    int a = getvalue();
    if (a == 0)
    {
        /* do something */
    }
    else
    {
        /* do something */
    }
    printf("%d\n", 10 / a); //缺陷点：15行 'a == 0'说明 a 在此分支可能为 0
}

/**
 * Perform a safe division of 10 by a value obtained from getvalue.
 *
 * Calls getvalue() to obtain an integer `a` and prints the result of `10 / a`
 * only when `a` is not zero; no division is performed when `a` equals zero.
 */
void DIVIDE_BY_ZERO_S_GOOD()
{
    int a = getvalue();
    if (a == 0)
    {
        /* do something */
    }
    else
    {
        /* do something */
        printf("%d\n", 10 / a); //修复点：在此分支 a != 0
    }
}