/**
    Filename: ASSERT_EFFECT.c
    Vuln: ASSERT_EFFECT
    SourceLine: -1
    SinkLine: 16
    Comment: 断言中的其他作用
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int getValue();
/**
 * Demonstrates an unsafe modification performed inside an assertion.
 *
 * Calls getValue(), then increments the retrieved value inside the assertion
 * expression. If the assertion fails the program aborts. When assertions are
 * disabled (for example by defining NDEBUG), the increment does not occur.
 */
void ASSERT_EFFECT_BAD() 
{
    int x = getValue();
    assert(++x);        // 缺陷点：在断言中进行修改操作
}

/**
 * Assert that the value returned by getValue() plus one is non-zero, performing the increment before the assertion.
 *
 * This function retrieves an integer from getValue(), computes x + 1 into a temporary variable, and asserts that the result is non-zero to avoid side effects inside the assertion expression.
 */
void ASSERT_EFFECT_GOOD() 
{
    int x = getValue();
    int temp = x + 1;
    assert(temp);        // 修复点：在断言前提前修改
}