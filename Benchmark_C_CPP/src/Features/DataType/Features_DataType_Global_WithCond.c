#include "benchmark.h"

int global = 10;

int Features_DataType_Global_WithCond_bad(int n, int *p) {
    if(n > 10 && n < 20) {
        if(n > global) {
            *p = 10;
            return *p;
        }
    }

    return 0;
}

int Features_DataType_Global_WithCond_good(int n, int *p) {
    if(n > 10 && n < 20) {
        if(n < global) {
            *p = 10;
            return *p;
        }
    }

    return 0;
}

int Features_DataType_Global_WithCond_bad_main() {
    int input;
    int *p = (int *) 0;
    scanf("%d", &input);
    return Features_DataType_Global_WithCond_bad(input, p);
}

int Features_DataType_Global_WithCond_good_main() {
    int input;
    int *p = (int *) 0;
    scanf("%d", &input);
    return Features_DataType_Global_WithCond_good(input, p);
}