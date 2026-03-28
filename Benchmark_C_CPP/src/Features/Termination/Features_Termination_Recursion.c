#include "benchmark.h"

int factorial(int n) {
    if(n <= 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int Features_Termination_Recursion_bad(int* p)
{
    int a;
    scanf("%d", &a);
    if (factorial(a) == 5040) // factorial(7)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}
int Features_Termination_Recursion_good(int* p)
{
    int a;
    scanf("%d", &a);
    if (factorial(a) < 0)
        return *p;  //NO NPD 条件冲突
    return 0;
}

int Features_Constraint_Recursive_main(){
    int *p = NULL;     //Source: 空指针null
    Features_Termination_Recursion_good(p);
    Features_Termination_Recursion_bad(p);
}