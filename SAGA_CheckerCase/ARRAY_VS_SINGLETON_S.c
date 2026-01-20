/**
    Filename: ARRAY_VS_SINGLETON_S.c
    Vuln: ARRAY_VS_SINGLETON_S
    SourceLine: -1
    SinkLine: 14
    Comment: 单一对象的指针被错误地当作数组
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Write the value 123 into `s` at the specified index.
 *
 * @param s Pointer to the first element of the target array; writing occurs at `s[index]`.
 * @param index Index into the array where `123` is stored; behavior is undefined if `s` does not point to storage for that index.
 */
void ARRAY_VS_SINGLETON_S_BAD(int *s,int index)
{
    s[index] = 123; // 缺陷点：单一对象被当做数组使用
}
/**
 * Demonstrates incorrect usage by passing the address of a single `int` to a function that treats it as an array.
 *
 * Calls ARRAY_VS_SINGLETON_S_BAD(&c, 9), which may cause an out-of-bounds write.
 */
void ARRAY_VS_SINGLETON_S_BAD_CALL()
{
    int c;
    ARRAY_VS_SINGLETON_S_BAD(&c, 9);
}

/**
 * Store the value 123 into the array element at the given index.
 * @param s Pointer to the first element of an `int` array with at least `index + 1` elements.
 * @param index Zero-based position within the array to write the value.
 *
 * Behavior is undefined if `s` is NULL or `index` is out of bounds for the provided array.
 */
void ARRAY_VS_SINGLETON_S_GOOD(int *s,int index)
{
    s[index] = 123; // 修复点：正常使用堆上的数组
}
/**
 * Allocate a 10-element int array, invoke ARRAY_VS_SINGLETON_S_GOOD with index 9, and free the array.
 *
 * If memory allocation fails, the function returns without calling ARRAY_VS_SINGLETON_S_GOOD.
 */
void ARRAY_VS_SINGLETON_S_GOOD_CALL()
{
    int *c = malloc(10 * sizeof(int));
    if(!c) return;
    ARRAY_VS_SINGLETON_S_GOOD(c, 9);
    free(c);
}