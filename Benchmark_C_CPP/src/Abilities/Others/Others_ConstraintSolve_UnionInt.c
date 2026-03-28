#include "benchmark.h"
#include "stdbool.h"

struct a
{
    int b;
    int c;
};

union d
{
    struct a e;
};

void Others_ConstraintSolve_UnionInt_good()
{
    union d g = {};
    int *r = (int *)0;
    if (-g.e.b && g.e.c) //条件冲突 NO NPD
    {
        *r = 42; // Null Pointer Dereference
    }
}

int Others_ConstraintSolve_UnionInt_main(){
    Others_ConstraintSolve_UnionInt_good();
}
