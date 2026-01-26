/**
    Filename: ARRAY_COMPARE.c
    Vuln: ARRAY_COMPARE
    SourceLine: -1
    SinkLine: 19
    Comment: 数组与 0 做了比较
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates an incorrect comparison where an array identifier is compared to 0 instead of its element.
 *
 * Initializes three arrays and sets a[0] to 1 when its first element equals 0. The second conditional mistakenly
 * compares the array name `b` (pointer) to 0, so its assignment is not executed and `b[0]` remains 0.
 */
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

/**
 * Update the first elements of two local arrays when they are zero.
 *
 * If a[0] equals 0, sets a[0] to 1. If b[0] equals 0, sets b[0] to 10.
 */
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