#include "benchmark.h"

#define LARGE_NUMBER 10000

void a(int *e) {
    *e = (0 == e);
}

void Features_Termination_Loop_Big_Loop_irrelevance_good() {
    int d[4];
    for (int c =0 ; c < LARGE_NUMBER; c++) //数据流路径上存在多个大循环（和条件无关）
        ;
    a(d);
}

void Features_Termination_Loop_Big_Loop_irrelevance_bad_sink(int *e) {
    *e = (0 == e); // Sink: 空指针解引用
}

void Features_Termination_Loop_Big_Loop_irrelevance_bad() {
    int* d = NULL; //Source: 空指针null
    for (int c =0 ; c < LARGE_NUMBER; c++)
        ;
    Features_Termination_Loop_Big_Loop_irrelevance_bad_sink(d);
}

int Features_Termination_Loop_Big_Loop_irrelevance_main(){
    Features_Termination_Loop_Big_Loop_irrelevance_good();
    Features_Termination_Loop_Big_Loop_irrelevance_bad();
    return 0;
}