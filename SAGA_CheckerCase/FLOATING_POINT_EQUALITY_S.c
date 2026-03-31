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
void FLOATING_POINT_EQUALITY_S_BAD(float x, float y)
{
    if ( x == y ) // 缺陷点：浮点数不能直接用 == 或 != 比较
    {
        /* do something */
    } 
}

void FLOATING_POINT_EQUALITY_S_GOOD(float x, float y)
{
    if ( fabs(x - y) < __FLT_EPSILON__ ) // 修复点：设置误差判断是否足够接近
    {
        /* do something */
    } 
}