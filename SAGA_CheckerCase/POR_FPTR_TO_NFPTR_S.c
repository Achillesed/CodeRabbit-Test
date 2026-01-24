/**
    Filename: POR_FPTR_TO_NFPTR_S.c
    Vuln: POR_FPTR_TO_NFPTR_S
    SourceLine: -1
    SinkLine: 16
    Comment: 将指向浮点表达式的指针强制转化为非浮点类型指针
*/

#include <stdio.h>
#include <stdlib.h>

void POR_FPTR_TO_NFPTR_S_BAD()
{
    float f = 1.23;
    float *a = &f;
    int *a1 = (int *)a; //缺陷点：浮点表达式的指针 float * 强制转化为非浮点类型指针 int *
}

void POR_FPTR_TO_NFPTR_S_GOOD()
{
    float f = 1.23;
    float *a = &f;
    float *a1 = a;  //修复点
}