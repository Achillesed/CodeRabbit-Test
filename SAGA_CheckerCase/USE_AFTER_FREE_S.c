/**
    Filename: USE_AFTER_FREE_S.c
    Vuln: USE_AFTER_FREE_S
    SourceLine: -1
    SinkLine: 25
    Comment: 释放后使用
*/

#include <stdio.h>
#include <stdlib.h>

struct data 
{
    int value;
};

int USE_AFTER_FREE_S_BAD()
{
    struct data *p = (struct data *)malloc(sizeof(struct data));
    if(!p) return -1;
    p->value = 42;
    //do something
    free(p);
    //do something
    p->value = 100;   //缺陷点：使用已释放指针
    return 0;
}

int USE_AFTER_FREE_S_GOOD()
{
    struct data *p = (struct data *)malloc(sizeof(struct data));
    if(!p) return -1;
    p->value = 42;
    //do something
    free(p);  //修复点
    return 0;
}