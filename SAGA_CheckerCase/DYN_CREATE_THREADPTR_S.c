/**
    Filename: DYN_CREATE_THREADPTR_S.c
    Vuln: DYN_CREATE_THREADPTR_S
    SourceLine: -1
    SinkLine: 21
    Comment: Rule 22.20 (强制) 在访问线程之前,应先创建线程特有存储指针 [MISRAC2012-RULE_22_20]
*/

#include <pthread.h>
#include <stdio.h>

static pthread_key_t key;

void *thread_bad(void *ptr)
{
    pthread_key_create(&key, NULL); // 缺陷点：此函数在线程入口点函数被调用
    return 0;
}

int DYN_CREATE_THREADPTR_S_BAD()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, &thread_bad, NULL);              
    return 0;
}

static pthread_key_t key;

void *thread_good(void *ptr)
{
    
    return 0;
}

int DYN_CREATE_THREADPTR_S_GOOD()
{
    pthread_t thread1;
    pthread_key_create(&key, NULL); // 修复点
    pthread_create(&thread1, NULL, &thread_good, NULL);              
    return 0;
}