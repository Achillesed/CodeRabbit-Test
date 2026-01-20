/**
    Filename: DANGERFUNC_MUST_S.c
    Vuln: DANGERFUNC_MUST_S
    SourceLine: -1
    SinkLine: 18
    Comment: 使用危险函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 16

char *gets(char*);
/**
 * Demonstrates unsafe input reading into a fixed-size stack buffer using `gets`.
 *
 * This function reads data from standard input into a 16-byte local buffer with no
 * bounds checking; doing so can cause a buffer overflow and undefined behavior.
 */
void DANGERFUNC_MUST_S_BAD()
{
    char buf[BUFSIZE];
    gets(buf);      //缺陷点
}

/**
 * Read input from standard input into a local buffer while preventing buffer overflow.
 *
 * Reads up to sizeof(buf) - 1 characters from stdin, stores a NUL-terminated string in buf,
 * and retains a trailing newline if present.
 */
void DANGERFUNC_MUST_S_GOOD()
{
    char buf[BUFSIZE];
    fgets(buf,sizeof(buf),stdin);     //修复点
}