#include <math.h>

/**
 * Return zero.
 *
 * @returns 0.0
 */
double returnZero()
{
    return 0.0;
}

/**
 * Demonstrates unsafe computation of the natural logarithm on zero.
 *
 * Calls `log` on a value equal to 0.0 without validation, producing a non‑finite floating-point result.
 */
void FLOAT_NAN_S_BAD(){
    double value = returnZero();
    double result = log(value); // 违规
}

/**
 * Safely computes the natural logarithm of a value only when that value is greater than 0.
 *
 * If the value is less than or equal to 0, the function does not call log and performs no action,
 * avoiding NaN or domain errors from invalid log inputs.
 */
void FLOAT_NAN_S_GOOD(){
    double value = returnZero();
    if(value > 0.0)
    {
        double result = log(value);  // 不违规
    }
}