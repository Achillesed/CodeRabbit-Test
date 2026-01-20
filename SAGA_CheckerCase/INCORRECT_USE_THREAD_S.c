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

void INCORRECT_USE_THREAD_BAD(){
    recv_func(&m);       // 缺陷点：线程对象只能由自定义函数访问
    if (t1 == t2)     // 缺陷点：线程对象直接被操作
    {

    }
}

void INCORRECT_USE_THREAD_GOOD(){
    pthread_mutex_lock(&m);     // 修复点
    if (pthread_equal(t1, t2))  // 修复点
    pthread_mutex_unlock(&m);   // 修复点
}
