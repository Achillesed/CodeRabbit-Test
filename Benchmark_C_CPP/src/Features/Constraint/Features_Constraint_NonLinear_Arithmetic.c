#include "benchmark.h"
int Features_Constraint_NonLinear_Arithmetic_bad()
{
    int *p = NULL;
    int a;
    scanf("%d", &a);
    int x = a * a;
    if (x)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}

int Features_Constraint_NonLinear_Arithmetic_good()
{
    int *p = NULL;
    int a;
    scanf("%d", &a);
    int x = a * a;
    if (x && p)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}
