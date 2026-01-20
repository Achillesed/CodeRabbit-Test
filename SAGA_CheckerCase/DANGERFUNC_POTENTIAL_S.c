/**
    Filename: DANGERFUNC_POTENTIAL_S.c
    Vuln: DANGERFUNC_POTENTIAL_S
    SourceLine: -1
    SinkLine: 16
    Comment: 使用具有潜在危险的函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Copy the provided C-string into a fixed 24-byte local buffer without bounds checking.
 *
 * Copies the contents of `string` into an internal 24-byte array using an unsafe operation.
 * If `string` has length greater than or equal to 24, this may overwrite adjacent memory and cause undefined behavior.
 * @param string Null-terminated source string to copy into the local buffer.
 */
void DANGERFUNC_POTENTIAL_S_BAD(char *string)
{
    char buf[24];
    strcpy(buf, string); // 缺陷点
}

/**
 * Copy up to 23 characters from the provided string into a local 24-byte buffer and ensure the result is null-terminated to mitigate buffer overflow.
 * @param string Source null-terminated string to copy from; may be longer than 23 bytes.
 */
void DANGERFUNC_POTENTIAL_S_GOOD(char *string)
{
    char buf[24];
    strncpy(buf, string, 23); // 修复点：使用 strncpy 替换，并手动添加字符串结尾符
    buf[23] = '\0';
}