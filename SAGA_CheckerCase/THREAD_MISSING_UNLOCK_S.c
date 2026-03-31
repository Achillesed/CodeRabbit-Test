#include <pthread.h>
#include <stdbool.h>
pthread_mutex_t* mutex;
bool preconditionHolds();

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
