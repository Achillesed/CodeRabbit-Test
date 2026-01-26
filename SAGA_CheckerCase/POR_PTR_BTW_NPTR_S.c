/**
    Filename: POR_PTR_BTW_NPTR_S.c
    Vuln: POR_PTR_BTW_NPTR_S
    SourceLine: -1
    SinkLine: 16
    Comment: 在不同时是指针或非指针的类型之间进行强制转换
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates an incorrect cast converting a pointer to a non-pointer integer.
 *
 * Initializes a `float` and a `float *` then casts the pointer to an `int`,
 * producing implementation-defined or undefined behavior depending on the platform.
 */
void POR_PTR_BTW_NPTR_S_BAD()
{
    float s = 1.23;
    float *ptr = &s;
    int a1 = (int)ptr;  //缺陷点：浮点指针 float* 转化为 非指针类型 int
}

/**
 * Demonstrates casting a float pointer to a double pointer.
 *
 * Declares a float variable, obtains its address as a `float*`, and casts that pointer to `double*`.
 */
void POR_PTR_BTW_NPTR_S_GOOD()
{
    float s = 1.23;
    float* ptr = &s;
    double* ptrValue = (double*)ptr;    //修复点：浮点指针 float* 转化为 double*
}