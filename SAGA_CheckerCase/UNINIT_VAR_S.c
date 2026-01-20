/**
    Filename: UNINIT_VAR_S.c
    Vuln: UNINIT_VAR_S
    SourceLine: -1
    SinkLine: 19
    Comment: 使用未初始化变量
*/
#include <stdio.h>
#include <stdlib.h>
int getValue();

/**
 * Demonstrates returning a local variable that may remain uninitialized when the input is non‑positive.
 *
 * @param flag Integer used to conditionally initialize the return value; when greater than zero it is assigned to the returned variable.
 * @returns The value of the local variable `ret`: equal to `flag` when `flag > 0`, otherwise an indeterminate (uninitialized) integer value.
 */
int UNINIT_VAR_S_BAD(int flag) 
{
    int ret;
    if (flag > 0) 
    {
        ret = flag;
    } 
    return ret;   //缺陷点：ret 变量未初始化
}

/**
 * Provide a value initialized from getValue and override it with flag when flag is greater than zero.
 *
 * @param flag If greater than zero, the function returns flag; otherwise the initial value from getValue() is used.
 * @returns The integer result: flag if flag > 0, otherwise the initial value obtained from getValue().
 */
int UNINIT_VAR_S_GOOD(int flag) 
{
    int ret = getValue();
    if (flag > 0) 
    {
        ret = flag;
    } 
    return ret;   //修复点
}
