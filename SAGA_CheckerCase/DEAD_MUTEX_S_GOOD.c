/**
    Filename: DEAD_MUTEX_S_GOOD.c
    Vuln: DEAD_MUTEX_S
    SourceLine: -1
    SinkLine: -1
    Comment: Dir 5.2 (必需) 线程之间不应有死锁 [MISRAC2012-DIR_5_2]
*/
#include <pthread.h>

pthread_mutex_t* lock1;
pthread_mutex_t* lock2;
int v1;
int v2;

/**
 * Acquire mutex `a` then `b`, increment the global counters `v1` and `v2` while holding the locks, and release the locks in reverse order.
 * @param a Mutex to lock first.
 * @param b Mutex to lock second.
 */
void takeLocksA(pthread_mutex_t* a, pthread_mutex_t* b) {
    pthread_mutex_lock(a);
    v1++;
    pthread_mutex_lock(b);
    v2++;
    pthread_mutex_unlock(b);
    pthread_mutex_unlock(a);
}

/**
 * Acquire the two mutexes in the order `b` then `a`, increment global counters, and release the mutexes.
 *
 * Acquires `b`, increments the global `v2`, then acquires `a`, increments the global `v1`, and finally
 * releases `a` followed by `b`.
 *
 * @param a Mutex to acquire second (released first).
 * @param b Mutex to acquire first (released last).
 */
void takeLocksB(pthread_mutex_t* a, pthread_mutex_t* b) {
    pthread_mutex_lock(b);
    v2++;
    pthread_mutex_lock(a);
    v1++;
    pthread_mutex_unlock(a);
    pthread_mutex_unlock(b);
}

/**
 * Acquire the two global mutexes in the consistent order (lock2 then lock1), update their associated counters, and release the mutexes.
 *
 * Ensures both global locks are obtained in a fixed order to avoid deadlock; increments v2 then v1 while the locks are held and releases them in reverse order.
 */
void DEAD_MUTEX_S_GOOD1() {
    takeLocksB(lock1, lock2);   //修复点1
}

/**
 * Ensure global mutexes are acquired in the order lock2 then lock1 to avoid deadlock.
 *
 * Acquires lock2 then lock1, updates the shared counters protected by those mutexes,
 * and releases lock1 followed by lock2.
 */
void DEAD_MUTEX_S_GOOD2() {
    takeLocksA(lock2, lock1);   //修复点2
}
