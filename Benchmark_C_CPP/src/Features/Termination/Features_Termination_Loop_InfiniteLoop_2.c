#include "benchmark.h"
#include <stdio.h>

void Features_Termination_Loop_InfiniteLoop_2_bad(unsigned i) {
    while (i > 10) {
        printf("Current value of i: %d\n", i);
        i++;

        if (i % 5 == 0) {
            printf("Take some actions...\n");
        }

        if (i < 20) {
            continue;
        }

        if (i < 25) {
            printf("Loop end!\n");
            break;
        }
    }
}

void Features_Termination_Loop_InfiniteLoop_2_good(unsigned i) {
    while (i > 10) {
        printf("Current value of i: %d\n", i);
        i++;

        if (i % 5 == 0) {
            printf("Take some actions...\n");
        }

        if (i < 20) {
            continue;
        }

        if (i > 25) {
            printf("Loop end!\n");
            break;
        }
    }
}

void Features_Termination_Loop_InfiniteLoop_2_bad_main() {
    unsigned input;
    scanf("%u", &input);
    Features_Termination_Loop_InfiniteLoop_2_bad(input);
}

void Features_Termination_Loop_InfiniteLoop_2_good_main() {
    unsigned input;
    scanf("%u", &input);
    Features_Termination_Loop_InfiniteLoop_2_good(input);
}