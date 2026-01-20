/**
    Filename: NPD_COMMON_S.cpp
    Vuln: NPD_COMMON_S
    SourceLine: -1
    SinkLine: 15
    Comment: 空指针解引用
*/

#include <stdio.h>
/**
 * Sets `p` to NULL and, if `a` is greater than 2, attempts to write through `p`, causing a null pointer dereference.
 *
 * @param a Integer that controls whether the dereference occurs; when greater than 2 the function will attempt to assign through `p`.
 * @param p Pointer which is set to NULL on entry to the function (subsequent dereference is invalid).
 */
void NPD_COMMON_S_BAD(int a,int *p)
{
    p = NULL;
    if(a > 2)
    {
        *p = 2;   //缺陷点：指针 p 为 NULL，此处产生了空指针解引用缺陷
    }
}

/**
 * Set *p to 2 when p is non-NULL and a is greater than 2.
 *
 * @param a Integer used as the condition; the assignment occurs only if a > 2.
 * @param p Pointer to the integer to update; if `p` is NULL the function returns without modifying anything.
 */
void NPD_COMMON_S_GOOD(int a,int *p)
{ 
    if(!p) return;
    if(a > 2)
    {
        *p = 2;   //修复点：确保指针 p 不为 NULL
    }
}