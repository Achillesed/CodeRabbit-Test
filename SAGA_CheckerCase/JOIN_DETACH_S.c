#include <pthread.h>

void * thread_func(void *arg){
    return 0;
}

void JOIN_DETACH_S_BAD()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_func, NULL);
    pthread_join(thread_id, 0);
    pthread_detach(thread_id);  // 违规
}

void JOIN_DETACH_S_GOOD()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_func, NULL);
    pthread_join(thread_id, 0);  // 未违规
}
