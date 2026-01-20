/**
    Filename: BAD_COMPARE_MEMCMP_S.c
    Vuln: BAD_COMPARE_MEMCMP_S
    SourceLine: -1
    SinkLine: 15
    Comment: 滥用了 memcmp 风格函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BAD_COMPARE_MEMCMP_S_BAD(const char *s) 
{
    if (strcmp(s, "blah") == 1)     //缺陷点：错误的认为 memcmp 类函数返回值为定值
    {
        /* do something */
    }
}

void BAD_COMPARE_MEMCMP_S_GOOD(const char *s) 
{
    if (strcmp(s, "blah") > 0)      //修复点：memcmp 类函数返回值应为正数情况
    {
        /* do something */
    }
}