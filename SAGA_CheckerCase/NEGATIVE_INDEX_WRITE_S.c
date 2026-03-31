/**
    Filename: NEGATIVE_INDEX_WRITE_S.cpp
    Vuln: NEGATIVE_INDEX_WRITE_S
    SourceLine: -1
    SinkLine: 14
    Comment: 缓冲区向下溢出写入
*/


int NEGATIVE_INDEX_WRITE_S_BAD() 
{
    int array[10] = {0};
    int index = -1;
    array[index] = 10;      //缺陷点：数组索引 index 值为 -1
    return 0;
}

int NEGATIVE_INDEX_WRITE_S_GOOD() 
{
    int array[10] = {0};
    int index = 0;
    array[index] = 10;      //修复点：数组索引 index 值为 0
    return 0;
}
