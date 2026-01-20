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
