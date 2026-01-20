/**
    Filename: SELF_ASSIGN.c
    Vuln: SELF_ASSIGN
    SourceLine: -1
    SinkLine: 20
    Comment: 自赋值
*/

#include <stdio.h>
#include <stdlib.h>

struct foo 
{
    int x;
    int y;
};

void SELF_ASSIGN_BAD(struct foo *ptr)
{
    ptr->x = ptr->x; //缺陷点
}

void SELF_ASSIGN_GOOD(struct foo *ptr)
{
    ptr->x = ptr->y; //修复点
}