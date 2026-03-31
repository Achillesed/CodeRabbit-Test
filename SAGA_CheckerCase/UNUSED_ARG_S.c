/**
    Filename: UNUSED_ARG_S.cpp
    Vuln: UNUSED_ARG_S
    SourceLine: -1
    SinkLine: 8
    Comment: 函数参数未使用
*/
int UNUSED_ARG_S_BAD(int first, int second)     //缺陷点：第二个参数未使用
{
    first *= 2;
    return first;
}

int UNUSED_ARG_S_GOOD(int first)     //修复点
{
    first *= 2;
    return first;
}
