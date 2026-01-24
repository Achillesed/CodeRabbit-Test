/**
    Filename: BAD_COMPARE_STR_S.c
    Vuln: BAD_COMPARE_STR_S
    SourceLine: -1
    SinkLine: 15
    Comment: 指针与字符串常量做了比较
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BAD_COMPARE_STR_S_GOOD(const char *other) 
{
    if(other == "expected")     //缺陷点：指针（地址）与字符串常量作比较
    {
        /* do something */
    }
}

void BAD_COMPARE_STR_S_BAD(const char *other) 
{
    if(strcmp(other, "expected") == 0)     //修复点：使用 strcmp 函数比较字符串内容
    {
        /* do something */
    }
}