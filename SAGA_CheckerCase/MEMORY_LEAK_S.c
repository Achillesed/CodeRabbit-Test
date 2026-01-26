/**
    Filename: MEMORY_LEAK_S.c
    Vuln: MEMORY_LEAK_S
    SourceLine: -1
    SinkLine: 13
    Comment: 有效生存期后未释放内存
*/

#include <stdlib.h>

/**
 * Allocate an array of `size` integers and set the first element to 25.
 *
 * If allocation succeeds, the function writes 25 to the first element but does not free the allocated memory, causing a memory leak. If allocation fails, the function returns without modifying memory.
 *
 * @param size Number of integers to allocate.
void MEMORY_LEAK_S_BAD(int size)
{
    int *ptr = malloc(sizeof(int) * size);  //缺陷点：此处的 malloc 在有效生存期后未进行内存释放
    if(!ptr) return;
    *ptr = 25;
}

/**
 * Allocate an array of `int` of the specified length, set the first element to 25, and free the allocation.
 *
 * @param size Number of `int` elements to allocate; if allocation fails the function returns without modifying memory.
 */
void MEMORY_LEAK_S_GOOD(int size)
{
    int *ptr = malloc(sizeof(int) * size);  //修复点：此 malloc 后续有释放
    if(!ptr) return;
    *ptr = 25;
    free(ptr);
}