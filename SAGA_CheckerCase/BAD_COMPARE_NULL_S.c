/**
    Filename: BAD_COMPARE_NULL_S.c
    Vuln: BAD_COMPARE_NULL_S
    SourceLine: -1
    SinkLine: 14
    Comment: 与 NULL 做了不相等比较
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates an incorrect comparison of a pointer with NULL using a relational operator.
 *
 * This function contains a flawed check that compares the pointer `x` to `NULL` using a
 * relational operator (>=) rather than an equality check; it is intended to illustrate
 * an unsafe/incorrect NULL comparison pattern.
 *
 * @param x Pointer to an integer; may be `NULL`.
 */
void BAD_COMPARE_NULL_S_BAD(int *x) 
{
    if (x >= NULL)     //缺陷点：与 NULL 做了不相等比较
    {
        /* do something */
    }
}

/**
 * Execute the function's action if the provided pointer is NULL.
 *
 * Checks whether the pointer `x` is equal to `NULL` and performs the conditional action when it is.
 *
 * @param x Pointer to an int to test for NULL.
 */
void BAD_COMPARE_NULL_S_GOOD(int *x) 
{
    if (x == NULL)     //修复点：与 NULL 做相等和不相等比较
    {
        /* do something */
    }
}