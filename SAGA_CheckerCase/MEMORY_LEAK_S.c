/**
    Filename: MEMORY_LEAK_S.c
    Vuln: MEMORY_LEAK_S
    SourceLine: -1
    SinkLine: 13
    Comment: 有效生存期后未释放内存
*/

#include <stdlib.h>

void MEMORY_LEAK_S_BAD(int size)
{
    int *ptr = malloc(sizeof(int) * size);  //缺陷点：此处的 malloc 在有效生存期后未进行内存释放
    if(!ptr) return;
    *ptr = 25;
}

void MEMORY_LEAK_S_GOOD(int size)
{
    int *ptr = malloc(sizeof(int) * size);  //修复点：此 malloc 后续有释放
    if(!ptr) return;
    *ptr = 25;
    free(ptr);
}