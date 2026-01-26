#include "benchmark.h"

int Features_DataType_Float_Arithmetic_bad(double d, int *p) {
    if (d > 1.0) {
        *p = 1; // Reachable!!!
        return *p;
    }
    
    return 0;
}

int Features_DataType_Float_Arithmetic_good(double d, int *p) {
    if (d > d) {
        *p = 1; // Unreachable!!!
        return *p;
    }
    
    return 0;
}

int Features_DataType_Float_Arithmetic_bad_main() {
    double input;
    int *p = (int *) 0;
    scanf("%lf", &input);
    return Features_DataType_Float_Arithmetic_bad(input, p);
}

int Features_DataType_Float_Arithmetic_good_main() {
    double input;
    int *p = (int *) 0;
    scanf("%lf", &input);
    return Features_DataType_Float_Arithmetic_good(input, p);
}