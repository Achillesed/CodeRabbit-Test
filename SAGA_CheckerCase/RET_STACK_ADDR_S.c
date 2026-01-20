/**
    Filename: RET_STACK_ADDR_S.c
    Vuln: RET_STACK_ADDR_S
    SourceLine: -1
    SinkLine: 17
    Comment: 返回栈变量的地址
*/

#include <stdio.h>
#include <stdlib.h>
#define STR_MAX 16

/**
 * Provide access to a locally allocated buffer; the returned pointer is invalid after the function returns.
 *
 * @returns `char *` pointing to a buffer allocated on the function's stack frame; using this pointer after the function returns results in undefined behavior.
 */
char* RET_STACK_ADDR_S_BAD() 
{
    char name[STR_MAX];
    /* do something */
    return name;     //缺陷点：返回局部变量地址
}

/**
 * Allocate and return a heap buffer suitable for storing a name.
 *
 * Allocates STR_MAX bytes on the heap and returns a pointer to the allocated buffer.
 * If allocation fails, returns the string literal "bad".
 *
 * @returns Pointer to a heap-allocated buffer of length STR_MAX on success (caller must free it); ` "bad"` on allocation failure.
 */
char* RET_STACK_ADDR_S_GOOD() 
{
    char* name = malloc(sizeof(char)*STR_MAX);
    if(!name) return "bad";
    /* do something */
    return name;    // 修复点：返回堆上的地址
}