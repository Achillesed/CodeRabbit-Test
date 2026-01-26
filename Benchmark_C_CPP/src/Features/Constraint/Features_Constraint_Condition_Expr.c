//条件运算
#include "benchmark.h"
int Features_Constraint_Condition_Expr_bad(int* p)
{
    int a;
    int b;
    int c;
    scanf("%d%d", &b, &c);
    a = b < c ? c : 0;
    if (a)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}
int Features_Constraint_Condition_Expr_good(int* p)
{
    int a;
    int b;
    int c;
    int d;
    scanf("%d%d%d", &b, &c, &d);
    a = b < c ? c * c - 19323 : 15 + d * d;
    if (a == 0)
        return *p;  //NO NPD 条件冲突
    return 0;
}



int Features_Constraint_Condition_Expr_main(){
    int *p = NULL;     //Source: 空指针null
    Features_Constraint_Condition_Expr_good(p);
    Features_Constraint_Condition_Expr_bad(p);
}