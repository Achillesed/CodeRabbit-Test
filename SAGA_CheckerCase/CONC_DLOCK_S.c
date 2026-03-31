/**
    Filename: CONC_DLOCK_S.c
    Vuln: CONC_DLOCK_S
    SourceLine: -1
    SinkLine: 18
    Comment: 锁定不当——双重锁定
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t* mutex;
void CONC_DLOCK_S_BAD(int a) 
{
    pthread_mutex_lock(mutex);
    for (int i = 0; i < a; i++) 
    {
        pthread_mutex_lock(mutex);      //缺陷点：mutex 双重锁定
        // ...
        pthread_mutex_unlock(mutex);
    }
}

void CONC_DLOCK_S_GOOD(int a) 
{
    for (int i = 0; i < a; i++) 
    {
        pthread_mutex_lock(mutex);   //修复点
        // ...
        pthread_mutex_unlock(mutex);
    }
}