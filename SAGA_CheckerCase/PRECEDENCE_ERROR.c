/**
    Filename: PRECEDENCE_ERROR.c
    Vuln: PRECEDENCE_ERROR
    SourceLine: -1
    SinkLine: 14
    Comment: 运算符优先逻辑错误
*/


#include <stdio.h>
#include <stdbool.h>
/**
 * Evaluate the expression `a + b & c` as parsed by C operator precedence.
 *
 * @param a Integer addend.
 * @param b Boolean operand (promoted to `int`, 0 or 1) used in the addition and bitwise operation.
 * @param c Boolean operand (promoted to `int`, 0 or 1) used as the right-hand operand of `&`.
 * @returns The integer result of the expression `(a + b) & c` according to C operator precedence.
 */
int PRECEDENCE_ERROR_BAD(int a, bool b, bool c) 
{
    return  a + b & c;
}

/**
 * Compute the sum of `a` and the bitwise AND of `b` and `c`.
 * @param a Integer value to which the bitwise result is added.
 * @param b Boolean operand for the bitwise AND.
 * @param c Boolean operand for the bitwise AND.
 * @returns The integer result equal to a + (b & c).
 */
int PRECEDENCE_ERROR_GOOD(int a, bool b, bool c) 
{
    return  a + (b & c);
}