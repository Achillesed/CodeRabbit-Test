/**
    Filename: NPD_NFR_S.c
    Vuln: NPD_NFR_S
    SourceLine: -1
    SinkLine: 19
    Comment: 函数NULL返回值解引用
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Provide a null pointer to int.
 *
 * @return NULL.
 */
static int *return_Null_func()
{
    return NULL;
}
/**
 * Demonstrates a null pointer dereference vulnerability.
 *
 * Calls a helper that may return `NULL` and then dereferences the returned pointer,
 * causing undefined behavior (null pointer dereference) if the pointer is `NULL`.
 */
void NPD_NFR_S_BAD()
{
        int *a = return_Null_func();
        *a = 1;     //缺陷点：函数可能返回null，在此处进行解引用
}

/**
 * Ensure the pointer returned by return_Null_func is valid and, if so, set the pointed integer to 1.
 *
 * Calls return_Null_func(); returns immediately if the result is NULL, otherwise assigns 1 to the pointed integer.
 */
void NPD_NFR_S_GOOD()
{
        int *a = return_Null_func();
        if(!a) return;
        *a = 1;     //修复点：解引用前进行了判空检查
}