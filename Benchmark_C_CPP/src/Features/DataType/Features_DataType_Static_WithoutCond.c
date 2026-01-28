#include "benchmark.h"

int Features_DataType_Global_WithoutCond_bad1() {
    static int val = 10;
    int c, res = 0;
    c = val - 10;
    res = 100 / c;
    return res;
}

int Features_DataType_Global_WithoutCond_good() {
    static int val = 10;
    int c, res = 0;
    c = val - 10;
    if (c != 0)
        res = 100 / c;
    return res;
}

int Features_DataType_Global_WithoutCond_bad1_main() {
    return Features_DataType_Global_WithoutCond_bad1();
}

int Features_DataType_Global_WithoutCond_good_main() {
    return Features_DataType_Global_WithoutCond_good();
}