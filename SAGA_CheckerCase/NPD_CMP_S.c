/**
    Filename: NPD_CMP_S.c
    Vuln: NPD_CMP_S
    SourceLine: -1
    SinkLine: 24
    Comment: 指针被NULL检查前或后解引用
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates writing to and freeing an integer pointer without ensuring it is non-NULL.
 *
 * Writes a computed value to `*p` unconditionally and then calls `free(p)`; if `p` is `NULL` the write causes undefined behavior (null pointer dereference).
 *
 * @param p Pointer to an integer that may be NULL.
 */
void NPD_CMP_S_BAD(int *p) 
{
    int x = 1;
    if ( p == NULL ) 
    {
      x = 0;
    }
    else
    {
      x += 1;
    }
      x += 1;
      *p = x;   // 缺陷点：指针 p 在之前与 null 有比较，说明此路径下指针 p 可能为 null，在此处可能发生空指针解引用
      free(p);
}

/**
 * Safely assigns a computed value to *p when p is non-NULL and then frees p.
 *
 * If `p` is non-NULL the function stores the value `2` into `*p`; if `p` is NULL no write occurs.
 * The function always calls `free(p)` (calling free with NULL is allowed).
 *
 * @param p Pointer to an int that may be NULL. If non-NULL, receives the stored value before being freed.
 */
void NPD_CMP_S_GOOD(int *p) 
{
    int x = 1;
    if ( p == NULL ) 
    {
        x = 0;
    } 
    else 
    {
        x += 1;
        *p = x;   // 修复点：此路径下确保 指针 p 不为 null
    }
    free(p);
}