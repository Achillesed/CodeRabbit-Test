/**
    Filename: MISSING_PRINTF_ARGS.c
    Vuln: MISSING_PRINTF_ARGS
    SourceLine: -1
    SinkLine: 18
    Comment: 缺少 printf 格式说明符的参数
*/

#include <stdio.h>

/**
 * Demonstrates insecure use of printf by providing a format specifier without its matching argument.
 *
 * Calls printf with the format string "Name %s" but does not supply the required argument for `%s`,
 * which can cause undefined behavior.
 *
 * @returns 0
 */
int MISSING_PRINTF_ARGS_BAD() 
{
    char* name = "Alice";
    int age = 30;
    printf("Name %s"); //缺陷点：缺少了一个 %s 对 name 参数的格式说明符
    return 0;
}

/**
 * Demonstrates correct usage of printf by printing a name with the matching "%s" format specifier.
 *
 * Prints "Name Alice" to standard output.
 * @returns 0 on success.
 */
int MISSING_PRINTF_ARGS_GOOD() 
{
    char* name = "Alice";
    int age = 30;
    printf("Name %s", name); //修复点：添加 %s 对 name 参数的格式说明符
    return 0;
}