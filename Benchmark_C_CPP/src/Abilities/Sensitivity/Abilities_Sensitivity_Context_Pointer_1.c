#include "benchmark.h"
#include <stdlib.h>

int *Abilities_Sensitivity_Context_Pointer_Callee(int *p) {
    return p;
}

int Abilities_Sensitivity_Context_Pointer_bad(int a, int b) {
    int *x, *y;
    x = Abilities_Sensitivity_Context_Pointer_Callee(&a);
    y = Abilities_Sensitivity_Context_Pointer_Callee(&b);
    return 100 / (*x + *y - 30);
}

int Abilities_Sensitivity_Context_Pointer_good(int a, int b) {
    int *x, *y;
    x = Abilities_Sensitivity_Context_Pointer_Callee(&a);
    y = Abilities_Sensitivity_Context_Pointer_Callee(&b);
    return 100 / (*x + *y - 20);
}

int Abilities_Sensitivity_Context_Pointer_bad_main() {
    int a = 20, b = 10;
    return Abilities_Sensitivity_Context_Pointer_bad(a, b);
}

int Abilities_Sensitivity_Context_Pointer_good_main() {
    int a = 20, b = 10;
    return Abilities_Sensitivity_Context_Pointer_good(a, b);
}