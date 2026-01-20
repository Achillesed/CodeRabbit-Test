#include <pthread.h>
#include <stdbool.h>
pthread_mutex_t* mutex;
bool preconditionHolds();

/**
 * Attempt to unlock the global mutex only when a precondition holds.
 *
 * If `preconditionHolds()` returns true, unlocks the global `mutex`; otherwise
 * does nothing, which may leave the mutex locked.
 */
void THREAD_MISSING_UNLOCK_S_BAD()
{
    if(preconditionHolds()){
        pthread_mutex_unlock(mutex);
    }
}    // 违规


THREAD_MISSING_UNLOCK_S_GOOD()
{
    if(preconditionHolds()){
        ;
    }
    pthread_mutex_unlock(mutex);
}