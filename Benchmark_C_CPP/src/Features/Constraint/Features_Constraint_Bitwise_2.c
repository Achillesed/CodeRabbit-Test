#include "benchmark.h"
#include <stdio.h>

//**************************************************************//
//               除零 (Divide By Zero, CWE369)                  //
//**************************************************************//

int Features_Constraint_Bitwise_2_source() {
    int input;
    scanf("%d", &input);
    return input;
}

// division
int Features_Constraint_Bitwise_2_sink(int dividend, int divisor) {
    return dividend / divisor;
}

int Features_Constraint_Bitwise_2_good1(int b) {
    int a = 0, c = b - 4;
    if(b & 0b10101 > 4) { // The value of b cannot be 4
        a = Features_Constraint_Bitwise_2_sink(b, c);
    }

    return a;
}

int Features_Constraint_Bitwise_2_good2(int b) {
    int a = 0, c = b - 4;
    if(b < 4) { // The value of b cannot be 4
        a = Features_Constraint_Bitwise_2_sink(b, c);
    }

    return a;
}

// CSA misses such bug!!!
int Features_Constraint_Bitwise_2_bad1(int b) {
    int a = 0, c = b - 4;
    if(b & 0b10101 > 1) { // The value of b can be 4
        a = Features_Constraint_Bitwise_2_sink(b, c);
    }

    return a;
}

// CSA misses such bug!!!
int Features_Constraint_Bitwise_2_bad2(int b) {
    int a = 0, c = b - 4;
    if(b > 2 && b < 5) { // The value of b can be 4
        a = Features_Constraint_Bitwise_2_sink(b, c);
    }

    return a;
}

int Features_Constraint_Bitwise_2_good_main1() {
    int src = Features_Constraint_Bitwise_2_source();
    return Features_Constraint_Bitwise_2_good1(src);
}

int Features_Constraint_Bitwise_2_bad_main1() {
    int src = Features_Constraint_Bitwise_2_source();
    return Features_Constraint_Bitwise_2_bad1(src);
}

int Features_Constraint_Bitwise_2_good_main2() {
    int src = Features_Constraint_Bitwise_2_source();
    return Features_Constraint_Bitwise_2_good2(src);
}

int Features_Constraint_Bitwise_2_bad_main2() {
    int src = Features_Constraint_Bitwise_2_source();
    return Features_Constraint_Bitwise_2_bad2(src);
}