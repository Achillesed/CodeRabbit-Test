/**
    Filename: IA_USEPTRSUBDETSIZE_S.c
    Vuln: IA_USEPTRSUBDETSIZE_S
    SourceLine: -1
    SinkLine: 21
    Comment: 使用指针减法确定大小
*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/**
 * Demonstrates incorrect pointer subtraction by subtracting a pointer into one array from the base of a different array.
 *
 * Locates '/' in s1 and computes Pos as (ptrPos - s2); subtracting pointers that do not point into the same array can produce an incorrect value or undefined behavior.
 */
void IA_USEPTRSUBDETSIZE_S_BAD()
{
    char s1[] = "abc/opqrstu";
    char s2[] = "abc/opqrstu";
    char* ptrPos;
    size_t Pos;
    ptrPos = strchr(s1, '/');
    Pos = (size_t) (ptrPos - s2);   //缺陷点：ptrPos（指向 s1） 与 s2 指向不同的内存区域，计算可能不在意料之中
}

/**
 * Compute the index of the first '/' character in s1 and store it in the local variable `Pos`.
 *
 * Demonstrates correct pointer subtraction by subtracting a pointer into `s1` from `s1`'s base.
 */
void IA_USEPTRSUBDETSIZE_S_GOOD()
{
    char s1[] = "abc/opqrstu";
    char s2[] = "abc/opqrstu";
    char* ptrPos;
    size_t Pos;
    ptrPos = strchr(s1, '/');
    Pos = (size_t) (ptrPos - s1);   //缺陷点：ptrPos 与 s1 指向相同内存区域
}