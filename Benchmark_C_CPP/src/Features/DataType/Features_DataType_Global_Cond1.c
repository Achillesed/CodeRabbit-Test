#include "benchmark.h"
static double Features_DataType_Global_Cond1_Five = 5.00;
int *Features_DataType_Global_Cond1_source() {
    int *data = NULL;   //Source: 空指针null
    return data;
}

int Features_DataType_Global_Cond1_sink(int *data) {
    return *data;       // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Features_DataType_Global_Cond1_bad(int *data) {
    int *data1;
    if(GlobalInt_Zero == 0)
        data1 = Features_DataType_Global_Cond1_source();
    else
        data1 = data;
    if(fabs(GlobalFloat_Five - Features_DataType_Global_Cond1_Five) < 0.00001)
        return Features_DataType_Global_Cond1_sink(data1);
    else
        return 0;
}

int Features_DataType_Global_Cond1_bad_main() {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Features_DataType_Global_Cond1_bad(data);
}


int Features_DataType_Global_Cond1_good(int *data, double parm) {
    int *data1;
    if(GlobalInt_Zero == parm)
        data1 = Features_DataType_Global_Cond1_source();
    else
        data1 = data;
    if(fabs(parm - Features_DataType_Global_Cond1_Five) < 0.00001)
        return Features_DataType_Global_Cond1_sink(data1);
    else
        return 0;
}

int Features_DataType_Global_Cond1_good_main(double parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Features_DataType_Global_Cond1_good(data, parm);
}