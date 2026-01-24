/**
    Filename: DYN_CREATE_THREAD_S.c
    Vuln: DYN_CREATE_THREAD_S
    SourceLine: -1
    SinkLine: 21
    Comment: Dir 5.3 (必需) 不应创建任何动态线程 [MISRAC2012-DIR_5_3]
*/
#include <pthread.h>

pthread_t thread1, thread2;

void *fun02( void* ignore )
{
    // ...
    return 0;
}

void *fun01( void* ignore )
{
    // ...
    pthread_create(&thread2, NULL, &fun02, NULL); // 违规点：线程 thread2 被另一个线程入口点函数 fun01 线程 thread1 创建
    return 0;
}

int DYN_CREATE_THREAD_S_BAD(void)
{
    pthread_create(&thread1, NULL, &fun01, NULL);
    return 0;
}

void *fun03( void* ignore )
{
    // ...
    return 0;
}

pthread_t thread3;
int DYN_CREATE_THREAD_S_GOOD(void)
{
    pthread_create(&thread3, NULL, &fun03, NULL); // 修复点：线程入口点函数 fun03 未创建线程
    return 0;
}