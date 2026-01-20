/**
    Filename: BAD_POINTER_ADDITION.c
    Vuln: BAD_POINTER_ADDITION
    SourceLine: -1
    SinkLine: 15
    Comment: 错误的指针增量
*/

#include <stdio.h>
#include <stdlib.h>
int* getPtr();
/**
 * Demonstrates incorrect pointer/increment usage by applying post-increment to the pointer and then dereferencing.
 *
 * Obtains an `int *` from `getPtr()` and evaluates `*p++`, which increments the pointer and dereferences the original address; this can cause undefined behavior if the pointer is invalid or moves past its intended object.
 */
void BAD_POINTER_ADDITION_BAD() 
{
    int *p = getPtr();
    *p++;        // 缺陷点：自增后立刻解引用，指针位置偏移。
}

/**
 * Increment the integer pointed to by getPtr() then advance the pointer.
 *
 * Obtains an int pointer from getPtr(), increments the value at that address, and then advances the pointer to the next int.
 */
void BAD_POINTER_ADDITION_GOOD() 
{
    int *p = getPtr();
    (*p)++;      //  修复点：使用括号保证操作准确性
    p ++;
}