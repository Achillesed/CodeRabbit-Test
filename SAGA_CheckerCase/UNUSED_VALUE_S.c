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
int UNUSED_VALUE_S_BAD() 
{
    int r;
    int buf = 16;
    r = getValue();  //缺陷点：变量 r 赋值 getName() 返回值 在未使用前就被 r = getNewBuffer(buf) 赋值覆盖
    r = getNewBuffer(buf);
    return r;
}

int UNUSED_VALUE_S_GOOD() 
{
    int r;
    int buf = 16;
    r = getValue();      //修复点
    int a = r;
    r = getNewBuffer(buf);
    return r;
}

