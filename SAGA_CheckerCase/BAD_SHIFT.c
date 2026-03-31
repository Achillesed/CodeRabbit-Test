/**
    Filename: BAD_SHIFT.c
    Vuln: BAD_SHIFT
    SourceLine: -1
    SinkLine: 15
    Comment: 错误的移位操作
*/

#include <stdio.h>
#include <stdlib.h>

int BAD_SHIFT_BAD(int val, int sh_a) 
{
    if(sh_a < 32) return val;
    return (val << sh_a);   //  缺陷点：移位操作超出了操作数范围 | 位移量可能为负数
}

int BAD_SHIFT_GOOD(int val, int sh_a) 
{
    if(sh_a >= 32 || sh_a < 0) return val;
    return (val << sh_a);   //  修复点：位移操作前做了检查
}