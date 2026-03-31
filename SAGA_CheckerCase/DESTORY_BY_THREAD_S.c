#include <pthread.h>

pthread_t thread1, thread2;

pthread_mutex_t mutex;
static pthread_key_t key;

void *DESTORY_BY_THREAD_S_BAD__1(void *ignore){
    pthread_key_delete(key);    // 违规
}

void *DESTORY_BY_THREAD_S_BAD__2(void *ignore){
    pthread_mutex_destroy(&mutex);  // 违规
}

int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_key_create(&key, NULL);

    pthread_create(&thread1, NULL, &DESTORY_BY_THREAD_S_BAD__1, NULL);
    pthread_create(&thread2, NULL, &DESTORY_BY_THREAD_S_BAD__2, NULL);
}


void *DESTORY_BY_THREAD_S_GOOD__1(void *ignore){
   
}

void *DESTORY_BY_THREAD_S_GOOD__2(void *ignore){
   
}

int main2(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_key_create(&key, NULL);

    pthread_create(&thread1, NULL, &DESTORY_BY_THREAD_S_GOOD__1, NULL);
    pthread_create(&thread2, NULL, &DESTORY_BY_THREAD_S_GOOD__2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_key_delete(key);    // 不违规
    pthread_mutex_destroy(&mutex);  // 不违规
}
