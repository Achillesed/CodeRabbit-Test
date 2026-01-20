/**
    Filename: ASSERT_EFFECT.c
    Vuln: ASSERT_EFFECT
    SourceLine: -1
    SinkLine: 16
    Comment: 断言中的其他作用
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int getValue();
void ASSERT_EFFECT_BAD() 
{
    int x = getValue();
    assert(++x);        // 缺陷点：在断言中进行修改操作
}

void ASSERT_EFFECT_GOOD() 
{
    int x = getValue();
    int temp = x + 1;
    assert(temp);        // 修复点：在断言前提前修改
}