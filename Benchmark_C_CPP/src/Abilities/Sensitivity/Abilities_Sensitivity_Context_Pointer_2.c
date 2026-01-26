#include "benchmark.h"
#include <stdlib.h>

// The information from the two callsites is merged at the entry so that 
// *p and *q are considered to alias in both calling contexts.
int Abilities_Sensitivity_Context_Pointer_Callee_bad(int **p, int **q) {
    int *r;
    int local = 10;
    *p = &local;
    r = *q;
    return 100 / (20 - *r);
}

// The information from the two callsites is merged at the entry so that 
// *p and *q are considered to alias in both calling contexts.
int Abilities_Sensitivity_Context_Pointer_Callee_good(int **p, int **q) {
    int *r;
    int local = 10;
    *p = &local;
    r = *q;
    return 100 / (10 - *r);
}

int Abilities_Sensitivity_Context_Pointer_Caller1_bad() {
    int a = 5, b = 20;
    int *p1 = &a, *p2 = &b;
    return Abilities_Sensitivity_Context_Pointer_Callee_bad(&p1, &p2);
}

int Abilities_Sensitivity_Context_Pointer_Caller2_bad() {
    int a = 5;
    int *q1 = &a;
    return Abilities_Sensitivity_Context_Pointer_Callee_bad(&q1, &q1);
}

int Abilities_Sensitivity_Context_Pointer_Caller1_good() {
    int a = 5, b = 20;
    int *p1 = &a, *p2 = &b;
    return Abilities_Sensitivity_Context_Pointer_Callee_good(&p1, &p2);
}

int Abilities_Sensitivity_Context_Pointer_Caller2_good() {
    int a = 5;
    int *q1 = &a;
    return Abilities_Sensitivity_Context_Pointer_Callee_good(&q1, &q1);
}