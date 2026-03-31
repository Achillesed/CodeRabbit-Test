/**
    Filename: INIT_THREAD_BY_THREAD_S.c
    Vuln: INIT_THREAD_BY_THREAD_S
    SourceLine: -1
    SinkLine: 15
    Comment: Rule 22.14 (强制) 线程同步对象在访问之前应先初始化 [MISRAC2012-RULE_22_14]
*/
#include <pthread.h>

pthread_t thread;
pthread_mutex_t mutex1, mutex2;           

void *foo( void* ignore )
{
    pthread_mutex_init(&mutex1, NULL); // 违规点：在线程入口函数内初始化线程
    return 0;
}

void *foo2( void* ignore )
{             
    return 0;
}


void INIT_THREAD_BY_THREAD_S_BAD()
{
    pthread_create(&thread, NULL, &foo, NULL);
    // ...
}

void INIT_THREAD_BY_THREAD_S_GOOD()
{
    pthread_mutex_init(&mutex2, NULL);   //修复点：在创建的线程外初始化线程同步对象
    pthread_create(&thread, NULL, &foo2, NULL);
    // ...
}