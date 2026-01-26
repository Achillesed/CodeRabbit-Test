/**
    Filename: FLOATING_POINT_EQUALITY_S.c
    Vuln: FLOATING_POINT_EQUALITY_S
    SourceLine: -1
    SinkLine: 14
    Comment: 错误比较浮点表达式
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * Demonstrates a faulty pattern that compares two float values using `==`.
 * This direct equality check is unreliable for floating-point values due to rounding and precision errors.
 * @param x First value to compare.
 * @param y Second value to compare.
 */
void FLOATING_POINT_EQUALITY_S_BAD(float x, float y)
{
    if ( x == y ) // 缺陷点：浮点数不能直接用 == 或 != 比较
    {
        /* do something */
    } 
}

/**
 * Check whether two single-precision values are approximately equal within
 * the float precision epsilon and execute an action if they are.
 *
 * Compares x and y using the single-precision machine epsilon (__FLT_EPSILON__)
 * to determine if their absolute difference is sufficiently small.
 *
 * @param x First float value to compare.
 * @param y Second float value to compare.
 */
void FLOATING_POINT_EQUALITY_S_GOOD(float x, float y)
{
    if ( fabs(x - y) < __FLT_EPSILON__ ) // 修复点：设置误差判断是否足够接近
    {
        /* do something */
    } 
}