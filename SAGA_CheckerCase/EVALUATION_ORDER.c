/**
    Filename: EVALUATION_ORDER.c
    Vuln: EVALUATION_ORDER
    SourceLine: -1
    SinkLine: 15
    Comment: 评估顺序冲突
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Illustrates an evaluation-order defect by computing and returning twice a value derived from `x`.
 *
 * The expression `a = x > 0 ? a++ : 0` modifies `a` and assigns to `a` in the same full expression,
 * creating unspecified/undefined behavior when `x > 0` due to the lack of a sequencing guarantee.
 *
 * @param x Input integer used to initialize `a` (as `x * x`) and to select the conditional branch.
 * @returns The value of `a + a` after the conditional assignment; the result is undefined when `x > 0`
 *          because the conditional uses `a++` and assigns to `a` within the same expression.
 */
int EVALUATION_ORDER_BAD(int x) 
{
    int a = x * x;
    a = x > 0 ? a++ : 0;  //缺陷点：无法确定执行顺序
    return a + a;
}

/**
 * Compute twice a value derived from x with a well-defined evaluation order.
 *
 * If x > 0, `a` is initialized to x*x and then incremented; otherwise `a` is set to 0.
 * The function returns the sum of `a` with itself.
 *
 * @param x Input integer used to compute the initial value of `a`.
 * @returns The value `a + a`, where `a` is `x*x + 1` when x > 0, or `0` when x <= 0.
 */
int EVALUATION_ORDER_GOOD(int x) 
{
    int a = x * x;
    if(x > 0)
    {
        a++;        //修复点：明确执行顺序
    }
    else
    {
        a = 0;
    }
    return a + a;
}