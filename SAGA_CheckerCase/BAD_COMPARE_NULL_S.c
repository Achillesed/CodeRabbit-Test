/**
    Filename: BAD_COMPARE_NULL_S.c
    Vuln: BAD_COMPARE_NULL_S
    SourceLine: -1
    SinkLine: 14
    Comment: 与 NULL 做了不相等比较
*/

#include <stdio.h>
#include <stdlib.h>

void BAD_COMPARE_NULL_S_BAD(int *x) 
{
    if (x >= NULL)     //缺陷点：与 NULL 做了不相等比较
    {
        /* do something */
    }
}

void BAD_COMPARE_NULL_S_GOOD(int *x) 
{
    if (x == NULL)     //修复点：与 NULL 做相等和不相等比较
    {
        /* do something */
    }
}
