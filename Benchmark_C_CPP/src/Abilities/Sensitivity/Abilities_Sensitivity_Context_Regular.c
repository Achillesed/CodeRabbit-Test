#include "benchmark.h"
#include <stdio.h>

// A context-sensitive analysis could accurately recognize the return value
// based on different path conditions, e.g., ret = 10 or ret = 20. However, 
// a context-insensitive analysis could only compute a over-approximation of
// the return value, e.g., ret = 10 or 20.
int Abilities_Sensitivity_Context_Regular_Callee(int x) {
    if(x > 0)
        return 10;

    return 20;
}

int Abilities_Sensitivity_Context_Regular_bad() {
    int n = Abilities_Sensitivity_Context_Regular_Callee(-1);
    return 100 / (n - 20);
}

int Abilities_Sensitivity_Context_Regular_good() {
    int n = Abilities_Sensitivity_Context_Regular_Callee(1);
    return 100 / (n - 20);
}

int Abilities_Sensitivity_Context_Regular_bad_main() {
    return Abilities_Sensitivity_Context_Regular_bad();
}

int Abilities_Sensitivity_Context_Regular_good_main() {
    return Abilities_Sensitivity_Context_Regular_good();
}