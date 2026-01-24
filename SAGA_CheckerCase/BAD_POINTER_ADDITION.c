/**
    Filename: BAD_POINTER_ADDITION.c
    Vuln: BAD_POINTER_ADDITION
    SourceLine: -1
    SinkLine: 15
    Comment: 错误的指针增量
*/

#include <stdio.h>
#include <stdlib.h>
int* getPtr();
void BAD_POINTER_ADDITION_BAD() 
{
    int *p = getPtr();
    *p++;        // 缺陷点：自增后立刻解引用，指针位置偏移。
}

void BAD_POINTER_ADDITION_GOOD() 
{
    int *p = getPtr();
    (*p)++;      //  修复点：使用括号保证操作准确性
    p ++;
}