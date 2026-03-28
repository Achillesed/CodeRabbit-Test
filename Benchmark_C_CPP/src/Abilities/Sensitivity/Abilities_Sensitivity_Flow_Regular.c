#include "benchmark.h"
#include <stdio.h>

int Abilities_Sensitivity_Flow_Regular_bad(int x) {
    int m = 100, n;
    n = 10;
    printf("n = %d\n", n);
    n = 100 - x;
    return m / n; // If x is 100, divide-by-zeo bug is triggered!
}

int Abilities_Sensitivity_Flow_Regular_good(int x) {
    int m = 100, n;
    n = 100 - x;
    printf("n = %d\n", n);
    n = 10;
    return m / n;
}

int Abilities_Sensitivity_Flow_Regular_bad_main() {
    int input;
    scanf("%d\n", &input);
    return Abilities_Sensitivity_Flow_Regular_bad(input);
}

int Abilities_Sensitivity_Flow_Regular_good_main() {
    int input;
    scanf("%d\n", &input);
    return Abilities_Sensitivity_Flow_Regular_good(input);
}