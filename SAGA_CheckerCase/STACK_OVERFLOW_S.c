/**
    Filename: STACK_OVERFLOW_S.c
    Vuln: STACK_OVERFLOW_S
    SourceLine: -1
    SinkLine: 22
    Comment: 栈写入向上溢出
*/

#include <stdio.h>
#include <stdlib.h>

#define SZ 16
int getValue();
int STACK_OVERFLOW_S_BAD()
{
    char b[SZ + SZ];
    int i = getValue();
    char * a = malloc(SZ);
    if(NULL == a) return -1;
    if(0 < i && i <= SZ + SZ)
    {
        b[i] = 1;    // 缺陷点："i <= SZ + SZ" 意味着在true分支中值可能为 "32" 此时越界
        return b[0];
    }
    free(a);
    return 0;
}

int STACK_OVERFLOW_S_GOOD()
{
    char b[SZ + SZ];
    int i = getValue();
    char * a = malloc(SZ);
    if(NULL == a) return -1;
    if(0 < i && i < SZ + SZ)
    {
        b[i] = 1;    // 修复点："i < SZ + SZ" 意味着在true分支中值可能为 "31" 此时不越界
        return b[0];
    }
    free(a);
    return 0;
}