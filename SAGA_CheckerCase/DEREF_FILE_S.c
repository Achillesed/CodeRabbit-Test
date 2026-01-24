/**
    Filename: DEREF_FILE_S.c
    Vuln: DEREF_FILE_S
    SourceLine: -1
    SinkLine: 14
    Comment: 指向 FILE 对象的指针不得解除引用 [MISRAC2012-RULE_22_5]
*/

#include <stdio.h>
FILE *pf1;
FILE *pf2;
void DEREF_FILE_S_BAD(){
  FILE f3;
  f3 = *pf2;  //违规点
}
void DEREF_FILE_S_GOOD(){
  FILE f3;
  pf2 = pf1;  //修复点
}