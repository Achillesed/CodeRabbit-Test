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