#include "benchmark.h"
#include <stdio.h>

int *Abilities_Dataflow_ConstantProp_source() {
    int *data = NULL;   // Source: 空指针null
    return data;
}

int Abilities_Dataflow_ConstantProp_sink(int *data) {
    return *data;       // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Abilities_Dataflow_ConstantProp_good(int *data, int value) {
    int a = 10;
    
    if(value > 0)
        a += 5;
    else
        a -= 5;
        
    if(a > 20)
        Abilities_Dataflow_ConstantProp_sink(data);

    return 0;
}

int Abilities_Dataflow_ConstantProp_bad(int *data, int value) {
    int a = 10;
    
    if(value > 0)
        a += 5;
    else
        a -= 5;
        
    if(a > 5)
        Abilities_Dataflow_ConstantProp_sink(data);

    return 0;
}

int Abilities_Dataflow_ConstantProp_good_main() {
    int input;
    scanf("%d", &input);
    int* data = Abilities_Dataflow_ConstantProp_source();
    return Abilities_Dataflow_ConstantProp_good(data, input);
}

int Abilities_Dataflow_ConstantProp_bad_main() {
    int input;
    scanf("%d", &input);
    int* data = Abilities_Dataflow_ConstantProp_source();
    return Abilities_Dataflow_ConstantProp_bad(data, input);
}