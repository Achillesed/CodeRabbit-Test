#include "benchmark.h"

int *Abilities_Sensitivity_Path_Cond1_source() {
    int *data = NULL;   //Source: 空指针null
    return data;
}

int Abilities_Sensitivity_Path_Cond1_sink(int *data) {
    return *data;       // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Abilities_Sensitivity_Path_Cond1_good(int *data, unsigned cond) {
    int *data1 = data;
    if(cond >= 0)
        data1 = Abilities_Sensitivity_Path_Cond1_source();
    int cond1 = cond;
    //Source 和 Sink 分支条件存在冲突
    if(cond1 < 0) {
        return Abilities_Sensitivity_Path_Cond1_sink(data1);
    }
    else return *data;
}

int Abilities_Sensitivity_Path_Cond1_bad(int *data, unsigned cond) {
    int *data1 = data;
    if(cond >= 0)
        data1 = Abilities_Sensitivity_Path_Cond1_source();
    int cond1 = cond;
    //Source 和 Sink 分支条件满足
    if(cond1 > 0) {
        return Abilities_Sensitivity_Path_Cond1_sink(data1);
    }
    else return *data;
}

int Abilities_Sensitivity_Path_Cond1_good_main(int parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Abilities_Sensitivity_Path_Cond1_good(data, parm);
}

int Abilities_Sensitivity_Path_Cond1_bad_main(int parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Abilities_Sensitivity_Path_Cond1_bad(data, parm);
}