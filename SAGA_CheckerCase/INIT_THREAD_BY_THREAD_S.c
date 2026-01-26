/**
    Filename: INIT_THREAD_BY_THREAD_S.c
    Vuln: INIT_THREAD_BY_THREAD_S
    SourceLine: -1
    SinkLine: 15
    Comment: Rule 22.14 (强制) 线程同步对象在访问之前应先初始化 [MISRAC2012-RULE_22_14]
*/
#include <pthread.h>

pthread_t thread;
pthread_mutex_t mutex1, mutex2;           

/**
 * Initializes the global mutex `mutex1` from within a thread entry routine.
 *
 * @param ignore Unused thread entry parameter.
 * @returns `NULL` (0) pointer.
 */
void *foo( void* ignore )
{
    pthread_mutex_init(&mutex1, NULL); // 违规点：在线程入口函数内初始化线程
    return 0;
}

/**
 * Thread entry that performs no actions.
 * @param ignore Unused thread argument.
 * @return NULL.
 */
void *foo2( void* ignore )
{             
    return 0;
}


/**
 * Create a thread whose entry routine initializes a mutex object, demonstrating improper sequencing.
 *
 * The created thread performs mutex initialization internally rather than ensuring the mutex is
 * initialized prior to thread creation; this can lead to races or undefined behavior and violates
 * the intended initialization-before-use sequencing for synchronization objects.
 */
void INIT_THREAD_BY_THREAD_S_BAD()
{
    pthread_create(&thread, NULL, &foo, NULL);
    // ...
}

/**
 * Initialize the mutex used by the new thread and then create the thread.
 *
 * Initializes `mutex2` before calling `pthread_create`, then starts a thread that runs `foo2`,
 * ensuring the synchronization object is ready prior to thread start.
 */
void INIT_THREAD_BY_THREAD_S_GOOD()
{
    pthread_mutex_init(&mutex2, NULL);   //修复点：在创建的线程外初始化线程同步对象
    pthread_create(&thread, NULL, &foo2, NULL);
    // ...
}