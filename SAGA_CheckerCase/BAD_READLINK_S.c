/**
    Filename: BAD_READLINK_S.c
    Vuln: BAD_READLINK_S
    SourceLine: -1
    SinkLine: 18
    Comment: 不安全地使用了 Readlink
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * Demonstrates unsafe usage of readlink by writing a terminator without validating the returned length.
 *
 * Calls `readlink` into a 128-byte stack buffer and unconditionally writes a NUL at `buff[len]`,
 * which can result in an out-of-bounds write or use of an invalid index if `readlink` returns -1
 * or a value not less than the buffer size.
 */
void BAD_READLINK_S_BAD() 
{
    int len;
    char buff[128];
    char *link = malloc(sizeof(char));
    if(!link) return;
    len = readlink(link, buff, sizeof(buff));
    buff[len] = 0;          //缺陷点：未检查 readlink 返回值就进行使用
    free(link);
}

/**
 * Safely reads a symbolic link target into a fixed-size buffer and null-terminates it when safe.
 *
 * Calls readlink with a 128-byte destination buffer and, if the returned length is not -1
 * and is less than the buffer size, writes a terminating NUL at buff[len]. Allocated link
 * memory is freed before the function returns.
 */
void BAD_READLINK_S_GOOD() 
{
    int len;
    char buff[128];
    char *link = malloc(sizeof(char));
    if(!link) return;
    len = readlink(link, buff, sizeof(buff));
    if(len != -1 && len < sizeof(buff))
    {
        buff[len] = 0;   //修复点：使用 readlink 返回值前进行了检查
    }
    free(link);
}