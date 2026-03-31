/**
    Filename: SELF_CALL_S.c
    Vuln: SELF_CALL_S
    SourceLine: -1
    SinkLine: 11
    Comment: 禁止使用直接或间接自调用函数
*/
void func() 
{
    /* do something */
    func(); // 缺陷点
}

int SELFCALL_S_BAD() 
{
    func();
    return 0;
}

void func2() 
{
    /* do something */
}

int SELFCALL_S_GOOD() 
{
    func2();    //修复点
    return 0;
}