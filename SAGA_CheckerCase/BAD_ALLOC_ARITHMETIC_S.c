/**
    Filename: BAD_ALLOC_ARITHMETIC_S.c
    Vuln: BAD_ALLOC_ARITHMETIC_S
    SourceLine: -1
    SinkLine: 14
    Comment: 离散的指针算术运算
*/

#include <stdio.h>
#include <stdlib.h>

void BAD_ALLOC_ARITHMETIC_S_BAD(int a, int b) 
{
  char *p = malloc(a) + b;   // 缺陷点：可能由于圆括号放错位置，导致分配不足或分配过度以及非正常的指针算术运算
  free(p);
}

void BAD_ALLOC_ARITHMETIC_S_GOOD(int a, int b) 
{
  char *p = malloc(a + b);   // 修复点：避免错误的指针算数运算
  free(p);
}