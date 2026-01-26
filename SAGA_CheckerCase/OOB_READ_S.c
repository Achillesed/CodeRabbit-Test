/**
    Filename: OOB_READ_S.c
    Vuln: OOB_READ_S
    SourceLine: -1
    SinkLine: 22
    Comment: 越界读取
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 8

int getValue();
/**
 * Reads a byte from a fixed-size local buffer using an index obtained from getValue,
 * illustrating an out-of-bounds read when the index equals SZ + SZ.
 *
 * @return The byte read from the buffer converted to `int` if the index check passes, `0` if the index check fails.
 *         May cause undefined behavior when the retrieved index equals `SZ + SZ` due to an out-of-bounds access.
 */
int OOB_READ_S_BAD()
{
    char a[SZ + SZ] = {0};
    int i = getValue();
    int p;
    if(0 < i && i <= SZ + SZ)
    {
        p = a[i]; // 缺陷点：i 可能取最大值为 SZ + SZ，此时 a[i] 越界

        return p;
    }
    return 0;
}

/**
 * Read a byte from a local buffer at the index supplied by getValue(), ensuring the index is within bounds.
 *
 * @returns The buffer byte at index `i` when `0 < i < SZ + SZ`, or `0` if `i` is out of range.
 */
int OOB_READ_S_GOOD()
{
    char a[SZ + SZ] = {0};
    int i = getValue();
    int p;
    if(0 < i && i < SZ + SZ)
    {
        p = a[i]; // 修复点：i 可能取最大值为 SZ + SZ -1，此时 a[i] 不越界

        return p;
    }
    return 0;
}