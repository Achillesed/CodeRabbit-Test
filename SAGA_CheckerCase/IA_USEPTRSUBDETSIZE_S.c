/**
    Filename: IA_USEPTRSUBDETSIZE_S.c
    Vuln: IA_USEPTRSUBDETSIZE_S
    SourceLine: -1
    SinkLine: 21
    Comment: 使用指针减法确定大小
*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void IA_USEPTRSUBDETSIZE_S_BAD()
{
    char s1[] = "abc/opqrstu";
    char s2[] = "abc/opqrstu";
    char* ptrPos;
    size_t Pos;
    ptrPos = strchr(s1, '/');
    Pos = (size_t) (ptrPos - s2);   //缺陷点：ptrPos（指向 s1） 与 s2 指向不同的内存区域，计算可能不在意料之中
}

void IA_USEPTRSUBDETSIZE_S_GOOD()
{
    char s1[] = "abc/opqrstu";
    char s2[] = "abc/opqrstu";
    char* ptrPos;
    size_t Pos;
    ptrPos = strchr(s1, '/');
    Pos = (size_t) (ptrPos - s1);   //缺陷点：ptrPos 与 s1 指向相同内存区域
}