/**
    Filename: INCORRECT_USE_THREAD_S.c
    Vuln: INCORRECT_USE_THREAD_S
    SourceLine: -1
    SinkLine: 18,19
    Comment: 线程对象只能由相应的标准库访问
*/
#include <pthread.h>
#include <stdbool.h>

pthread_t t1;
pthread_t t2;
pthread_mutex_t m;

void recv_func(void *arg);

/**
 * Demonstrates incorrect usage of pthread objects and mutexes.
 *
 * This function illustrates two observable defects: passing a mutex object
 * directly to a thread/handler and comparing `pthread_t` identifiers using
 * the `==` operator instead of using the pthread library's comparison
 * mechanisms.
 */
void INCORRECT_USE_THREAD_BAD(){
    recv_func(&m);       // 缺陷点：线程对象只能由自定义函数访问
    if (t1 == t2)     // 缺陷点：线程对象直接被操作
    {

    }
}

/**
 * Demonstrates safe access to thread objects by comparing two global thread identifiers while holding a mutex.
 *
 * Locks the global mutex `m`, compares `t1` and `t2` using `pthread_equal`, and then unlocks `m`.
 */
void INCORRECT_USE_THREAD_GOOD(){
    pthread_mutex_lock(&m);     // 修复点
    if (pthread_equal(t1, t2))  // 修复点
    pthread_mutex_unlock(&m);   // 修复点
}