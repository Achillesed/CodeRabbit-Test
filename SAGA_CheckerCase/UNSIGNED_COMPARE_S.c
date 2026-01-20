/**
    Filename: UNSIGNED_COMPARE_S.c
    Vuln: UNSIGNED_COMPARE_S
    SourceLine: -1
    SinkLine: 15
    Comment: 无符号值与 0 做了比较
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates an incorrect comparison of an unsigned value with zero.
 *
 * The function performs a comparison `what < 0` on an unsigned parameter; this condition is always false and the conditional block is never executed.
 *
 * @param what Unsigned integer value that is (incorrectly) compared against zero.
 */
void UNSIGNED_COMPARE_S_BAD(unsigned int what)
{
    int num = 0;
    if (what < 0)    //缺陷点：无符号值不因与 0 做 > < 比较
    {
      // do something
    }
}

/**
 * Increment a local counter when the provided unsigned value is greater than 1.
 *
 * @param what Unsigned value to test; if greater than 1 the function increments an internal local counter.
 */
void UNSIGNED_COMPARE_S_GOOD(unsigned int what)
{
    int num = 0;
    if (what > 1)    //修复点
      num += 1;
}