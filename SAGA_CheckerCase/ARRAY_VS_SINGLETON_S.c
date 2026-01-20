/**
    Filename: ARRAY_VS_SINGLETON_S.c
    Vuln: ARRAY_VS_SINGLETON_S
    SourceLine: -1
    SinkLine: 14
    Comment: 单一对象的指针被错误地当作数组
*/

#include <stdio.h>
#include <stdlib.h>

void ARRAY_VS_SINGLETON_S_BAD(int *s,int index)
{
    s[index] = 123; // 缺陷点：单一对象被当做数组使用
}
void ARRAY_VS_SINGLETON_S_BAD_CALL()
{
    int c;
    ARRAY_VS_SINGLETON_S_BAD(&c, 9);
}

void ARRAY_VS_SINGLETON_S_GOOD(int *s,int index)
{
    s[index] = 123; // 修复点：正常使用堆上的数组
}
void ARRAY_VS_SINGLETON_S_GOOD_CALL()
{
    int *c = malloc(10 * sizeof(int));
    if(!c) return;
    ARRAY_VS_SINGLETON_S_GOOD(c, 9);
    free(c);
}