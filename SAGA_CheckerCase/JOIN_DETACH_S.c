#include <pthread.h>

/**
 * Thread start routine that immediately returns NULL.
 *
 * @param arg Unused start routine argument.
 * @return NULL pointer.
 */
void * thread_func(void *arg){
    return 0;
}

/**
 * Demonstrates creating a thread, joining it, then incorrectly attempting to detach it.
 *
 * This function creates a thread, waits for its termination with pthread_join, and
 * then calls pthread_detach on the same thread identifier — detaching a thread
 * after it has been joined is invalid.
 */
void JOIN_DETACH_S_BAD()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_func, NULL);
    pthread_join(thread_id, 0);
    pthread_detach(thread_id);  // 违规
}

/**
 * Create a thread running thread_func and wait for its termination with pthread_join.
 *
 * Demonstrates correct usage by joining the created thread (no detach is performed).
 */
void JOIN_DETACH_S_GOOD()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_func, NULL);
    pthread_join(thread_id, 0);  // 未违规
}