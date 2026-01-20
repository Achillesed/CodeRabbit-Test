/**
    Filename: POR_FTYPE_TO_NFTYPE_S.cpp
    Vuln: POR_FTYPE_TO_NFTYPE_S
    SourceLine: -1
    SinkLine: 13
    Comment: 将浮点表达式强制转化为非浮点类型
*/
#include<math.h>

/**
 * Demonstrates an unsafe conversion from floating-point to integer that discards the fractional part.
 *
 * The function initializes a float and assigns it to an int using an implicit cast, causing truncation
 * of the fractional component (illustrates a faulty float-to-integer conversion).
 */
void POR_FTYPE_TO_NFTYPE_S_BAD()
{
    float a2 = 1.23;
    int a3 = a2;    //缺陷点：将浮点表达式强制转化为非浮点类型
}

/**
 * Convert a floating-point constant to a long using round-to-nearest.
 *
 * Uses `lround` to round the float 1.23 to the nearest integer and store the result in a `long`.
 */
void POR_FTYPE_TO_NFTYPE_S_GOOD()
{
    float a2 = 1.23;
    long a3 = lround(a2);    //修复点：四舍五入返回 long 类型
}