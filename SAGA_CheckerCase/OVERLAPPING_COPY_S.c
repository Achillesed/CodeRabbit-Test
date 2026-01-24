/**
    Filename: OVERLAPPING_COPY_S.c
    Vuln: OVERLAPPING_COPY_S
    SourceLine: -1
    SinkLine: 16
    Comment: 分配重叠内存
*/

#include <string.h>
#define SZ 10

void OVERLAPPING_COPY_S_BAD()
{
    char a[SZ] = "abcdefg";
    char * b = a + 2;
    memcpy(a, b, 3);   //缺陷点：从 b 开始拷贝3个字节到 a，拷贝内容会覆盖 b 本身
}

void OVERLAPPING_COPY_S_GOOD()
{
    char a[SZ] = "abcdefg";
    char * b = a + 3;
    memcpy(a, b, 3);   //修复点：此时拷贝内容不会覆盖 b 本身
}



