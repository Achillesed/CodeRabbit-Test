/**
    Filename: USELESS_CALL_S.c
    Vuln: USELESS_CALL_S
    SourceLine: -1
    SinkLine: 28
    Comment: 无用的调用
*/

#include<stdio.h>
//Cov官网样例
typedef struct 
{
    int x;
    int y;    
} pair_t;

pair_t swap(pair_t xy)
{
    pair_t swapped;
    swapped.x = xy.y;
    swapped.y = xy.x;
    return swapped;
}

void USELESS_CALL_S_BAD()
{
    pair_t xy = {1,2};
    swap(xy);   //缺陷点：函数swap调用仅对已忽略的其返回值有用
}

void USELESS_CALL_S_GOOD()
{
    pair_t xy = {1,2};
    xy = swap(xy);   //修复点
}


