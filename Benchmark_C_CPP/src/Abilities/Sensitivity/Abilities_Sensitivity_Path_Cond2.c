#include "benchmark.h"

int *Abilities_Sensitivity_Path_Cond2_source() {
    int *data = NULL;   //Source: 空指针null
    return data;
}

int Abilities_Sensitivity_Path_Cond2_sink(int *data) {
    return *data;       // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Abilities_Sensitivity_Path_Cond2_bad(int *data, int cond) {
    int *data1 = Abilities_Sensitivity_Path_Cond2_source();
    if(cond < 0) //数据流断开
        data1 = data;
    int cond1 = cond;
    //Source 和 Sink 分支条件满足
    if(cond1 >= 0) {
        return Abilities_Sensitivity_Path_Cond2_sink(data1);
    }
    else return *data;
}

int Abilities_Sensitivity_Path_Cond2_good(int *data, unsigned cond) {
    int *data1 = Abilities_Sensitivity_Path_Cond2_source();
    if(cond >= 0)   //数据流断开
        data1 = data;
    int cond1 = cond;
    //Source 和 Sink 分支条件冲突
    if(cond1 > 0) {
        return Abilities_Sensitivity_Path_Cond2_sink(data1);
    }
    else return *data;
}


int Abilities_Sensitivity_Path_Cond2_bad_main(int parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Abilities_Sensitivity_Path_Cond2_bad(data, parm);
}

int Abilities_Sensitivity_Path_Cond2_good_main(int parm) {
    int *data = malloc(4);
    if(data == NULL)
        return 0;
    return Abilities_Sensitivity_Path_Cond2_good(data, parm);
}