#include <pthread.h>

pthread_t thread1, thread2;

pthread_mutex_t mutex;
static pthread_key_t key;

/**
 * Thread start routine that deletes the thread-specific data key.
 *
 * Calls pthread_key_delete(key) to remove the thread-specific key as a side effect.
 *
 * @returns An unspecified pointer value (the function does not provide a meaningful return value).
 */
void *DESTORY_BY_THREAD_S_BAD__1(void *ignore){
    pthread_key_delete(key);    // 违规
}

/**
 * Thread routine that destroys the global mutex `mutex`.
 *
 * This function calls `pthread_mutex_destroy(&mutex)`, which releases resources
 * associated with the global mutex. Calling this while other threads may still
 * access or be blocked on the mutex can lead to undefined behavior.
 *
 * @param ignore Unused parameter.
 * @returns `NULL`.
 */
void *DESTORY_BY_THREAD_S_BAD__2(void *ignore){
    pthread_mutex_destroy(&mutex);  // 违规
}

/**
 * Initialize a mutex and a thread-specific key, then create two threads that run DESTORY_BY_THREAD_S_BAD__1 and DESTORY_BY_THREAD_S_BAD__2.
 *
 * @returns 0
 */
int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_key_create(&key, NULL);

    pthread_create(&thread1, NULL, &DESTORY_BY_THREAD_S_BAD__1, NULL);
    pthread_create(&thread2, NULL, &DESTORY_BY_THREAD_S_BAD__2, NULL);
}


/**
 * Thread entry function that performs no operations.
 *
 * @param ignore Unused argument (typically thread start parameter); ignored by the function.
 * @returns NULL.
 */
void *DESTORY_BY_THREAD_S_GOOD__1(void *ignore){
   
}

/**
 * Thread entry that performs no work.
 *
 * @param ignore Unused parameter; provided to match pthread_create signature.
 * @returns NULL
 */
void *DESTORY_BY_THREAD_S_GOOD__2(void *ignore){
   
}

/**
 * Run a safe threading scenario: initialize a mutex and thread-specific key, start two worker threads, join them, then delete the key and destroy the mutex.
 *
 * @returns Exit status: `0` on success.
 */
int main2(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_key_create(&key, NULL);

    pthread_create(&thread1, NULL, &DESTORY_BY_THREAD_S_GOOD__1, NULL);
    pthread_create(&thread2, NULL, &DESTORY_BY_THREAD_S_GOOD__2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_key_delete(key);    // 不违规
    pthread_mutex_destroy(&mutex);  // 不违规
}