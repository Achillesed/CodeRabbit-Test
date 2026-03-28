#include "benchmark.h"

#define LARGE_NUMBER 10000

//**************************************************************//
//               除零 (Divide By Zero, CWE369)                  //
//**************************************************************//

int Features_Termination_Loop_Big_Loop_good(int n) {
    int i = 1, res;
    for(; i <= LARGE_NUMBER; i++) {
        res = n / i;
        printf("result = %d\n", res);
    }

    return res;
}

int Features_Termination_Loop_Big_Loop_bad(int n) {
    int i = 1, res;
    for(; i <= LARGE_NUMBER; i++) {
        res = n / (i - 1000);
        printf("result = %d\n", res);
    }

    return res;
}

int Features_Termination_Loop_Big_Loop_good_main() {
    int divident = 100;
    return Features_Termination_Loop_Big_Loop_good(divident);
}

int Features_Termination_Loop_Big_Loop_bad_main() {
    int divident = 100;
    return Features_Termination_Loop_Big_Loop_bad(divident);
}