/**
    Filename: BAD_FLOAT_RET.c
    Vuln: BAD_FLOAT_RET
    SourceLine: -1
    SinkLine: 14
    Comment: 结果不是浮点型
*/

#include <stdio.h>
#include <stdlib.h>

int BAD_FLOAT_RET_BAD(int a, int b) 
{
    return (int)(0.5 + ((a + b) / 2)); // 缺陷点：除数和被除数都不为浮点型，结果被截断为整数，可能会丢失精度
}

int BAD_FLOAT_RET_GOOD(int a, int b) 
{
    return (int)(0.5 + ((double)a + b) / 2); // 修复点：被除数为浮点型
}
