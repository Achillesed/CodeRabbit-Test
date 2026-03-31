/**
    Filename: BAD_FREE_S.c
    Vuln: BAD_FREE_S
    SourceLine: -1
    SinkLine: 20
    Comment: 释放非堆上的内存
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16

struct S { int a[4]; };

void BAD_FREE_S_BAD(struct S *s) 
{
    int stackarray[3];
    int *p = stackarray;  
    free(p);              // 缺陷点：释放了栈上的内存
}

void BAD_FREE_S_GOOD(struct S *s) 
{
    int *stackarray = malloc(sizeof(int)*4);
    int *p = stackarray;  
    free(p);              // 修复点：释放堆上内存
}