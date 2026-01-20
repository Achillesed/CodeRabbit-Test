/**
    Filename: TEST_NOT_ASSIGN.c
    Vuln: TEST_NOT_ASSIGN
    SourceLine: -1
    SinkLine: 16
    Comment: 测试应该赋值
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates a mistaken use of '==' where '=' (assignment) is intended.
 *
 * This test case contains an unused comparison between two integers to
 * illustrate the "not assignment" defect (the comparison result is discarded).
 */
void TEST_NOT_ASSIGN_BAD() 
{
    int a = 1;
    int b = 2;
    a == b; // 缺陷点：此处应该为赋值
}

/**
 * Assign the value of `b` to `a` to demonstrate correct assignment usage.
 */
void TEST_NOT_ASSIGN_GOOD() 
{
    int a = 1;
    int b = 2;
    a = b; // 修复点
}