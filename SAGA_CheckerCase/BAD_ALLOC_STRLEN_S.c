/**
    Filename: BAD_ALLOC_STRLEN_S.c
    Vuln: BAD_ALLOC_STRLEN_S
    SourceLine: -1
    SinkLine: 18
    Comment: 字符串长度计算错误
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BAD_ALLOC_STRLEN_S_BAD(char* name)
{
  char *new_name = NULL;
  if (name) 
  {
    new_name = (char*)malloc(strlen(name+1));  //缺陷点：分配大小错误，可能导致复制时发生缓冲区溢出
    //strcpy(new_name, name);
    free(new_name);
  }
}

void BAD_ALLOC_STRLEN_S_GOOD(char* name)
{
  char *new_name = NULL;
  if (name) 
  {
    new_name = (char*)malloc(strlen(name) + 1);  //修复点：使用正确的字符串长度计算
    //strcpy(new_name, name);
    free(new_name);
  }
}