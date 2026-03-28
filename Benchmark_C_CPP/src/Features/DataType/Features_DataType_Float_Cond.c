#include "benchmark.h"
int Features_DataType_Float_Cond_bad0(int* p)
{
    float a;
    scanf("%f", &a);
    if (a > 0)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}

int Features_DataType_Float_Cond_bad1(int* p)
{
    double a;
    scanf("%lf", &a);
    if (a > 0)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}

int Features_DataType_Float_Cond_bad2(int* p)
{
    float x, y;
    scanf("%f%f", &x, &y);

    if(x + y > 0.7) {
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    }
    return 0;
}

int Features_DataType_Float_Cond_bad3(int* p)
{
    double x, y;
    scanf("%lf%lf", &x, &y);

    if(x + y > 0.7) {
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    }
    return 0;
}


int Features_DataType_Float_Cond_main(){
    int *p = NULL;     //Source: 空指针null
    Features_DataType_Float_Cond_bad0(p);
    Features_DataType_Float_Cond_bad1(p);
    Features_DataType_Float_Cond_bad2(p);
    Features_DataType_Float_Cond_bad3(p);
}