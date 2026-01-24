/**
    Filename: DELETE_VOID.cpp
    Vuln: DELETE_VOID
    SourceLine: -1
    SinkLine: 14
    Comment: 删除了 void 指针
*/

#include <iostream>

void DELETE_VOID_BAD(void *p)
{
    /* do something */
    delete p;
}

void DELETE_VOID_GOOD(char *p)
{
    /* do something */
    delete p;
}