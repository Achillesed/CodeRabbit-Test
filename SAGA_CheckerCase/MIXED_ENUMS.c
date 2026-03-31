/**
    Filename: MIXED_ENUMS.c
    Vuln: MIXED_ENUMS
    SourceLine: -1
    SinkLine: 20
    Comment: 混合了枚举类型
*/

typedef enum {E1, E2}e;
typedef enum {F0, F1, F2, F3}f;

void MIXED_ENUMS_BAD(e ee) 
{
    int num = 0;
    switch (ee) 
    {
        case E1:
            num++;
            break;
        case F2: //缺陷点：F2不为 e 的枚举类型
            num++;
            break;
        default:
            num++;
            break;
    }
}

void MIXED_ENUMS_GOOD(e ee) 
{
    int num = 0;
    switch (ee) 
    {
        case E1:
            num++;
            break;
        case E2: //修复点：E2 为 e 的枚举类型
            num++;
            break;
        default:
            num++;
            break;
    }
}