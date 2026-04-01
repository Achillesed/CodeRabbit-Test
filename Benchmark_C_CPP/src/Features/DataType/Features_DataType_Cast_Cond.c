#include <benchmark.h>

int Features_DataType_Cast_Cond_bad0(int t1)
{
    int t2 = t1 + 3;
    if (!t2)
    {
        int *p = (void *)t2;
        *p = 1024; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good0(int t1)
{
    int t2 = t1 * 3;
    if (t2)
    {
        int *p = (void *)t2;
        *p = 1024; 
    }
}

int Features_DataType_Cast_Cond_bad1(double t1)
{
    int t2 = (int)t1; //整数与浮点数之间的转换
    t2 = t2 + 3;
    if (!t2)
    {
        int *q = (int *)t2; 
        return *q; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good1(double t1)
{
    int t2 = (int)t1;
    t2 = t2 + 3;
    if (t2)
    {
        int *q = (int *)t2; 
        return *q;
    }
}

int Features_DataType_Cast_Cond_bad2(int *p)
{
    unsigned x = (unsigned)p;
    x = x * 3;
    if (!x)
    {
        int *q = (int *)x; 
        return *q; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good2(int *p)
{
    unsigned x = (unsigned)p;
    x = x / 2;
    if (x)
    {
        int *q = (int *)x;
        return *q;
    }
}

int Features_DataType_Cast_Cond_bad3(int t1)
{
    char *p = (char *)t1;
    if (!p)
    {
        return *p; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good3(int t1)
{
    char *p = (char *)t1;
    if (p)
    {
        return *p; 
    }
}

int Features_DataType_Cast_Cond_bad4(long longValue)
{
    int* p = NULL; ////Source: 空指针null
    void *voidPointer = &longValue; // 将long整数地址转换为void指针
    int *intPointer = (int *)voidPointer; // 将void指针转换为int指针
    if(*intPointer + 1> 0){
        return *p; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good4(long longValue)
{
    int* p = NULL; ////Source: 空指针null
    void *voidPointer = &longValue; // 将long整数地址转换为void指针
    int *intPointer = (int *)voidPointer; // 将void指针转换为int指针
    p = intPointer;
    if(p){
        return *p; 
    }
}

//浮点数到指针的转换
int Features_DataType_Cast_Cond_bad5(float f)
{
    int* p = NULL; ////Source: 空指针null
    int *intPointer = (int *)(*(int *)&f); // 将浮点数f的位模式直接转换为整数指针
    if(*intPointer + 1> 0){
        return *p; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good5(float f)
{
    int* p = NULL; ////Source: 空指针null
    int *intPointer = (int *)(*(int *)&f); // 将浮点数f的位模式直接转换为整数指针
    p = intPointer;
    if(p){
        return *p; 
    }
}

int Features_DataType_Cast_Cond_bad6(char* data)
{
    int* p = NULL; ////Source: 空指针null
    int *intPointer = (int *)data; // 将字符数组的地址转换为整数指针
    if(*intPointer * 100> 0){
        return *p; // Sink: 空指针解引用
    }
}

int Features_DataType_Cast_Cond_good6(char* data)
{
    int* p = NULL; ////Source: 空指针null
    int *intPointer = (int *)data; // 将字符数组的地址转换为整数指针
    p = intPointer;
    if(p){
        return *p; 
    }
}