/**
    Filename: BAD_SHIFT.c
    Vuln: BAD_SHIFT
    SourceLine: -1
    SinkLine: 15
    Comment: 错误的移位操作
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Perform a left shift of `val` when `sh_a` is 32 or greater; otherwise return `val` unchanged.
 *
 * @param val Integer value to (possibly) shift.
 * @param sh_a Shift amount; if `sh_a < 32` the function returns `val` unchanged, otherwise the function returns `val` left-shifted by `sh_a`.
 * @returns `val` if `sh_a < 32`; otherwise the result of `val << sh_a` (this result may be undefined if `sh_a` is outside the valid shift range for `int` on the platform).
 */
int BAD_SHIFT_BAD(int val, int sh_a) 
{
    if(sh_a < 32) return val;
    return (val << sh_a);   //  缺陷点：移位操作超出了操作数范围 | 位移量可能为负数
}

/**
 * Perform a left bitwise shift of `val` by `sh_a` when `sh_a` is between 0 and 31 (inclusive of 0, exclusive of 32).
 *
 * @param val Integer value to shift.
 * @param sh_a Number of bit positions to shift; valid range is 0..31.
 * @returns The result of `val << sh_a` when `0 <= sh_a < 32`, otherwise returns `val` unchanged.
 */
int BAD_SHIFT_GOOD(int val, int sh_a) 
{
    if(sh_a >= 32 || sh_a < 0) return val;
    return (val << sh_a);   //  修复点：位移操作前做了检查
}