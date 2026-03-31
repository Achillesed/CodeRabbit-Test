/**
    Filename: DEAD_MUTEX_S_BAD.c
    Vuln: DEAD_MUTEX_S
    SourceLine: -1
    SinkLine: 34
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

void DEAD_MUTEX_S_BAD1() {
    takeLocksB(lock1, lock2);   //缺陷点1：死锁路径1
}

void DEAD_MUTEX_S_BAD2() {
    takeLocksA(lock1, lock2);   //缺陷点2：死锁路径2
}

