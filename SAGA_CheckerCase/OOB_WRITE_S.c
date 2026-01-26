/**
    Filename: OOB_WRITE_S.c
    Vuln: OOB_WRITE_S
    SourceLine: -1
    SinkLine: 20
    Comment: 越界写入
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 8
int getValue();
/**
 * Demonstrates a conditional write to a local buffer that can go out of bounds.
 *
 * If the externally provided index equals SZ + SZ, the write to b[i] exceeds
 * the buffer's valid range and induces an out-of-bounds write.
 *
 * @returns 0
 */
int OOB_WRITE_S_BAD()
{
    char b[SZ + SZ] = {0};
    int i = getValue();
    if(0 < i && i <= SZ + SZ)
    {
        b[i] = 1; // 缺陷点：i 可能取最大值为 SZ + SZ，此时 b[i] 越界
    }
    return 0;
}

/**
 * Write 1 into a local buffer at the index returned by getValue when that index is strictly within the buffer bounds.
 *
 * Ensures the index i satisfies 0 < i < SZ + SZ before writing to avoid an out-of-bounds write.
 *
 * @returns 0 indicating successful completion.
 */
int OOB_WRITE_S_GOOD()
{
    char b[SZ + SZ] = {0};
    int i = getValue();
    if(0 < i && i < SZ + SZ)
    {
        b[i] = 1; // 修复点：i 可能取最大值为 SZ + SZ -1，此时 b[i] 不越界
    }
    return 0;
}