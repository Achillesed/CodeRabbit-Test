#include "benchmark.h"
#include <stdlib.h>
#include <stdio.h>

int Abilities_Sensitivity_Field_ArrayIndex_bad1(int n) {
    int res = 0, arr[5];
    arr[0] = 1; arr[1] = 2; arr[2] = n; arr[3] = 4; arr[4] = 5;

    if (n > 0 && n < 10) {
        res = 10 / (arr[2] - 3);
    }
    
    return res;
}

int Abilities_Sensitivity_Field_ArrayIndex_bad2(int n) {
    int res = 0, arr[5];
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;

    if (n > 0 && n < 10) {
        res = 10 / (arr[2] - 3);
    }
    
    return res;
}

int Abilities_Sensitivity_Field_ArrayIndex_good(int n) {
    int res = 0, arr[5];
    arr[0] = 1; arr[1] = 2; arr[2] = n; arr[3] = 4; arr[4] = 5;

    if (n > 0 && n < 10) {
        res = 10 / (arr[4] - 3);
    }
    
    return res;
}

int Abilities_Sensitivity_Field_ArrayIndex_bad1_main() {
    int input;
    scanf("%d\n", &input); 
    return Abilities_Sensitivity_Field_ArrayIndex_bad1(input);
}

int Abilities_Sensitivity_Field_ArrayIndex_bad2_main() {
    int input;
    scanf("%d\n", &input); 
    return Abilities_Sensitivity_Field_ArrayIndex_bad2(input);
}

int Abilities_Sensitivity_Field_ArrayIndex_good_main() {
    int input;
    scanf("%d\n", &input); 
    return Abilities_Sensitivity_Field_ArrayIndex_good(input);
}