/**
    Filename: DANGERFUNC_POTENTIAL_S.c
    Vuln: DANGERFUNC_POTENTIAL_S
    SourceLine: -1
    SinkLine: 16
    Comment: 使用具有潜在危险的函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DANGERFUNC_POTENTIAL_S_BAD(char *string)
{
    char buf[24];
    strcpy(buf, string); // 缺陷点
}

void DANGERFUNC_POTENTIAL_S_GOOD(char *string)
{
    char buf[24];
    strncpy(buf, string, 23); // 修复点：使用 strncpy 替换，并手动添加字符串结尾符
    buf[23] = '\0';
}