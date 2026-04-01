#include "benchmark.h"
#include <stdio.h>

void Features_Termination_Loop_InfiniteLoop_1_good(unsigned i) {
    if(i >= 30) return;

    while (1) {
        printf("Current value of i: %d\n", i);
        i++;

        if (i % 5 == 0) {
            printf("Take some actions...\n");
        }

        if (i < 20) {
            continue;
        }

        if (i == 30) {
            printf("Loop end!\n");
            break;
        }
    }
}

// The parameter i must be unsigned because unsigned integer overflow is defined behavior,
// whereas signed integer overflow is not.
void Features_Termination_Loop_InfiniteLoop_1_bad1(unsigned i) {
    while (1) {
        printf("Current value of i: %d\n", i);
        i++;

        if (i % 5 == 0) {
            printf("Take some actions...\n");
        }

        if (i < 20) {
            continue;
        }

        if (i == 30) {
            printf("Loop end!\n");
            break;
        }
    }
}

void Features_Termination_Loop_InfiniteLoop_1_bad2(unsigned i) {
    while (1) {
        printf("Current value of i: %d\n", i);
        i++;

        if (i % 5 == 0) {
            printf("Take some actions...\n");
        }

        if (i < 20) {
            continue;
        }

        if (i == 30) {
            printf("Loop end!\n");
        }
    }
}

void Features_Termination_Loop_InfiniteLoop_1_good_main() {
    unsigned input;
    scanf("%d", &input);
    Features_Termination_Loop_InfiniteLoop_1_good(input);
}

void Features_Termination_Loop_InfiniteLoop_1_bad1_main() {
    unsigned input;
    scanf("%d", &input);
    Features_Termination_Loop_InfiniteLoop_1_bad1(input);
}

void Features_Termination_Loop_InfiniteLoop_1_bad2_main() {
    unsigned input;
    scanf("%d", &input);
    Features_Termination_Loop_InfiniteLoop_1_bad2(input);
}