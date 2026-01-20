/**
    Filename: CONC_NO_UNLOCK_S.c
    Vuln: CONC_NO_UNLOCK_S
    SourceLine: -1
    SinkLine: 13
    Comment: 锁定不当——缺少解锁
*/
#include <pthread.h>
pthread_mutex_t mutex;

/**
 * Locks the global mutex and exits without releasing it.
 *
 * This function acquires the global `mutex` and returns while still holding the lock,
 * leaving the mutex locked and potentially causing deadlock or a resource leak.
 *
 * @param arg Unused thread argument; ignored.
 * @returns NULL.
 */
void* thread_func_bad(void* arg) 
{
    pthread_mutex_lock(&mutex);     //缺陷点：加锁后未解锁
    // do something
    // 未调用pthread_mutex_unlock(&mutex);
    return NULL;
}

/**
 * Demonstrates a synchronization misuse where a created thread locks a global mutex and does not unlock it.
 *
 * Initializes the global mutex, starts a thread that acquires the mutex without releasing it, waits for the thread to finish, and destroys the mutex.
 * @returns 0 on success.
 */
int CONC_NO_UNLOCK_S_BAD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, thread_func_bad, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}
pthread_mutex_t mutex1;
/**
 * Thread entry that locks `mutex1`, performs a critical section, and then unlocks `mutex1`.
 *
 * @param arg Unused; present to match the `pthread` thread function signature.
 * @returns NULL. 
 */
void* thread_func_good(void* arg) 
{
    pthread_mutex_lock(&mutex1);        //修复点
    // do something
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

/**
 * Execute the corrected concurrency example demonstrating proper mutex locking and unlocking by a thread.
 *
 * Initializes a mutex, starts a thread that locks and then unlocks that mutex, waits for the thread to finish,
 * and then destroys the mutex.
 *
 * @returns 0 on success.
 */
int CONC_NO_UNLOCK_S_GOOD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex1, NULL);
    pthread_create(&thread, NULL, thread_func_good, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex1);

    return 0;
}