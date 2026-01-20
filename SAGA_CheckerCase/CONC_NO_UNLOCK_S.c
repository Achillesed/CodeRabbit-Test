/**
    Filename: CONC_NO_UNLOCK_S.c
    Vuln: CONC_NO_UNLOCK_S
    SourceLine: -1
    SinkLine: 13
    Comment: 锁定不当——缺少解锁
*/
#include <pthread.h>
pthread_mutex_t mutex;

void* thread_func_bad(void* arg) 
{
    pthread_mutex_lock(&mutex);     //缺陷点：加锁后未解锁
    // do something
    // 未调用pthread_mutex_unlock(&mutex);
    return NULL;
}

int CONC_NO_UNLOCK_S_BAD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, thread_func_bad, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}
pthread_mutex_t mutex1;
void* thread_func_good(void* arg) 
{
    pthread_mutex_lock(&mutex1);        //修复点
    // do something
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int CONC_NO_UNLOCK_S_GOOD() 
{
    pthread_t thread;
    pthread_mutex_init(&mutex1, NULL);
    pthread_create(&thread, NULL, thread_func_good, NULL);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex1);

    return 0;
}