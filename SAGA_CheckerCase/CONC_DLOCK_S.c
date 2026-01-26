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
/**
 * Acquire a global mutex and then, for `a` iterations, attempt to lock and unlock it again, demonstrating an incorrect double-lock pattern.
 *
 * This function first locks the global `mutex` and then calls `pthread_mutex_lock` on the same `mutex` inside the loop before unlocking it once per iteration; the repeated locking of the same non-recursive mutex can deadlock or cause undefined behavior.
 *
 * @param a Number of iterations to perform inside the loop.
 */
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

/**
 * Perform a protected critical section for a specified number of iterations.
 *
 * Acquires the global `mutex` once per iteration, executes the critical section, and releases the mutex.
 * @param a Number of iterations to execute the protected section.
 * @note The global `mutex` must be initialized and non-NULL before calling.
 */
void CONC_DLOCK_S_GOOD(int a) 
{
    for (int i = 0; i < a; i++) 
    {
        pthread_mutex_lock(mutex);   //修复点
        // ...
        pthread_mutex_unlock(mutex);
    }
}