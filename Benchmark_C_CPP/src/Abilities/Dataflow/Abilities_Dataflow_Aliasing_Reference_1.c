//指针别名分析 + 流敏感指针分析
#include "benchmark.h"
void Abilities_Dataflow_Aliasing_Reference_1_good_Snk(int ***p, int ***q) {
    if(**p){
        int c = ***q;    //NO NPD
    }else{
        int a = 1;
        **p = &a;
        int c = ***q;       //NO NPD
    }
}

void Abilities_Dataflow_Aliasing_Reference_1_bad_Snk(int **p, int **q) {
    if(*p){
        int c = **q;
    }else{
        int a = 1;
        *p = &a;
        int c = **q;    // Sink: 空指针解引用 (Null Pointer Dereference, CWE476) x与y不属于指针别名
    }
}

int Abilities_Dataflow_Aliasing_Reference_1_good_main() {
    int *a = NULL;
    int **x = &a;
    int **y = &a;
    int ***w = &x;

    Abilities_Dataflow_Aliasing_Reference_1_good_Snk(&y, w);
    return 0;
}

int Abilities_Dataflow_Aliasing_Reference_1_bad_main() {
    int *a = NULL;    //Source: 指针a为null
    int *x = a;
    int *y = a;
    int **w = &x;
    Abilities_Dataflow_Aliasing_Reference_1_bad_Snk(&y, w);
    return 0;
}

