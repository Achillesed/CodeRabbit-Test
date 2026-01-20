/**
    Filename: POR_IMCOMPATIBLE_TYPE_S.c
    Vuln: POR_IMCOMPATIBLE_TYPE_S
    SourceLine: -1
    SinkLine: 17
    Comment: 尝试将表达式强制转换为可能不兼容的大小类型 (&& INCOMPATIBLE_CAST_S)
*/

#include <stdio.h>
#include <stdlib.h>

void POR_IMCOMPATIBLE_TYPE_S_BAD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = *(long*)pi;   // 缺陷点：不能将 指向 int 对象 的 int* 指针 强制转换为 long* 类型指针，再以 long 类型 取出内容
}

void POR_IMCOMPATIBLE_TYPE_S_GOOD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = 0L | *(int*)pi;    // 修复点：0L 与 i 的值进行按位或运算
}