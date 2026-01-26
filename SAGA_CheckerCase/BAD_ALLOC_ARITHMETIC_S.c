/**
    Filename: BAD_ALLOC_ARITHMETIC_S.c
    Vuln: BAD_ALLOC_ARITHMETIC_S
    SourceLine: -1
    SinkLine: 14
    Comment: 离散的指针算术运算
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates incorrect pointer arithmetic on a malloc-allocated pointer followed by free.
 *
 * Allocates `a` bytes with malloc, advances the returned pointer by `b`, and then frees the advanced pointer.
 * Freeing a pointer that is not the value returned by malloc results in undefined behavior when `b` is nonzero.
 *
 * @param a Number of bytes requested from malloc.
 * @param b Offset (in bytes) added to the allocated pointer before calling free; nonzero values can make the free invalid.
 */
void BAD_ALLOC_ARITHMETIC_S_BAD(int a, int b) 
{
  char *p = malloc(a) + b;   // 缺陷点：可能由于圆括号放错位置，导致分配不足或分配过度以及非正常的指针算术运算
  free(p);
}

/**
 * Allocate (a + b) bytes on the heap and immediately free the allocation.
 *
 * @param a First number of bytes to include in the allocation size.
 * @param b Second number of bytes to include in the allocation size.
 */
void BAD_ALLOC_ARITHMETIC_S_GOOD(int a, int b) 
{
  char *p = malloc(a + b);   // 修复点：避免错误的指针算数运算
  free(p);
}