#include "benchmark.h"
#include <stdio.h>

//**************************************************************//
//               除零 (Divide By Zero, CWE369)                  //
//**************************************************************//

int Features_Dataflow_Implicit_flows_source() {
    int input;
    scanf("%d", &input);
    return input;
}

// division
int Features_Dataflow_Implicit_flows_sink(int dividend, int divisor) {
    return dividend / divisor;
}

int Features_Dataflow_Implicit_flows_good1(int b) {
    int a = 0, c, d;

    if(b < 0) 
        d = 1;
    else if(b >= 0 && b < 10) 
        d = 2;
    else if(b > 10) 
        d = 4;

    switch (b) {
        case 1: a = d / 2; break;
        case 4: c = d - 4; a = Features_Dataflow_Implicit_flows_sink(d, c); break;
    }

    return a;
}

int Features_Dataflow_Implicit_flows_good2(int b) {
    int a = 0, c, d;

    if(b < 0) 
        d = 1;
    else if(b >= 0 && b < 10) 
        d = 2;
    else if(b > 10) 
        d = 3;

    switch (b) {
        case 1: a = d / 2; break;
        case 14: c = d - 4; a = Features_Dataflow_Implicit_flows_sink(d, c); break;
    }

    return a;
}

int Features_Dataflow_Implicit_flows_bad(int b) {
    int a = 0, c, d;

    if(b < 0) 
        d = 1;
    else if(b >= 0 && b < 10) 
        d = 2;
    else if(b > 10) 
        d = 4;

    switch (b) {
        case 1: a = d / 2; break;
        case 14: c = d - 4; a = Features_Dataflow_Implicit_flows_sink(d, c); break;
    }

    return a;
}

int Features_Dataflow_Implicit_flows_good1_main() {
    int src = Features_Dataflow_Implicit_flows_source();
    return Features_Dataflow_Implicit_flows_good1(src);
}

int Features_Dataflow_Implicit_flows_good2_main() {
    int src = Features_Dataflow_Implicit_flows_source();
    return Features_Dataflow_Implicit_flows_good2(src);
}

int Features_Dataflow_Implicit_flows_bad_main() {
    int src = Features_Dataflow_Implicit_flows_source();
    return Features_Dataflow_Implicit_flows_bad(src);
}