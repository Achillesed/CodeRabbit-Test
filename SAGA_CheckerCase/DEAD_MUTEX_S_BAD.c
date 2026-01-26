/**
    Filename: DEAD_MUTEX_S_BAD.c
    Vuln: DEAD_MUTEX_S
    SourceLine: -1
    SinkLine: 34
    Comment: Dir 5.2 (必需) 线程之间不应有死锁 [MISRAC2012-DIR_5_2]
*/
#include <pthread.h>

pthread_mutex_t* lock1;
pthread_mutex_t* lock2;
int v1;
int v2;

/**
 * Acquire mutex `a` then mutex `b`, increment the global counters `v1` and `v2`, and release the mutexes in reverse order.
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
 * Acquire the two mutexes in the order `b` then `a`, incrementing the corresponding global counters.
 *
 * Locks `b`, increments the global counter `v2`, then locks `a` and increments the global counter `v1`.
 * Both mutexes are unlocked in reverse order (`a` then `b`) before returning.
 *
 * @param a Pointer to the first mutex to be acquired after `b`.
 * @param b Pointer to the mutex to acquire first.
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
 * Execute the lock-order path that acquires lock2 then lock1 and demonstrates a potential deadlock between lock1 and lock2.
 *
 * This public entry point triggers the mutex acquisition sequence corresponding to deadlock path 1.
 */
void DEAD_MUTEX_S_BAD1() {
    takeLocksB(lock1, lock2);   //缺陷点1：死锁路径1
}

/**
 * Execute the lock ordering that acquires lock1 then lock2 to illustrate a potential deadlock.
 *
 * This public entry point runs the sequence that locks `lock1` and then `lock2`; if another
 * thread acquires these locks in the opposite order, the program may deadlock.
 */
void DEAD_MUTEX_S_BAD2() {
    takeLocksA(lock1, lock2);   //缺陷点2：死锁路径2
}
