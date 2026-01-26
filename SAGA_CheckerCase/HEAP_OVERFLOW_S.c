/**
    Filename: HEAP_OVERFLOW_S.c
    Vuln: HEAP_OVERFLOW_S
    SourceLine: -1
    SinkLine: 24
    Comment: 堆写入向上溢出(优先报越界读取)
*/

#include <stdio.h>
#include <stdlib.h>

#define SZ 16
int getValue();
/**
 * Demonstrates a heap write using an incorrect upper-bound check that can write one byte past the allocated buffer.
 *
 * Allocates two heap buffers and obtains an index from `getValue()`. If the index is between 0 and `SZ+SZ` inclusive,
 * a write is performed to `b[i]`. Because the check uses `<= SZ+SZ`, an index equal to `SZ+SZ` will cause an out-of-bounds
 * write of one byte past `b`'s allocation.
 *
 * @returns 0 on success, -1 if memory allocation fails.
 */
int HEAP_OVERFLOW_S_BAD()
{
    int i;
    char *b = malloc(SZ + SZ);
    char *a = malloc(SZ);
    if(NULL == a || NULL == b) 
        return -1;
    i = getValue();
    if(i>=0 && i <= SZ + SZ)
    {
        b[i] = 1;   //缺陷点：比较'i <= SZ + SZ' 说明 i 可能为 SZ + SZ，此时溢出
    }
    /* do something */
    free(a);
    free(b);
    return 0;
}

/**
 * Perform a heap write into a buffer using a corrected boundary check to prevent out-of-bounds access.
 *
 * Allocates two heap buffers, obtains an index from getValue(), and if the index is within [0, SZ+SZ)
 * writes a byte to the first buffer at that index. Frees allocated memory before returning.
 *
 * @returns -1 if either allocation fails, 0 on success.
 */
int HEAP_OVERFLOW_S_GOOD()
{
    int i;
    char *b = malloc(SZ + SZ);
    char *a = malloc(SZ);
    if(NULL == a || NULL == b) 
        return -1;
    i = getValue();
    if(i>=0 && i < SZ + SZ)
    {
        b[i] = 1;   //修复点：此时 i 的最大值为 SZ + SZ - 1，不会溢出
    }
    /* do something */
    free(a);
    free(b);
    return 0;
}