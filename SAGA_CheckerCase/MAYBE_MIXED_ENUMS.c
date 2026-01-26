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

/**
 * Demonstrates a switch on enum `e` that incorrectly contains a case for `F2` from enum `f`.
 * @param ee Value of enum `e` to branch on.
 */
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

/**
 * Process a value of enum `e` and increment an internal counter for recognized cases.
 *
 * @param ee Value of enum `e` to handle; the function increments a local counter when `ee` is `E1` or `E2`.
 */
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