/**
    Filename: BAD_COMPARE_STR_S.c
    Vuln: BAD_COMPARE_STR_S
    SourceLine: -1
    SinkLine: 15
    Comment: 指针与字符串常量做了比较
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Compare the pointer value of `other` with the string literal "expected" and execute the conditional block if they are the same address.
 *
 * This performs an address (pointer) comparison against the literal rather than comparing string contents.
 * @param other Pointer to a NUL-terminated string to compare. 
 */
void BAD_COMPARE_STR_S_GOOD(const char *other) 
{
    if(other == "expected")     //缺陷点：指针（地址）与字符串常量作比较
    {
        /* do something */
    }
}

/**
 * Check whether `other` equals "expected" and execute action if equal.
 *
 * Compares the content of `other` to the string literal "expected" using `strcmp`
 * and enters the conditional block if they are equal.
 *
 * @param other Input string to compare against "expected".
 */
void BAD_COMPARE_STR_S_BAD(const char *other) 
{
    if(strcmp(other, "expected") == 0)     //修复点：使用 strcmp 函数比较字符串内容
    {
        /* do something */
    }
}