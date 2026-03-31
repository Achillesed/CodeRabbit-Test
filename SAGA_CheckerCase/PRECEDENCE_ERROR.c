/**
    Filename: PRECEDENCE_ERROR.c
    Vuln: PRECEDENCE_ERROR
    SourceLine: -1
    SinkLine: 14
    Comment: 运算符优先逻辑错误
*/


#include <stdio.h>
#include <stdbool.h>
int PRECEDENCE_ERROR_BAD(int a, bool b, bool c) 
{
    return  a + b & c;
}

int PRECEDENCE_ERROR_GOOD(int a, bool b, bool c) 
{
    return  a + (b & c);
}