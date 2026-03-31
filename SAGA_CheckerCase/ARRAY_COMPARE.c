/**
    Filename: ARRAY_COMPARE.c
    Vuln: ARRAY_COMPARE
    SourceLine: -1
    SinkLine: 19
    Comment: 数组与 0 做了比较
*/

#include <stdio.h>
#include <stdlib.h>

void ARRAY_COMPARE_BAD() 
{
    unsigned int a[3] = {0};
    unsigned int b[1] = {0};
    unsigned int c[2] = {0};
    if(*a == 0) 
        a[0] = 1;
    if(b == 0)  //  缺陷点：使用数组首地址与0作比较
        b[0] = 10;  
}

void ARRAY_COMPARE_GOOD() 
{
    unsigned int a[3] = {0};
    unsigned int b[1] = {0};
    unsigned int c[2] = {0};
    if(*a == 0) 
        a[0] = 1;
    if(*b == 0)  //  修复点：使用数组首元素与0作比较
        b[0] = 10;  
}