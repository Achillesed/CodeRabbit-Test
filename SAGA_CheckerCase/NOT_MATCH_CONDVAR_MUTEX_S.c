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

/**
 * Demonstrates an incorrect association of a pthread condition variable with a mutex.
 *
 * This negative example calls pthread_cond_wait with `cv` and `mutex1`, showing the misuse of associating the same condition variable with a mutex that differs from other uses of `cv`; such misuse can produce undefined synchronization behavior.
 */
void NOT_MATCH_CONDVAR_MUTEX_S_BAD1() {
    pthread_cond_wait(&cv, &mutex1);  // 缺陷点1
}

/**
 * Demonstrates incorrect association of a condition variable with a different mutex.
 *
 * Calls pthread_cond_wait with the global condition variable `cv` and `mutex2`,
 * illustrating the misuse of using the same condition variable with multiple mutexes,
 * which can lead to undefined behavior.
 */
void NOT_MATCH_CONDVAR_MUTEX_S_BAD2() {
    pthread_cond_wait(&cv, &mutex2);  // 缺陷点2
}

pthread_mutex_t mutex3, mutex4;
pthread_cond_t cv1, cv2;
/**
 * Demonstrates correct use of a condition variable paired with its dedicated mutex.
 *
 * Calls pthread_cond_wait with `cv1` and `mutex3` to illustrate a condition variable
 * associated with a single, matching mutex.
 */
void NOT_MATCH_CONDVAR_MUTEX_S_GOOD1() {
    pthread_cond_wait(&cv1, &mutex3);  // 修复点
}

/**
 * Waits on the global condition variable `cv2` using the global mutex `mutex4`.
 *
 * Blocks the calling thread until `cv2` is signaled while synchronizing access
 * with `mutex4`.
 */
void NOT_MATCH_CONDVAR_MUTEX_S_GOOD2() {
    pthread_cond_wait(&cv2, &mutex4);  // 修复点
}