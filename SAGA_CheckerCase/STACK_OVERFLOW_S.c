/**
    Filename: STACK_OVERFLOW_S.c
    Vuln: STACK_OVERFLOW_S
    SourceLine: -1
    SinkLine: 22
    Comment: 栈写入向上溢出
*/

#include <stdio.h>
#include <stdlib.h>

#define SZ 16
int getValue();
/**
 * Demonstrates a stack-based write that can go out of bounds when an external index is used.
 *
 * Allocates a heap buffer of size SZ and obtains an index from getValue(). If allocation fails the function
 * returns -1. If the index satisfies 0 < i && i <= SZ + SZ the function writes to a stack buffer at b[i]
 * and returns the value of b[0]; otherwise it frees the heap buffer and returns 0.
 *
 * Note: when i == SZ + SZ the write b[i] is out of bounds and may cause undefined behavior.
 *
 * @returns `-1` if heap allocation fails, the value of `b[0]` after the conditional write when `0 < i && i <= SZ + SZ`, or `0` otherwise.
 */
int STACK_OVERFLOW_S_BAD()
{
    char b[SZ + SZ];
    int i = getValue();
    char * a = malloc(SZ);
    if(NULL == a) return -1;
    if(0 < i && i <= SZ + SZ)
    {
        b[i] = 1;    // 缺陷点："i <= SZ + SZ" 意味着在true分支中值可能为 "32" 此时越界
        return b[0];
    }
    free(a);
    return 0;
}

/**
 * Validate an index from getValue(), write a byte into a local buffer within bounds, and return the first byte.
 *
 * Writes the value 1 into a stack buffer at the index obtained from getValue() when the index is between 1 and 31
 * (inclusive), then returns the buffer's first element. Allocates SZ bytes on the heap and frees them only when the
 * index is not in the valid range.
 *
 * @returns `b[0]` when `i` is greater than 0 and less than SZ + SZ; `0` when `i` is out of that range; `-1` if heap
 * allocation fails.
 *
 * @note When the index is in the valid range the allocated heap memory is not freed before returning (intentional
 * control-flow in this function), which results in a memory leak on that path.
 */
int STACK_OVERFLOW_S_GOOD()
{
    char b[SZ + SZ];
    int i = getValue();
    char * a = malloc(SZ);
    if(NULL == a) return -1;
    if(0 < i && i < SZ + SZ)
    {
        b[i] = 1;    // 修复点："i < SZ + SZ" 意味着在true分支中值可能为 "31" 此时不越界
        return b[0];
    }
    free(a);
    return 0;
}