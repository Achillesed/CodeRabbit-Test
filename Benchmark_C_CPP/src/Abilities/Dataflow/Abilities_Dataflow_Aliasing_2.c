//#include "benchmark.h"

void Abilities_Dataflow_Aliasing_2_update(int *ptr1, int *ptr2) {
    *ptr1 = 5;
    *ptr2 = 0;
}

int Abilities_Dataflow_Aliasing_2_main() {
    int data = 10;
    int *aliasPtr = &data;
    Abilities_Dataflow_Aliasing_2_update(&data, aliasPtr);
    int temp = 10/data;     //Sink:CWE369除零错误
    return 0;
}
