/**
    Filename: RACE_CONDITION_WITHIN_THREAD_S.c
    Vuln: RACE_CONDITION_WITHIN_THREAD_S
    SourceLine: -1
    SinkLine: 23
    Comment: Dir 5.1 (必需) 线程之间不应存在数据争用 [MISRAC2012-DIR_5_1]
*/
#include <pthread.h>
pthread_t thread1, thread2;

int x;
/**
 * Set the shared global variable `x` to 1.
 *
 * This function writes to the global `x` without synchronization; concurrent
 * execution with other threads that access `x` may result in a data race.
 *
 * @param ignore Unused thread argument; may be NULL.
 * @returns Null pointer.
 */
void *fun02( void* ignore )
{
    int a;
    x = 1;      //缺陷点
    a = 1;
    // ...
    return 0;
}

/**
 * Set the shared global variable `x` to 2 and terminate the thread.
 *
 * @param ignore Unused thread argument (may be NULL).
 * @returns NULL pointer.
 */
void *fun01( void* ignore )
{
    x = 2;      //缺陷点
    // ...
    return 0;
}

/**
 * Create two threads that run fun01 and fun02.
 *
 * Starts thread1 executing fun01 and thread2 executing fun02 without
 * checking pthread_create return values and without joining the threads;
 * concurrent access to shared variable `x` may result in a data race.
 *
 * @returns Always returns 0.
 */
int DYN_CREATE_THREAD_S_BAD(void)
{
    pthread_create(&thread1, NULL, &fun01, NULL);
    pthread_create(&thread2, NULL, &fun02, NULL);
    return 0;
}

pthread_t thread3, thread4;
int y;
pthread_mutex_t* mutex;
/**
 * Set the shared variable `y` to 3 under mutex protection.
 *
 * Locks the global `mutex`, assigns 3 to the shared variable `y`, then unlocks the mutex.
 *
 * @param ignore Unused thread argument (provided to match pthread signature).
 * @returns `NULL` on completion.
 */
void *fun03( void* ignore )
{
    // ...
    pthread_mutex_lock(mutex);
    y = 3;      //修复点
    pthread_mutex_unlock(mutex);
    return 0;
}

/**
 * Set shared variable y to 4 while holding the mutex.
 *
 * Locks the global mutex, assigns 4 to the shared variable `y`, then unlocks the mutex.
 * @param ignore Unused parameter required by the pthread entry signature.
 * @return `NULL`.
 */
void *fun04( void* ignore )
{
    // ...
    pthread_mutex_lock(mutex);
    y = 4;      //修复点
    pthread_mutex_unlock(mutex);
    return 0;
}

/**
 * Create two threads that perform mutex-protected updates to shared state.
 *
 * This function launches thread3 running fun03 and thread4 running fun04.
 * Both thread routines perform their updates while holding the shared mutex.
 *
 * @returns 0 on completion.
 */
int DYN_CREATE_THREAD_S_GOOD(void)
{
    pthread_create(&thread3, NULL, &fun03, NULL);
    pthread_create(&thread4, NULL, &fun04, NULL);
    return 0;
}