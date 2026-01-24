/**
    Filename: MISMATCH_S.cpp
    Vuln: MISMATCH_S
    SourceLine: -1
    SinkLine: 20
    Comment: 不匹配的内存管理例程
*/

#include <iostream>

typedef struct BarObj 
{
    int a;
    int b;
};

void MISMATCH_S_BAD()
{
    BarObj *ptr = new BarObj();
    free(ptr); // 缺陷点：错误使用 free 释放 new 分配出的内存
}

void MISMATCH_S_GOOD()
{
    BarObj *ptr = new BarObj();
    delete(ptr); // 修复点：使用 delete 释放 new 分配的内存
}