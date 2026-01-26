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

/**
 * Demonstrates an incorrect string allocation that may under-allocate buffer space.
 *
 * If `name` is non-NULL, this function allocates memory using `malloc(strlen(name+1))`
 * (an incorrect size calculation). The allocation is immediately freed; if a string copy
 * were performed into the allocated buffer, it could cause a buffer overflow. If `name`
 * is NULL, the function does nothing.
 *
 * @param name Input string; may be NULL. When non-NULL, memory is allocated using an incorrect size calculation.
 */
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

/**
 * Allocate and free a buffer sized to hold a copy of the input C-string including the terminating null byte.
 *
 * If `name` is non-NULL, this function allocates `strlen(name) + 1` bytes intended for a copy of `name`
 * and then frees the allocated buffer.
 *
 * @param name Null-terminated input string to copy; if NULL the function performs no action.
 */
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