/**
    Filename: PTR_PROH_PARMPTR_ASSGN_S.c
    Vuln: PTR_PROH_PARMPTR_ASSGN_S
    SourceLine: -1
    SinkLine: 16
    Comment: 禁止对参数指针进行赋值
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Increment an internal static counter and reassign the local parameter pointer to point to it.
 *
 * This function updates a static counter, assigns the local copy of `pa` to refer to that internal counter,
 * and returns the updated counter value. The assignment modifies only the function's local copy of the pointer.
 *
 * @param pa Pointer that will be reassigned locally to point at the internal static counter.
 * @returns The incremented value of the internal static counter.
 */
unsigned int PTR_PROH_PARMPTR_ASSGN_S_BAD(unsigned int *pa)
{
    static unsigned int i = 10;
    i = i + 1;
    pa = &i;    //缺陷点：违背规则对参数指针进行赋值
    return i;
}

/**
 * Increment a static counter and read the value pointed to by pa.
 *
 * Reads the unsigned integer pointed to by `pa` and returns the static counter after incrementing it.
 * @param pa Pointer to an unsigned int whose value is read but not modified.
 * @returns The incremented static counter value.
 */
unsigned int PTR_PROH_PARMPTR_ASSGN_S_GOOD(unsigned int *pa)
{
    static unsigned int i = 10;
    i = i + 1;
    unsigned int a = *pa;    //修复点：进行使用
    return i;
}