/**
    Filename: UNREACHABLE.c
    Vuln: UNREACHABLE
    SourceLine: -1
    SinkLine: 19
    Comment: 结构死代码
*/

#include <stdio.h>
#include <stdlib.h>

void handle_error();
void use_p(int n);
int UNREACHABLE_BAD(int *p)
{
  if( p == NULL )   
    handle_error();    
    return -1;
  use_p( *p );    //缺陷点：if 后面的语句需要用"{}"括起，否则只进行下一行代码，return -1总是会被执行，此处为结构死代码
  return 0;    
}

int UNREACHABLE_GOOD(int *p)
{
  if( p == NULL )   
  {
    handle_error();    
    return -1;    
  }   
  use_p( *p );    //修复点
  return 0;    
}