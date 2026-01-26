/**
    Filename: DOUBLE_FREE_S.c
    Vuln: DOUBLE_FREE_S
    SourceLine: -1
    SinkLine: 21
    Comment: 双重释放
*/

#include <stdio.h>
#include <stdlib.h>
int getvalue();
/**
 * Demonstrates a double-free vulnerability by freeing the same allocated pointer along a reachable execution path.
 *
 * The allocated memory may be freed inside the conditional branch and then freed again unconditionally, which can cause undefined behavior.
 */
void DOUBLE_FREE_S_BAD()
{
    int a = getvalue();
    char* ptr = (char*)malloc(sizeof(char));
    if (a) {
        /* do something */
        free(ptr);
    }
    /* do something */
    free(ptr);      //缺陷点：存在一条可达路径 对 ptr 指针进行了两次 free
}

/**
 * Allocate a byte and ensure the allocated memory is freed at most once.
 *
 * If the conditional branch frees the allocation the function returns immediately,
 * otherwise the allocation is freed once before returning.
 */
void DOUBLE_FREE_S_GOOD()
{
    int a = getvalue();
    char* ptr = (char*)malloc(sizeof(char));
    if (a) {
        /* do something */
        free(ptr);
        return;
    }
    /* do something */
    free(ptr); // 修复点：第一次 free 后会退出函数
}