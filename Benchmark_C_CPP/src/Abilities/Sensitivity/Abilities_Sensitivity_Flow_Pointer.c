#include "benchmark.h"
#include <stdio.h>

int Abilities_Sensitivity_Flow_Pointer_Sink(int** p)
{
    return **p;  // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Abilities_Sensitivity_Flow_Pointer_bad()
{
    int a1 = 0;
    int* a = &a1;
    int* b = NULL;    // Source
    int** c;

    c = &a;
    printf("%p\n", c);
    c = &b;
    return Abilities_Sensitivity_Flow_Pointer_Sink(c);
}

int Abilities_Sensitivity_Flow_Pointer_good()
{
    int a1 = 0;
    int* a = &a1;
    int* b = NULL;    // Source
    int** c;

    c = &b;
    printf("%p\n", c);
    c = &a;
    
    return Abilities_Sensitivity_Flow_Pointer_Sink(c);
}

int Abilities_Sensitivity_Flow_Pointer_bad_main()
{
    return Abilities_Sensitivity_Flow_Pointer_bad();
}

int Abilities_Sensitivity_Flow_Pointer_good_main()
{
    return Abilities_Sensitivity_Flow_Pointer_good();
}