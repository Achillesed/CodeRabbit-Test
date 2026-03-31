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