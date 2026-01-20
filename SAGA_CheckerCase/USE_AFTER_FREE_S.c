/**
    Filename: USE_AFTER_FREE_S.c
    Vuln: USE_AFTER_FREE_S
    SourceLine: -1
    SinkLine: 25
    Comment: 释放后使用
*/

#include <stdio.h>
#include <stdlib.h>

struct data 
{
    int value;
};

/**
 * Demonstrates a use-after-free vulnerability by writing to memory after it has been freed.
 *
 * Allocates a `struct data`, initializes it, frees it, and then writes to the freed pointer,
 * which results in undefined behavior.
 *
 * @returns `0` on nominal completion, `-1` if memory allocation fails; note that writing to the
 *          freed pointer causes undefined behavior and may render the return value meaningless.
 */
int USE_AFTER_FREE_S_BAD()
{
    struct data *p = (struct data *)malloc(sizeof(struct data));
    if(!p) return -1;
    p->value = 42;
    //do something
    free(p);
    //do something
    p->value = 100;   //缺陷点：使用已释放指针
    return 0;
}

/**
 * Allocate, initialize, and free a data object without accessing it after free.
 *
 * Allocates a struct data, sets its value, then frees the allocation and returns
 * without using the freed memory.
 *
 * @returns 0 on success, -1 if memory allocation fails.
 */
int USE_AFTER_FREE_S_GOOD()
{
    struct data *p = (struct data *)malloc(sizeof(struct data));
    if(!p) return -1;
    p->value = 42;
    //do something
    free(p);  //修复点
    return 0;
}