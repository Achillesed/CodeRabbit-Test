/**
    Filename: DANGERFUNC_MUST_S.c
    Vuln: DANGERFUNC_MUST_S
    SourceLine: -1
    SinkLine: 18
    Comment: 使用危险函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 16

char *gets(char*);
void DANGERFUNC_MUST_S_BAD()
{
    char buf[BUFSIZE];
    gets(buf);      //缺陷点
}

void DANGERFUNC_MUST_S_GOOD()
{
    char buf[BUFSIZE];
    fgets(buf,sizeof(buf),stdin);     //修复点
}
