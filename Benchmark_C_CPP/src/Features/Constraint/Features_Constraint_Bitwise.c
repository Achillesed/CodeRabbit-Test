//位运算
#include "benchmark.h"
int Features_Constraint_Bitwise_bad(int* p)
{
    int a;
    scanf("%d", &a);
    a = a | 1;
    if (a)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}
int Features_Constraint_Bitwise_good(int* p)
{
    int a;
    scanf("%d", &a);
    if ((a & 1) && ((a & 1) ^ 1))
        return *p;  //NO NPD 条件冲突
    return 0;
}

int Features_Constraint_Bitwise_Expr_main(){
    int *p = NULL;     //Source: 空指针null
    Features_Constraint_Bitwise_good(p);
    Features_Constraint_Bitwise_bad(p);
}