#include "benchmark.h"
#include <stdio.h>

int *Abilities_InterProcedural_Regular_1_source() {
    int *data = 0;   // Source: 空指针null
    return data;
}

int Abilities_InterProcedural_Regular_1_sink(int *data) {
    return *data;       // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

int Abilities_InterProcedural_Regular_1_bad(int *data) {        
    int res = Abilities_InterProcedural_Regular_1_sink(data);
    return res;
}

int Abilities_InterProcedural_Regular_1_bad_main() {
    int* data = Abilities_InterProcedural_Regular_1_source();
    return Abilities_InterProcedural_Regular_1_bad(data);
}