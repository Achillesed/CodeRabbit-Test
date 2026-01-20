/**
    Filename: PTR_FIXXEDADDR_PTR_S.c
    Vuln: PTR_FIXXEDADDR_PTR_S
    SourceLine: -1
    SinkLine: 14
    Comment: 将固定地址分配给指针
*/

#include <stdio.h>
#include <stdlib.h>
int *getPtr();
void PTR_FIXXEDADDR_PTR_S_BAD()
{
    int (*pt2Function)(float, char, char) = (int *)0x08040000;  //缺陷点
    int result = (*pt2Function) (12, 'a', 'b');

}

void PTR_FIXXEDADDR_PTR_S_GOOD()
{
    int (*pt2Function)(float, char, char) = getPtr();  //修复点
    int result = (*pt2Function) (12, 'a', 'b');

}