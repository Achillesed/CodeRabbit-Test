#include "benchmark.h"

#define SAFEFREE(ptr) do { free(ptr); (ptr) = NULL; } while(0)

#define FREE(ptr) do { if(*ptr != 10){ *ptr = 10;} free(ptr); } while(0)

int Features_Language_Macro_bad() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;

    FREE(ptr); // source: free ptr
    free(ptr); // sink: double free ptr

    return 0;
}

int Features_Language_Macro_good() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;

    SAFEFREE(ptr); // source: free ptr
    free(ptr);

    return 0;
}
