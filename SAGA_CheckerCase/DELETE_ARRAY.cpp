/**
    Filename: DELETE_ARRAY.cpp
    Vuln: DELETE_ARRAY
    SourceLine: -1
    SinkLine: 13
    Comment: 对象的非数组删除
*/

#include <iostream>

void DELETE_ARRAY_BAD() 
{
    char *buf = new char [10];
    /* do something */
    delete buf; // 缺陷点：数组 delete 应该用 delete[]
}

void DELETE_ARRAY_GOOD() 
{
    char *buf = new char [10];
    /* do something */
    delete[] buf; // 修复点
}
