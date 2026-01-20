/**
    Filename: BAD_COMPARE_MEMCMP_S.c
    Vuln: BAD_COMPARE_MEMCMP_S
    SourceLine: -1
    SinkLine: 15
    Comment: 滥用了 memcmp 风格函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Illustrates an incorrect comparison of two strings using strcmp.
 *
 * This function calls strcmp(s, "blah") and enters the if-block only when the
 * result is equal to 1, which is a flawed assumption about memcmp/strcmp
 * semantics (these functions return a value greater than, equal to, or less
 * than zero to indicate ordering).
 *
 * @param s Null-terminated string to compare against the literal "blah".
 */
void BAD_COMPARE_MEMCMP_S_BAD(const char *s) 
{
    if (strcmp(s, "blah") == 1)     //缺陷点：错误的认为 memcmp 类函数返回值为定值
    {
        /* do something */
    }
}

/**
 * Execute a placeholder action when the input string is lexicographically greater than "blah".
 *
 * @param s Null-terminated string to compare against "blah".
 */
void BAD_COMPARE_MEMCMP_S_GOOD(const char *s) 
{
    if (strcmp(s, "blah") > 0)      //修复点：memcmp 类函数返回值应为正数情况
    {
        /* do something */
    }
}