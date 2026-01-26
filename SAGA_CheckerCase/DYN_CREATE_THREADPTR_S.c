/**
    Filename: DYN_CREATE_THREADPTR_S.c
    Vuln: DYN_CREATE_THREADPTR_S
    SourceLine: -1
    SinkLine: 21
    Comment: Rule 22.20 (强制) 在访问线程之前,应先创建线程特有存储指针 [MISRAC2012-RULE_22_20]
*/

#include <pthread.h>
#include <stdio.h>

static pthread_key_t key;

/**
 * Thread entry routine that creates the global thread-specific key.
 *
 * This function calls pthread_key_create(&key, NULL) as a side effect and then returns NULL.
 *
 * @param ptr Pointer passed to the thread entry; unused.
 * @returns NULL (0).
 */
void *thread_bad(void *ptr)
{
    pthread_key_create(&key, NULL); // 缺陷点：此函数在线程入口点函数被调用
    return 0;
}

/**
 * Create a new thread that creates the thread-specific key from within the thread (demonstrates the flawed pattern).
 *
 * @returns 0
 */
int DYN_CREATE_THREADPTR_S_BAD()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, &thread_bad, NULL);              
    return 0;
}

static pthread_key_t key;

/**
 * Thread entry function that performs no action.
 * @param ptr Pointer to thread argument; ignored.
 * @returns A null pointer (NULL).
 */
void *thread_good(void *ptr)
{
    
    return 0;
}

/**
 * Initialize the thread-specific key and create a thread that runs thread_good.
 *
 * Creates the pthread key for thread-local storage before spawning the thread,
 * then starts a thread executing `thread_good`.
 *
 * @returns 0 on success.
 */
int DYN_CREATE_THREADPTR_S_GOOD()
{
    pthread_t thread1;
    pthread_key_create(&key, NULL); // 修复点
    pthread_create(&thread1, NULL, &thread_good, NULL);              
    return 0;
}