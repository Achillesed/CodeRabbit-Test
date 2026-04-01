#include "benchmark.h"

int *Features_Language_Ternary_Cond1_source() {
    int *data = NULL;   //Source: 空指针null
    return data;
}

int Features_Language_Ternary_Cond1_sink(int *data) {
    return *data;       // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Features_Language_Ternary_Cond1_bad(int *data, int cond) {
    int array[100];
    int *data_array = &array[1];
    //条件为0时存在Source到Sink的数据流
    int *data1 = cond < 0 ? data 
                          : ( cond == 0 ? Features_Language_Ternary_Cond1_source()
                                        : data_array);
    return cond == 0 ? Features_Language_Ternary_Cond1_sink(data1)
                     : 0;
}

int Features_Language_Ternary_Cond1_bad_main(int parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Features_Language_Ternary_Cond1_bad(data, parm);
}

int Features_Language_Ternary_Cond1_good(int *data, int cond) {
    int array[100];
    int *data_array = &array[1];
    //不存在Source到Sink的数据流
    int *data1 = cond < 0 ? data 
                          : ( cond == 0 ? Features_Language_Ternary_Cond1_source()
                                        : data_array);
    return cond > 0 ? Features_Language_Ternary_Cond1_sink(data1)
                    : 0;
}

int Features_Language_Ternary_Cond1_good_main(int parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Features_Language_Ternary_Cond1_good(data, parm);
}