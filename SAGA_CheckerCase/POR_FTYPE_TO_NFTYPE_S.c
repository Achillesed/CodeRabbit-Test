/**
    Filename: POR_FTYPE_TO_NFTYPE_S.cpp
    Vuln: POR_FTYPE_TO_NFTYPE_S
    SourceLine: -1
    SinkLine: 13
    Comment: 将浮点表达式强制转化为非浮点类型
*/
#include<math.h>

void POR_FTYPE_TO_NFTYPE_S_BAD()
{
    float a2 = 1.23;
    int a3 = a2;    //缺陷点：将浮点表达式强制转化为非浮点类型
}

void POR_FTYPE_TO_NFTYPE_S_GOOD()
{
    float a2 = 1.23;
    long a3 = lround(a2);    //修复点：四舍五入返回 long 类型
}