/**
    Filename: UNUSED_VALUE_S.c
    Vuln: UNUSED_VALUE_S
    SourceLine: -1
    SinkLine: 17
    Comment: 变量赋值未使用
*/

#include <stdio.h>
#include <stdlib.h>
int getValue();
int getNewBuffer(int);
/**
 * Illustrates overwriting a previously assigned value before it is used.
 *
 * @returns The integer result produced by the final assignment (the value returned by getNewBuffer).
 */
int UNUSED_VALUE_S_BAD() 
{
    int r;
    int buf = 16;
    r = getValue();  //缺陷点：变量 r 赋值 getName() 返回值 在未使用前就被 r = getNewBuffer(buf) 赋值覆盖
    r = getNewBuffer(buf);
    return r;
}

/**
 * Preserve an initially retrieved value before overwriting and return the final buffer value.
 *
 * @returns The integer value stored in `r` after it is overwritten (the final buffer value).
 */
int UNUSED_VALUE_S_GOOD() 
{
    int r;
    int buf = 16;
    r = getValue();      //修复点
    int a = r;
    r = getNewBuffer(buf);
    return r;
}
