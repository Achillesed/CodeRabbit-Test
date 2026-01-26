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
/**
 * Demonstrates an incorrect dereference of a FILE pointer.
 *
 * Copies the FILE object pointed to by the global `pf2` into a local `FILE`
 * variable, which dereferences the pointer and violates MISRA 2012 rules
 * disallowing dereference of pointers to `FILE` objects.
 */
void DEREF_FILE_S_BAD(){
  FILE f3;
  f3 = *pf2;  //违规点
}
/**
 * Set the global FILE pointer `pf2` to the value of `pf1`.
 *
 * Updates the global pointer `pf2` so it points to the same FILE object as `pf1`,
 * avoiding dereferencing a FILE pointer.
 */
void DEREF_FILE_S_GOOD(){
  FILE f3;
  pf2 = pf1;  //修复点
}