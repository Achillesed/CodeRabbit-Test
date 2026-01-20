/**
    Filename: OVERLAPPING_COPY_S.c
    Vuln: OVERLAPPING_COPY_S
    SourceLine: -1
    SinkLine: 16
    Comment: 分配重叠内存
*/

#include <string.h>
#define SZ 10

/**
 * Demonstrates an unsafe overlapping memory copy using memcpy.
 *
 * Copies 3 bytes from a+2 into a, causing the source and destination regions to overlap
 * and resulting in undefined behavior and potential data corruption.
 */
void OVERLAPPING_COPY_S_BAD()
{
    char a[SZ] = "abcdefg";
    char * b = a + 2;
    memcpy(a, b, 3);   //缺陷点：从 b 开始拷贝3个字节到 a，拷贝内容会覆盖 b 本身
}

/**
 * Copy three bytes from a later position in the buffer into its start without overlapping the source.
 *
 * Copies 3 bytes from the array `a` starting at offset 3 into the beginning of `a`. The source and
 * destination ranges do not overlap, so the copy does not invoke undefined behavior associated with
 * overlapping memory regions when using `memcpy`.
 */
void OVERLAPPING_COPY_S_GOOD()
{
    char a[SZ] = "abcdefg";
    char * b = a + 3;
    memcpy(a, b, 3);   //修复点：此时拷贝内容不会覆盖 b 本身
}


