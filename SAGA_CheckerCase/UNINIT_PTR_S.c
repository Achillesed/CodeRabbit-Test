/**
    Filename: UNINIT_PTR_S.c
    Vuln: UNINIT_PTR_S
    SourceLine: -1
    SinkLine: 13
    Comment: 使用未初始化的指针
*/

int *getInit();
int UNINIT_PTR_S_BAD() 
{
    int *sign;
    int sign1 = *sign;   //缺陷点：使用未初始化指针 sign
    return sign1;
}

int UNINIT_PTR_S_GOOD() 
{
    int *sign = getInit();
    int sign1 = *sign;   //修复点
    return sign1;
}