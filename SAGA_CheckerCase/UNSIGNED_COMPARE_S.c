/**
    Filename: UNSIGNED_COMPARE_S.c
    Vuln: UNSIGNED_COMPARE_S
    SourceLine: -1
    SinkLine: 15
    Comment: 无符号值与 0 做了比较
*/

#include <stdio.h>
#include <stdlib.h>

void UNSIGNED_COMPARE_S_BAD(unsigned int what)
{
    int num = 0;
    if (what < 0)    //缺陷点：无符号值不因与 0 做 > < 比较
    {
      // do something
    }
}

void UNSIGNED_COMPARE_S_GOOD(unsigned int what)
{
    int num = 0;
    if (what > 1)    //修复点
      num += 1;
}