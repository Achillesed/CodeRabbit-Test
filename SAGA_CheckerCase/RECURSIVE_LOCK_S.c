/**
    Filename: RECURSIVE_LOCK_S.c
    Vuln: RECURSIVE_LOCK_S
    SourceLine: -1
    SinkLine: 24
    Comment: Rule 22.18 (必需) 非递归 mutex 不得递归锁定 [MISRAC2012-RULE_22_18]
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

pthread_mutex_t* mutex;

/**
 * Determine whether the precondition for the recursive-locking checks holds.
 *
 * Currently implemented as a stub that always returns `true`.
 *
 * @returns `true` if the precondition holds, `false` otherwise.
 */
bool preconditionHolds() {
    // ...
    return true;
}

/**
 * Demonstrates a computation performed under a non-recursive mutex that (incorrectly) recurses while the lock is held.
 *
 * Locks the global non-recursive `mutex`, performs conditional work, and calls itself recursively while still holding the lock.
 * This causes an attempt to re-lock the same non-recursive mutex and can result in deadlock or undefined behavior.
 */
void exclusivelyCompute_bad()
{
    pthread_mutex_lock(mutex);
    if (preconditionHolds()) {
        /* perform some computations */
        exclusivelyCompute_bad();   // 违规点: 递归调用将导致双重锁定
    }
    pthread_mutex_unlock(mutex);
}

/**
 * Demonstrates an incorrect recursive locking scenario using a non-recursive pthread mutex.
 *
 * Allocates and initializes a mutex, invokes a computation that may recursively attempt to
 * acquire the same mutex (leading to deadlock or undefined behavior), then destroys and frees the mutex.
 */
void RECURSIVE_LOCK_S_BAD()
{
    mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, NULL);
    exclusivelyCompute_bad();
    pthread_mutex_destroy(mutex);
    free(mutex);
}

/**
 * Perform the computation recursively without acquiring the global mutex.
 *
 * When the precondition holds, executes the computation and recurses into the same
 * non-locking path so the mutex is not locked repeatedly across recursive calls.
 */
static void nonexclusivelyCompute()
{
    if (preconditionHolds()) {
        /* perform some computations */
        nonexclusivelyCompute(); // 修复: 只进行一次加锁
    }
}

/**
 * Execute a computation while holding the global mutex to ensure exclusive access.
 *
 * Acquires the global `mutex`, performs the recursive-safe computation, and then
 * releases the `mutex`. The computation invoked does not re-acquire the same mutex,
 * avoiding recursive locking of a non-recursive mutex.
 */
void exclusivelyCompute_good()
{
    pthread_mutex_lock(mutex);
    nonexclusivelyCompute();
    pthread_mutex_unlock(mutex);
}

/**
 * Set up a non-recursive mutex, execute the corrected locking scenario, and free resources.
 *
 * Allocates and initializes a pthread mutex, runs the non-recursive computation protected
 * by that mutex, and then frees the allocated mutex memory.
 */
void RECURSIVE_LOCK_S_GOOD()
{
    mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, (const pthread_mutexattr_t*)0);
    exclusivelyCompute_good();
    free(mutex);
}