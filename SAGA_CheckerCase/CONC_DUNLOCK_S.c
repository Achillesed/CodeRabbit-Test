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
/**
 * Iterate `a` times, locking and unlocking the global `mutex` on each iteration,
 * then perform an additional unlock after the loop.
 *
 * This extra unlock after the loop can attempt to unlock `mutex` a second time,
 * causing undefined behavior (double unlock).
 *
 * @param a Number of loop iterations to perform; each iteration locks then unlocks `mutex`.
 */
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

/**
 * Execute a protected section `a` times, acquiring and releasing the global mutex on each iteration.
 *
 * @param a Number of iterations; each iteration locks the global `mutex`, executes the protected code, and then unlocks it.
 */
void CONC_DUNLOCK_S_GOOD(int a) 
{
    for (int i = 0; i < a; i++) 
    {
        pthread_mutex_lock(mutex);
        // ...
        pthread_mutex_unlock(mutex);    //修复点
    }
}