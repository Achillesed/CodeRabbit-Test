/**
    Filename: NOT_MATCH_CONDVAR_MUTEX_S.c
    Vuln: NOT_MATCH_CONDVAR_MUTEX_S
    SourceLine: -1
    SinkLine: 18
    Comment: Rule 22.19 (必需) 一个条件变量至多与一个 mutex 对象相关联 [MISRAC2012-RULE_22_19]规则
*/
#include <pthread.h>

pthread_mutex_t mutex1, mutex2;
pthread_cond_t cv;

void NOT_MATCH_CONDVAR_MUTEX_S_BAD1() {
    pthread_cond_wait(&cv, &mutex1);  // 缺陷点1
}

void NOT_MATCH_CONDVAR_MUTEX_S_BAD2() {
    pthread_cond_wait(&cv, &mutex2);  // 缺陷点2
}

pthread_mutex_t mutex3, mutex4;
pthread_cond_t cv1, cv2;
void NOT_MATCH_CONDVAR_MUTEX_S_GOOD1() {
    pthread_cond_wait(&cv1, &mutex3);  // 修复点
}

void NOT_MATCH_CONDVAR_MUTEX_S_GOOD2() {
    pthread_cond_wait(&cv2, &mutex4);  // 修复点
}