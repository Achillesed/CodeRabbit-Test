/**
    Filename: NEGATIVE_INDEX_READ_S.cpp
    Vuln: NEGATIVE_INDEX_READ_S
    SourceLine: -1
    SinkLine: 13
    Comment: 缓冲区向下溢出读取
*/

int NEGATIVE_INDEX_READ_S_BAD() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = -1;
    int a = arr[index];     //缺陷点：数组索引 index 值为 -1
    return 0;
}

int NEGATIVE_INDEX_READ_S_GOOD() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 0;
    int a = arr[index];     //修复点：数组索引 index 值为 0
    return 0;
}