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
/**
 * @brief Demonstrates a conditional with identical branches (an example of the bad pattern).
 *
 * Calls getValue() and executes two branches of an if-statement that perform the same operations,
 * illustrating duplicated code that should be consolidated.
 */
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

/**
 * @brief Set two integers: assign 32 to y and twice that value to z.
 *
 * Sets the referenced integer `y` to 32 and assigns `z` the value `y * 2`.
 *
 * @param[out] y Destination integer that will be set to 32.
 * @param[out] z Destination integer that will be set to twice `y`.
 */
void process(int& y, int& z)
{
  y = 32;
  z = y*2;
}
/**
 * @brief Demonstrates a refactored control flow that avoids duplicate branch code.
 *
 * Reads a value via `getValue()` and delegates identical branch behavior to `process(y, z)`,
 * ensuring the common operations for `y` and `z` are performed regardless of the condition.
 */
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