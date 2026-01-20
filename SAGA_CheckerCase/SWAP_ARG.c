/**
    Filename: SWAP_ARG.c
    Vuln: SWAP_ARG
    SourceLine: -1
    SinkLine: 22
    Comment: 参数的顺序错误
*/

#include <stdio.h>
#include <stdlib.h>
int getValue();
/**
 * Copy the integer value at index `src` to index `dst` within the provided array.
 *
 * @param dst Destination index in `ptr` where the value will be written.
 * @param src Source index in `ptr` from which the value will be read.
 * @param ptr Pointer to an integer array; must be non-NULL and have valid indices `src` and `dst`.
 */
void copy_value(int dst, int src, int *ptr) 
{
    ptr[dst] = ptr[src];
}

/**
 * Demonstrates a vulnerability caused by passing arguments to a helper in the wrong order.
 *
 * Allocates an 8-element int array, initializes it with values 0 through 7, then calls
 * copy_value with the destination and source arguments swapped (invoking the incorrect
 * argument order). The function frees the allocated memory before returning.
 */
void SWAP_ARG_BAD() 
{
    int dst = getValue();
    int src = getValue();
    int *ptr = malloc(sizeof(int) * 8);
    if(!ptr) return;
    for (int i = 0; i < 8; i++)
    {
        ptr[i] = i;
    }
    copy_value(src, dst, ptr);  // 缺陷点：参数顺序错误
    free(ptr);
}

/**
 * Demonstrates correct argument ordering for copy_value by allocating an 8-element int array,
 * initializing it with values 0..7, copying the value from the specified source index to the
 * specified destination index, and freeing the array.
 *
 * If memory allocation fails, the function returns without performing the copy.
 */
void SWAP_ARG_GOOD() 
{
    int dst = getValue();
    int src = getValue();
    int *ptr = malloc(sizeof(int) * 8);
    if(!ptr) return;
    for (int i = 0; i < 8; i++)
    {
        ptr[i] = i;
    }
    copy_value(dst, src, ptr);  // 修复点：参数顺序一致
    free(ptr);
}