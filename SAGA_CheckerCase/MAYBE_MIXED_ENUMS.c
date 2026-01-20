/**
    Filename: MAYBE_MIXED_ENUMS.c
    Vuln: MAYBE_MIXED_ENUMS
    SourceLine: -1
    SinkLine: 23
    Comment: 推断滥用了枚举
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {E1, E2}e;
typedef enum {F0, F1, F2, F3}f;

void MAYBE_MIXED_ENUMS_BAD(e ee) 
{
  int num = 0;
    switch (ee) 
    {
      case E1:
        num += 1;
        break;
      case F2: //缺陷点：F2 不是 e 中的枚举
        num += 1;
        break;
    }
}

void MAYBE_MIXED_ENUMS_GOOD(e ee) 
{
  int num = 0;
    switch (ee) 
    {
      case E1:
        num += 1;
        break;
      case E2: //修复点：E2 是 e 中的枚举
        num += 1;
        break;
    }
}