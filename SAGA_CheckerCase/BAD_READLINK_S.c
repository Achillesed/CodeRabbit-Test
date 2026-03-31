/**
    Filename: BAD_READLINK_S.c
    Vuln: BAD_READLINK_S
    SourceLine: -1
    SinkLine: 18
    Comment: 不安全地使用了 Readlink
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void BAD_READLINK_S_BAD() 
{
    int len;
    char buff[128];
    char *link = malloc(sizeof(char));
    if(!link) return;
    len = readlink(link, buff, sizeof(buff));
    buff[len] = 0;          //缺陷点：未检查 readlink 返回值就进行使用
    free(link);
}

void BAD_READLINK_S_GOOD() 
{
    int len;
    char buff[128];
    char *link = malloc(sizeof(char));
    if(!link) return;
    len = readlink(link, buff, sizeof(buff));
    if(len != -1 && len < sizeof(buff))
    {
        buff[len] = 0;   //修复点：使用 readlink 返回值前进行了检查
    }
    free(link);
}