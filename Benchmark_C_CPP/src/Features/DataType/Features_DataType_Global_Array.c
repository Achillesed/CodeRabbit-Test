#include "benchmark.h"

int a[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

int Features_DataType_Array_Cond_bad(int n, int *p) {
    if (n < 0 || n > 9) 
        return 0;
    
    if(a[n] == 11) {
        *p = a[n]; // Reachable!!!
        return *p;
    }

    return 0;
}

int Features_DataType_Array_Cond_good(int n, int *p) {
    if (n < 0 || n > 9) 
        return 0;
    
    if(a[n] == 21) {
        *p = a[n]; // Unreachable!!!
        return *p;
    }

    return 0;
}

int Features_DataType_Array_Cond_bad_main() {
    int input;
    int *p = (int *) 0;
    scanf("%d", &input);
    return Features_DataType_Array_Cond_bad(input, p);
}

int Features_DataType_Array_Cond_good_main() {
    int input;
    int *p = (int *) 0;
    scanf("%d", &input);
    return Features_DataType_Array_Cond_good(input, p);
}