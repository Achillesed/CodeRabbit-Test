/**
    Filename: ABUSE_COMMA.c
    Vuln: ABUSE_COMMA
    SourceLine: -1
    SinkLine: 16
    Comment: 滥用了逗号运算符
*/

#include <stdio.h>
#include <stdlib.h>

void ABUSE_COMMA_BAD()
{

    int a,b;
    for(a = 0, b = 0; a < 10, b < 10; a++, b++)   // 缺陷点:布尔表达式a < 10, b < 10中，a < 10没有意义
    {
        /* do something */
    }

}
void ABUSE_COMMA_GOOD()
{

    int a,b;
    for(a = 0, b = 0; a < 10 && b < 10; a++, b++)   // 修复点：使用逻辑运算符 && 修正布尔表达式
    {
        /* do something */
    }

}