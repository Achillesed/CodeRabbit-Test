/**
    Filename: USELESS_CALL_S.c
    Vuln: USELESS_CALL_S
    SourceLine: -1
    SinkLine: 28
    Comment: 无用的调用
*/

#include<stdio.h>
//Cov官网样例
typedef struct 
{
    int x;
    int y;    
} pair_t;

/**
 * Return a pair with its components exchanged.
 *
 * @param xy The input pair whose `x` and `y` fields will be swapped in the result.
 * @returns A `pair_t` whose `x` equals the input's `y` and whose `y` equals the input's `x`.
 */
pair_t swap(pair_t xy)
{
    pair_t swapped;
    swapped.x = xy.y;
    swapped.y = xy.x;
    return swapped;
}

/**
 * Demonstrates a useless call where the return value of `swap` is ignored.
 *
 * Creates a `pair_t` initialized to {1, 2} and calls `swap` without using its
 * returned value to illustrate the incorrect usage pattern.
 */
void USELESS_CALL_S_BAD()
{
    pair_t xy = {1,2};
    swap(xy);   //缺陷点：函数swap调用仅对已忽略的其返回值有用
}

/**
 * Demonstrates correct usage of swap by assigning the returned swapped pair back to the original variable.
 *
 * Creates a `pair_t` initialized to {1, 2} and replaces it with the result of `swap(xy)`.
 */
void USELESS_CALL_S_GOOD()
{
    pair_t xy = {1,2};
    xy = swap(xy);   //修复点
}

