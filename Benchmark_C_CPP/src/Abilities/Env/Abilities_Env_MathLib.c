#include "benchmark.h"
int Abilities_Env_MathLib_bad0(int* p)
{
    float x, y;
    scanf("%f%f", &x, &y);

    if(cos(x) + y > 0.7) {
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    }
    return 0;
}

int Abilities_Env_MathLib_good0(int* p)
{
    float x, y;
    scanf("%f", &x);
    y = x;
    float epsilon = 0.00001f;
    if(fabs(x - y) > epsilon) {
        return *p; //NO NPD 条件不成立
    }
    return 0;
}

int Abilities_Env_MathLib_bad1(int* p)
{
    double x;
    scanf("%lf", &x);
    double epsilon = 0.000001;
    double y = pow(x, 3); 
    if (fabs(y - 27) < epsilon) {
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    }
    return 0;
}

int Abilities_Env_MathLib_good1(int* p)
{
    double x;
    scanf("%lf", &x);

    double y = pow(x, 4); 
    if(y < 0.0) {
        return *p; //NO NPD 条件不成立
    }
    return 0;
}

int Abilities_Env_MathLib_bad2(int* p) {
    double n;
    scanf("%lf", &n);

    double sqRoot = sqrt(n);
    double epsilon = 0.000001;
    if (fabs(sqRoot = 5) < epsilon) {
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    }
    return 0;
}

int Abilities_Env_MathLib_good2(int* p)
{
    double n;
    scanf("%lf", &n);

    double sqRoot = sqrt(n);
    if (n > 0.0 && sqRoot < 0.0) {
        return *p; //NO NPD 条件不成立
    }
    return 0;
}

int Abilities_Env_MathLib_bad3(int* p)
{
    double angle;
    scanf("%lf", &angle);
    double sinVal = sin(angle);
    if(sinVal == 0.5) {
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    }
    return 0;
}
int Abilities_Env_MathLib_good3(int* p)
{
    double angle;
    scanf("%lf", &angle);
    double sinVal = sin(angle);
    if(sinVal > 1.0) {
        return *p; //NO NPD 条件不成立
    }
    return 0;
}


int Abilities_Env_MathLib_main() {
    int *p = NULL;     //Source: 空指针null
    Abilities_Env_MathLib_bad0(p);
    Abilities_Env_MathLib_good0(p);
    Abilities_Env_MathLib_bad1(p);
    Abilities_Env_MathLib_good1(p);
    Abilities_Env_MathLib_bad2(p);
    Abilities_Env_MathLib_good2(p);
    Abilities_Env_MathLib_bad3(p);
    Abilities_Env_MathLib_good3(p);
}