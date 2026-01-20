/**
    Filename: INCOMPATIBLE_CAST_S.c
    Vuln: INCOMPATIBLE_CAST_S
    SourceLine: -1
    SinkLine: 14
    Comment: 转型不当导致的越界访问
*/

void INCOMPATIBLE_CAST_S_BAD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = *(long*)pi;  // 缺陷点：指针指向的有效类型被解引用为较宽的对象，这可能导致内存崩溃
}

void INCOMPATIBLE_CAST_S_GOOD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = 0L | *(int*)pi;  // 修复点：将结果提升为 long 类型
}