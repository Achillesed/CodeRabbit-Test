/**
    Filename: CONC_NO_LOCK_S.c
    Vuln: CONC_NO_LOCK_S
    SourceLine: -1
    SinkLine: 16
    Comment: 锁定不当——缺少锁
*/
#include <pthread.h>
pthread_mutex_t mutex;

/**
 * Demonstrates unlocking a global mutex without acquiring it first.
 *
 * This thread routine calls pthread_mutex_unlock on the global `mutex`
 * without a preceding pthread_mutex_lock, which is a defect that can
 * lead to undefined behavior.
 *
 * @param arg Unused thread argument.
 * @returns NULL.
 */
void* thread_func_bad(void* arg) 
{
    // pthread_mutex_lock(&mutex);
    // do something

    pthread_mutex_unlock(&mutex);   //缺陷点：解锁之前缺少加锁
    return NULL;
}

/**
 * Run a demonstration that creates a thread which improperly unlocks a mutex without acquiring it.
 *
 * Initializes a global mutex, spawns a thread that executes the flawed routine `thread_func_bad`, waits for the thread to finish, and then destroys the mutex.
 *
 * @returns 0 on completion.
 */
int CONC_NO_LOCK_S_BAD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, thread_func_bad, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}
/**
 * Thread entry that acquires the global mutex, performs work while holding it, and releases the mutex before exiting.
 *
 * @returns `NULL`.
 */
void* thread_func_good(void* arg)
{
    pthread_mutex_lock(&mutex);
    // do something
    pthread_mutex_unlock(&mutex);   //修复点
    return NULL;
}

/**
 * Start a thread that demonstrates correct mutex locking and unlocking.
 *
 * Initializes the global mutex, creates a worker thread that locks and unlocks the mutex,
 * waits for the thread to complete, destroys the mutex, and returns.
 *
 * @returns 0 on success.
 */
int CONC_NO_LOCK_S_GOOD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, thread_func_good, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}