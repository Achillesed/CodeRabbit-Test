/**
    Filename: MISSING_RETURN_S.c
    Vuln: MISSING_RETURN_S
    SourceLine: -1
    SinkLine: 18
    Comment: 缺少 return 语句
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Return a mapped integer for specific input values.
 *
 * @param x Input value to evaluate.
 * @returns 4 if `x` equals 5, 2 if `x` equals 3; behavior is undefined for other values (function may not return).
 */
int MISSING_RETURN_S_BAD(int x) 
{
    if (x == 5)
    {
        return 4;
    }
    else if (x == 3)
    {
        return 2;
    }
}       /**
 * Map specific input values to predefined outputs.
 *
 * @param x Input integer to evaluate.
 * @returns `4` if `x` equals 5, `2` if `x` equals 3, `0` otherwise.
 */

int MISSING_RETURN_S_GOOD(int x) 
{
    if (x == 5)
    {
        return 4;
    }
    else if (x == 3)
    {
        return 2;
    }
    return 0;
}       //修复点：此函数无分支缺少 return