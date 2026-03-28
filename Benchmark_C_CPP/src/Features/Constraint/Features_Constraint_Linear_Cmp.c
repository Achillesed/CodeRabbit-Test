#include "benchmark.h"

int Features_Constraint_Linear_Cmp_bad(int *p, int n) {
    if(n < 0 || n > 10) return 0;

    if (n + 1 > n) {
        *p = 1;
        return *p;
    }

    return 0;
}

int Features_Constraint_Linear_Cmp_good(int *p, int n) {
    if(n < 0 || n > 10) return 0;
    
    if (n > n + 1) {
        *p = 1;
        return *p;
    }

    return 0;
}

int Features_Constraint_Linear_Cmp_bad_main(){
    int *p = 0;
    int a;
    scanf("%d", &a);
    return Features_Constraint_Linear_Cmp_bad(p, a);
}

int Features_Constraint_Linear_Cmp_good_main(){
    int *p = 0;
    int a;
    scanf("%d", &a);
    return Features_Constraint_Linear_Cmp_good(p, a);
}