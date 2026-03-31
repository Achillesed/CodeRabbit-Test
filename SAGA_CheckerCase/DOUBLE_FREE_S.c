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