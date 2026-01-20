/**
    Filename: DYN_CREATE_THREAD_S.c
    Vuln: DYN_CREATE_THREAD_S
    SourceLine: -1
    SinkLine: 21
    Comment: Dir 5.3 (必需) 不应创建任何动态线程 [MISRAC2012-DIR_5_3]
*/
#include <pthread.h>

pthread_t thread1, thread2;

/**
 * Thread entry that performs no action and returns NULL.
 *
 * @param ignore Unused pointer parameter; may be NULL.
 * @returns NULL.
 */
void *fun02( void* ignore )
{
    // ...
    return 0;
}

/**
 * Thread entry function that creates `thread2` to run `fun02` and then returns.
 *
 * @param ignore Unused context pointer passed to the thread entry.
 * @returns `NULL` pointer.
 */
void *fun01( void* ignore )
{
    // ...
    pthread_create(&thread2, NULL, &fun02, NULL); // 违规点：线程 thread2 被另一个线程入口点函数 fun01 线程 thread1 创建
    return 0;
}

/**
 * Demonstrates a bad dynamic thread-creation pattern by spawning a thread whose entry routine creates another thread.
 *
 * This function calls pthread_create to start `fun01` in a new thread (stored in `thread1`). `fun01` itself creates an additional thread, illustrating the prohibited pattern.
 *
 * @returns 0.
 */
int DYN_CREATE_THREAD_S_BAD(void)
{
    pthread_create(&thread1, NULL, &fun01, NULL);
    return 0;
}

/**
 * Thread entry function that performs no thread creation.
 *
 * @param ignore Unused thread argument; may be NULL.
 * @returns `NULL` pointer.
 */
void *fun03( void* ignore )
{
    // ...
    return 0;
}

pthread_t thread3;
/**
 * Create thread3 using fun03 as the entry function; the entry function does not create additional threads.
 *
 * @returns `0` on success.
 */
int DYN_CREATE_THREAD_S_GOOD(void)
{
    pthread_create(&thread3, NULL, &fun03, NULL); // 修复点：线程入口点函数 fun03 未创建线程
    return 0;
}