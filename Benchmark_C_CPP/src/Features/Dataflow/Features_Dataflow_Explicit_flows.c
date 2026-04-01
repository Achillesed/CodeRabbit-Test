#include "benchmark.h"
#include <stdio.h>

//**************************************************************//
//               除零 (Divide By Zero, CWE369)                  //
//**************************************************************//

int Features_Dataflow_Explicit_flows_source() {
    int input;
    scanf("%d", &input);
    return input;
}

// division
int Features_Dataflow_Explicit_flows_sink(int dividend, int divisor) {
    return dividend / divisor;
}

int Features_Dataflow_Explicit_flows_good(int b) {
    int a = 0, c;
    switch (b) {
        case 1: a = b / 2; break;
        case 4: c = b - 3; a = Features_Dataflow_Explicit_flows_sink(b, c); break;
        default: break;
    }

    return a;
}

int Features_Dataflow_Explicit_flows_bad(int b) {
    int a = 0, c;
    switch (b) {
        case 1: a = b / 2; break;
        case 4: c = b - 4; a = Features_Dataflow_Explicit_flows_sink(b, c); break;
        default: break;
    }

    return a;
}

int Features_Dataflow_Explicit_flows_good_main() {
    int src = Features_Dataflow_Explicit_flows_source();
    return Features_Dataflow_Explicit_flows_good(src);
}

int Features_Dataflow_Explicit_flows_bad_main() {
    int src = Features_Dataflow_Explicit_flows_source();
    return Features_Dataflow_Explicit_flows_bad(src);
}