/**
    Filename: RACE_CONDITION_WITHIN_THREAD_S.c
    Vuln: RACE_CONDITION_WITHIN_THREAD_S
    SourceLine: -1
    SinkLine: 23
    Comment: Dir 5.1 (必需) 线程之间不应存在数据争用 [MISRAC2012-DIR_5_1]
*/
#include <pthread.h>
pthread_t thread1, thread2;

int x;
void *fun02( void* ignore )
{
    int a;
    x = 1;      //缺陷点
    a = 1;
    // ...
    return 0;
}

void *fun01( void* ignore )
{
    x = 2;      //缺陷点
    // ...
    return 0;
}

int DYN_CREATE_THREAD_S_BAD(void)
{
    pthread_create(&thread1, NULL, &fun01, NULL);
    pthread_create(&thread2, NULL, &fun02, NULL);
    return 0;
}

pthread_t thread3, thread4;
int y;
pthread_mutex_t* mutex;
void *fun03( void* ignore )
{
    // ...
    pthread_mutex_lock(mutex);
    y = 3;      //修复点
    pthread_mutex_unlock(mutex);
    return 0;
}

void *fun04( void* ignore )
{
    // ...
    pthread_mutex_lock(mutex);
    y = 4;      //修复点
    pthread_mutex_unlock(mutex);
    return 0;
}

int DYN_CREATE_THREAD_S_GOOD(void)
{
    pthread_create(&thread3, NULL, &fun03, NULL);
    pthread_create(&thread4, NULL, &fun04, NULL);
    return 0;
}