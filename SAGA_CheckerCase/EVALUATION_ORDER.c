/**
    Filename: EVALUATION_ORDER.c
    Vuln: EVALUATION_ORDER
    SourceLine: -1
    SinkLine: 15
    Comment: 评估顺序冲突
*/

#include <stdio.h>
#include <stdlib.h>

int EVALUATION_ORDER_BAD(int x) 
{
    int a = x * x;
    a = x > 0 ? a++ : 0;  //缺陷点：无法确定执行顺序
    return a + a;
}

int EVALUATION_ORDER_GOOD(int x) 
{
    int a = x * x;
    if(x > 0)
    {
        a++;        //修复点：明确执行顺序
    }
    else
    {
        a = 0;
    }
    return a + a;
}