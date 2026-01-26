/**
    Filename: SELF_ASSIGN.c
    Vuln: SELF_ASSIGN
    SourceLine: -1
    SinkLine: 20
    Comment: 自赋值
*/

#include <stdio.h>
#include <stdlib.h>

struct foo 
{
    int x;
    int y;
};

/**
 * Demonstrates an unintended self-assignment of a struct field.
 *
 * @param ptr Pointer to a `struct foo`; the function assigns `ptr->x` to itself.
 */
void SELF_ASSIGN_BAD(struct foo *ptr)
{
    ptr->x = ptr->x; //缺陷点
}

/**
 * Copy the `y` field into the `x` field of the provided `foo` structure.
 * @param ptr Pointer to the `foo` instance whose `x` will be set to the value of `y`.
 */
void SELF_ASSIGN_GOOD(struct foo *ptr)
{
    ptr->x = ptr->y; //修复点
}