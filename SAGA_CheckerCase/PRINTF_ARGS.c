/**
    Filename: PRINTF_ARGS.c
    Vuln: PRINTF_ARGS
    SourceLine: -1
    SinkLine: 14
    Comment: Printf 格式说明符的参数中的无效类型
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates printing a long long value using an incorrect printf format specifier.
 * This function intentionally uses a mismatched format specifier for testing/demonstration.
 * @param l_val The long long value passed to printf.
 */
void PRINTF_ARGS_BAD(long long l_val) 
{
    printf("%d\n", l_val);  //缺陷点：long long 应 为 %lld 格式说明符
}

/**
 * Print a long long value to standard output using the correct printf format.
 *
 * @param l_val The long long value to print.
 */
void PRINTF_ARGS_GOOD(long long l_val) 
{
    printf("%lld\n", l_val);  //修复点
}