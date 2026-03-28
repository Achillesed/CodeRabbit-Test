#include "benchmark.h"

int global = 10;

int Features_DataType_Global_WithoutCond_bad1() {
    int c, res = 0;
    c = global - 10;
    res = 100 / c;
    return res;
}

int Features_DataType_Global_WithoutCond_bad2() {
    int c, res = 0, local = 10;
    c = local - 10;
    res = 100 / c;
    return res;
}

int Features_DataType_Global_WithoutCond_good() {
    int c, res = 0;
    c = global - 10;
    if (c != 0)
        res = 100 / c;
    return res;
}

int Features_DataType_Global_WithoutCond_bad1_main() {
    return Features_DataType_Global_WithoutCond_bad1();
}

int Features_DataType_Global_WithoutCond_bad2_main() {
    return Features_DataType_Global_WithoutCond_bad2();
}

int Features_DataType_Global_WithoutCond_good_main() {
    return Features_DataType_Global_WithoutCond_good();
}