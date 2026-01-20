/**
    Filename: CONC_NO_LOCK_S.c
    Vuln: CONC_NO_LOCK_S
    SourceLine: -1
    SinkLine: 16
    Comment: 锁定不当——缺少锁
*/
#include <pthread.h>
pthread_mutex_t mutex;

void* thread_func_bad(void* arg) 
{
    // pthread_mutex_lock(&mutex);
    // do something

    pthread_mutex_unlock(&mutex);   //缺陷点：解锁之前缺少加锁
    return NULL;
}

int CONC_NO_LOCK_S_BAD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, thread_func_bad, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}
void* thread_func_good(void* arg)
{
    pthread_mutex_lock(&mutex);
    // do something
    pthread_mutex_unlock(&mutex);   //修复点
    return NULL;
}

int CONC_NO_LOCK_S_GOOD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, thread_func_good, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}