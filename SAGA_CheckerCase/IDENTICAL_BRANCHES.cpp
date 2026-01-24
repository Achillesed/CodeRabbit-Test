/**
    Filename: IDENTICAL_BRANCHES.cpp
    Vuln: IDENTICAL_BRANCHES
    SourceLine: -1
    SinkLine: 15
    Comment: 适用于不同分支的相同代码
*/

#include <stdio.h>
#include <stdlib.h>
int getValue();
void IDENTICAL_BRANCHES_BAD()
{
  int x, y, z;
  x = getValue();
  if (x==2)   //缺陷点：两分支代码相同
  {
    y=32;
    z=y*2;
  } 
  else
  {
    y=32;
    z=y*2;
  }
}

void process(int& y, int& z)
{
  y = 32;
  z = y*2;
}
void IDENTICAL_BRANCHES_GOOD()
{
  int x, y, z;
  x = getValue();
  if (x==2)   //修复点：相同代码包装成一个函数
  {
    process(y, z);
  } 
  else
  {
    process(y, z);
  }
}