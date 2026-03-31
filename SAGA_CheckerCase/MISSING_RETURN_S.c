/**
    Filename: MISSING_RETURN_S.c
    Vuln: MISSING_RETURN_S
    SourceLine: -1
    SinkLine: 18
    Comment: 缺少 return 语句
*/

#include <stdio.h>
#include <stdlib.h>

int MISSING_RETURN_S_BAD(int x) 
{
    if (x == 5)
    {
        return 4;
    }
    else if (x == 3)
    {
        return 2;
    }
}       //缺陷点：此函数存在分支缺少 return

int MISSING_RETURN_S_GOOD(int x) 
{
    if (x == 5)
    {
        return 4;
    }
    else if (x == 3)
    {
        return 2;
    }
    return 0;
}       //修复点：此函数无分支缺少 return