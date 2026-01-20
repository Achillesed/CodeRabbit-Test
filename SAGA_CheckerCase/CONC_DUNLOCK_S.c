/**
    Filename: CONC_DUNLOCK_S.c
    Vuln: CONC_DUNLOCK_S
    SourceLine: -1
    SinkLine: 21
    Comment: 锁定不当——双重解锁
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t* mutex;
void CONC_DUNLOCK_S_BAD(int a) 
{
    for (int i = 0; i < a; i++) 
    {
        pthread_mutex_lock(mutex);
        // ...
        pthread_mutex_unlock(mutex);
    }
    pthread_mutex_unlock(mutex); //缺陷点：mutex 双重解锁
}

void CONC_DUNLOCK_S_GOOD(int a) 
{
    for (int i = 0; i < a; i++) 
    {
        pthread_mutex_lock(mutex);
        // ...
        pthread_mutex_unlock(mutex);    //修复点
    }
}