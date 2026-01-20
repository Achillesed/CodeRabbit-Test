/**
    Filename: DEAD_MUTEX_S_GOOD.c
    Vuln: DEAD_MUTEX_S
    SourceLine: -1
    SinkLine: -1
    Comment: Dir 5.2 (必需) 线程之间不应有死锁 [MISRAC2012-DIR_5_2]
*/
#include <pthread.h>

pthread_mutex_t* lock1;
pthread_mutex_t* lock2;
int v1;
int v2;

void takeLocksA(pthread_mutex_t* a, pthread_mutex_t* b) {
    pthread_mutex_lock(a);
    v1++;
    pthread_mutex_lock(b);
    v2++;
    pthread_mutex_unlock(b);
    pthread_mutex_unlock(a);
}

void takeLocksB(pthread_mutex_t* a, pthread_mutex_t* b) {
    pthread_mutex_lock(b);
    v2++;
    pthread_mutex_lock(a);
    v1++;
    pthread_mutex_unlock(a);
    pthread_mutex_unlock(b);
}

void DEAD_MUTEX_S_GOOD1() {
    takeLocksB(lock1, lock2);   //修复点1
}

void DEAD_MUTEX_S_GOOD2() {
    takeLocksA(lock2, lock1);   //修复点2
}

