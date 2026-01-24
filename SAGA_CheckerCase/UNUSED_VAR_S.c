/**
    Filename: UNUSED_VAR_S.c
    Vuln: UNUSED_VAR_S
    SourceLine: -1
    SinkLine: 11
    Comment: 未使用的变量
*/
void useData(char);
void UNUSED_VAR_S_BAD()
{
    char data;   // 缺陷点：变量data被声明，但之后未被使用
}

void UNUSED_VAR_S_GOOD()
{
    char data = 'C';    //修复点：在后有使用
    useData(data); 

}