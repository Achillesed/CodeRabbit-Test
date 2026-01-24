/**  算术运算
* 乘法、除法、取余、左移、右移
*/

#include "benchmark.h"
int Features_Constraint_Linear_Arithmetic_bad0(int* p)
{
    int a;
    scanf("%d", &a);
    if(a < 0){
        a = -a;
    }
    int x = a * 2;
    if (x)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}

int Features_Constraint_Linear_Arithmetic_bad1(int* p)
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a / b == 2 && a % b == 1)
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}

int Features_Constraint_Linear_Arithmetic_good1(int* p)
{
    int a;
    scanf("%d", &a);
    if (a % 2 == 0 && a % 2 == 1)
        return *p;  //NO NPD 条件冲突
    return 0;
}

int Features_Constraint_Linear_Arithmetic_bad2(int* p)
{
    unsigned int a; 
    scanf("%u", &a);
    unsigned int shifted = (a << 4) >> 4;

    if (shifted == a) 
        return *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
    return 0;
}

int Features_Constraint_Linear_Arithmetic_good2(int* p)
{
    unsigned int a; 
    scanf("%u", &a);
    unsigned int shifted = (a << 4) >> 4;

    if (shifted > a)
        return *p;  //NO NPD 条件冲突
    return 0;
}


int Features_Constraint_Linear_Arithmetic_main(){
    int *p = NULL;     //Source: 空指针null
    Features_Constraint_Linear_Arithmetic_good0(p);
    Features_Constraint_Linear_Arithmetic_bad0(p);
    Features_Constraint_Linear_Arithmetic_good1(p);
    Features_Constraint_Linear_Arithmetic_bad1(p);
    Features_Constraint_Linear_Arithmetic_good2(p);
    Features_Constraint_Linear_Arithmetic_bad2(p);
}