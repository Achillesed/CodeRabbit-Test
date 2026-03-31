/**
    Filename: RECURSIVE_LOCK_S.c
    Vuln: RECURSIVE_LOCK_S
    SourceLine: -1
    SinkLine: 24
    Comment: Rule 22.18 (必需) 非递归 mutex 不得递归锁定 [MISRAC2012-RULE_22_18]
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

pthread_mutex_t* mutex;

bool preconditionHolds() {
    // ...
    return true;
}

void exclusivelyCompute_bad()
{
    pthread_mutex_lock(mutex);
    if (preconditionHolds()) {
        /* perform some computations */
        exclusivelyCompute_bad();   // 违规点: 递归调用将导致双重锁定
    }
    pthread_mutex_unlock(mutex);
}

void RECURSIVE_LOCK_S_BAD()
{
    mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, NULL);
    exclusivelyCompute_bad();
    pthread_mutex_destroy(mutex);
    free(mutex);
}

static void nonexclusivelyCompute()
{
    if (preconditionHolds()) {
        /* perform some computations */
        nonexclusivelyCompute(); // 修复: 只进行一次加锁
    }
}

void exclusivelyCompute_good()
{
    pthread_mutex_lock(mutex);
    nonexclusivelyCompute();
    pthread_mutex_unlock(mutex);
}

void RECURSIVE_LOCK_S_GOOD()
{
    mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, (const pthread_mutexattr_t*)0);
    exclusivelyCompute_good();
    free(mutex);
}
