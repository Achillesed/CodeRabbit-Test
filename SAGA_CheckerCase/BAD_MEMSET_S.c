/**
    Filename: BAD_MEMSET_S.c
    Vuln: BAD_MEMSET_S
    SourceLine: -1
    SinkLine: 15
    Comment: Memset 调用错误
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Demonstrates an incorrect memset usage that attempts to zero a buffer.
 *
 * This function calls memset with a size of 0; as a result no bytes of `buf` are set to zero.
 *
 * @param buf Buffer intended to be initialized.
 */
void BAD_MEMSET_S_BAD(char *buf) 
{ 
    memset(buf, 0, 0);  //缺陷点：缓冲区初始化大小为 0
}

/**
 * Zeroes the memory starting at buf for sizeof(buf) bytes.
 *
 * @param buf Pointer to the memory to set to zero. The function writes sizeof(buf) bytes (the size of the pointer) beginning at this address.
 */
void BAD_MEMSET_S_GOOD(char *buf) 
{ 
    memset(buf, 0, sizeof(buf));    //修复点
}