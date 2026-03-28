//三目运算符条件搜集
#include "benchmark.h"
int Features_Language_Ternary_good(int p) {
    int *a = p ? &p : 0;    //Source: 空指针null, 当p为0时
    return p ? *a : 0; //条件冲突 NO NPD
}

int Features_Language_Ternary_bad(int p) {
    int *a = p ? 0 : &p;    //Source: 空指针null，当p不为0时
    return p ? *a : 0; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

