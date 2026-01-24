/**
    Filename: CHECKED_RETURN_S.c
    Vuln: CHECKED_RETURN_S
    SourceLine: -1
    SinkLine: 16
    Comment: 来自库函数的未检查返回值
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int CHECKED_RETURN_S_BAD()
{
    pthread_cond_t cond;
    pthread_cond_init(&cond, NULL); //缺陷点：未检查特定库函数返回值
    /* do something */
    return 0;
}

int CHECKED_RETURN_S_GOOD()
{
    pthread_cond_t cond;
    if(pthread_cond_init(&cond, NULL) != 0)     //修复点：检查操作
    {
        return -1;
    }
    /* do something */
    return 0;
}