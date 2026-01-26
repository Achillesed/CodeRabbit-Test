/**
    Filename: POR_IMCOMPATIBLE_TYPE_S.c
    Vuln: POR_IMCOMPATIBLE_TYPE_S
    SourceLine: -1
    SinkLine: 17
    Comment: 尝试将表达式强制转换为可能不兼容的大小类型 (&& INCOMPATIBLE_CAST_S)
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates an unsafe pointer cast from an `int*` to a `long*` and writes the resulting value through `pl`.
 *
 * The function casts the address of a local `int` to `long*`, dereferences it, and assigns that value to `*pl`,
 * which invokes undefined behavior due to incompatible pointer types.
 *
 * @param pl Pointer to a `long` that will receive the value read via the invalid cast.
 */
void POR_IMCOMPATIBLE_TYPE_S_BAD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = *(long*)pi;   // 缺陷点：不能将 指向 int 对象 的 int* 指针 强制转换为 long* 类型指针，再以 long 类型 取出内容
}

/**
 * Store the value 32 into the long pointed to by `pl` using a safe integer conversion.
 *
 * @param pl Pointer to a `long` where the converted `int` value will be written.
 */
void POR_IMCOMPATIBLE_TYPE_S_GOOD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = 0L | *(int*)pi;    // 修复点：0L 与 i 的值进行按位或运算
}