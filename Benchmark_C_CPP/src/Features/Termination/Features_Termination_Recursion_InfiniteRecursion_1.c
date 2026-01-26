#include "benchmark.h"
#include <stdio.h>

void Features_Termination_Recursion_InfiniteRecursion_1_good(int n) {
    printf("Current value of n: %d\n", n);
    
    if (n % 5 == 0) {
        printf("Take some actions...\n");
    }

    if (n < 20) {
        Features_Termination_Recursion_InfiniteRecursion_1_good(n + 1);
    }

    if (n == 30) {
        printf("Recursion end!\n");
        return;
    }
}

void Features_Termination_Recursion_InfiniteRecursion_1_bad(int n) {
    printf("Current value of n: %d\n", n);
    
    if (n % 5 == 0) {
        printf("Take some actions...\n");
    }

    Features_Termination_Recursion_InfiniteRecursion_1_bad(n + 1);

    if (n == 30) {
        printf("Recursion end!\n");
        return;
    }
}

void Features_Termination_Recursion_InfiniteRecursion_1_good_main() {
    int n = 0;
    Features_Termination_Recursion_InfiniteRecursion_1_good(n);
}

void Features_Termination_Recursion_InfiniteRecursion_1_bad_main() {
    int n = 0;
    Features_Termination_Recursion_InfiniteRecursion_1_bad(n);
}