/**
    Filename: RESOURCE_LEAK_S.c
    Vuln: RESOURCE_LEAK_S
    SourceLine: -1
    SinkLine: 16
    Comment: 文件使用后未关闭
*/

#include <stdio.h>
#include <stdlib.h>

void RESOURCE_LEAK_S_BAD() 
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+"); // 缺陷点：文件使用后未关闭
    /* do something */
}

void RESOURCE_LEAK_S_GOOD() 
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+"); // 修复点：后续存在关闭
    if(!data) return;
    /* do something */
    fclose(data);
}