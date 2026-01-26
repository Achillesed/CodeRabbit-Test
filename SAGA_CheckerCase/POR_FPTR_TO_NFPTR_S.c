/**
    Filename: POR_FPTR_TO_NFPTR_S.c
    Vuln: POR_FPTR_TO_NFPTR_S
    SourceLine: -1
    SinkLine: 16
    Comment: 将指向浮点表达式的指针强制转化为非浮点类型指针
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates an unsafe cast from a pointer to floating-point data to a pointer to a non-floating type.
 *
 * Creates a float object and then forcibly converts its `float *` pointer to an `int *`, illustrating
 * the defect of treating a floating-point object as a non-floating-pointer type.
 */
void POR_FPTR_TO_NFPTR_S_BAD()
{
    float f = 1.23;
    float *a = &f;
    int *a1 = (int *)a; //缺陷点：浮点表达式的指针 float * 强制转化为非浮点类型指针 int *
}

/**
 * Preserve a floating-point pointer by copying a `float *` to another `float *`.
 *
 * Demonstrates the corrected behavior where the address of a `float` is assigned to
 * another `float *` without casting to a non-floating-point pointer type.
 */
void POR_FPTR_TO_NFPTR_S_GOOD()
{
    float f = 1.23;
    float *a = &f;
    float *a1 = a;  //修复点
}