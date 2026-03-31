/**
    Filename: BAD_MEMSET_S.c
    Vuln: BAD_MEMSET_S
    SourceLine: -1
    SinkLine: 15
    Comment: Memset 调用错误
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BAD_MEMSET_S_BAD(char *buf) 
{ 
    memset(buf, 0, 0);  //缺陷点：缓冲区初始化大小为 0
}

void BAD_MEMSET_S_GOOD(char *buf) 
{ 
    memset(buf, 0, sizeof(buf));    //修复点
}