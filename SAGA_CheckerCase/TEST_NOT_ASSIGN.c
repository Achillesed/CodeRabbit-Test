/**
    Filename: TEST_NOT_ASSIGN.c
    Vuln: TEST_NOT_ASSIGN
    SourceLine: -1
    SinkLine: 16
    Comment: 测试应该赋值
*/

#include <stdio.h>
#include <stdlib.h>

void TEST_NOT_ASSIGN_BAD() 
{
    int a = 1;
    int b = 2;
    a == b; // 缺陷点：此处应该为赋值
}

void TEST_NOT_ASSIGN_GOOD() 
{
    int a = 1;
    int b = 2;
    a = b; // 修复点
}