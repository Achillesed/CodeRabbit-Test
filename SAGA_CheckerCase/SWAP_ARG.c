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
void copy_value(int dst, int src, int *ptr) 
{
    ptr[dst] = ptr[src];
}

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