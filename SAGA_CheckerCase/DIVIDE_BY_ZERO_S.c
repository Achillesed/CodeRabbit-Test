/**
    Filename: DIVIDE_BY_ZERO_S.c
    Vuln: DIVIDE_BY_ZERO_S
    SourceLine: -1
    SinkLine: 24
    Comment: 除零错误
*/

#include <stdio.h>
#include <stdlib.h>
int getvalue();
void DIVIDE_BY_ZERO_S_BAD()
{
    int a = getvalue();
    if (a == 0)
    {
        /* do something */
    }
    else
    {
        /* do something */
    }
    printf("%d\n", 10 / a); //缺陷点：15行 'a == 0'说明 a 在此分支可能为 0
}

void DIVIDE_BY_ZERO_S_GOOD()
{
    int a = getvalue();
    if (a == 0)
    {
        /* do something */
    }
    else
    {
        /* do something */
        printf("%d\n", 10 / a); //修复点：在此分支 a != 0
    }
}