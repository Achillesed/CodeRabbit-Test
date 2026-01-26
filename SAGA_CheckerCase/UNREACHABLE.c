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
/**
 * Handle a possibly-NULL `p` and attempt to use the pointed value; due to missing braces this implementation always performs the error return.
 * @param p Pointer to an integer to be used; intended to be validated for NULL before dereference.
 * @returns `-1` in all cases; the call to `use_p(*p)` and the final `return 0` are unreachable because `return -1` is always executed. 
 */
int UNREACHABLE_BAD(int *p)
{
  if( p == NULL )   
    handle_error();    
    return -1;
  use_p( *p );    //缺陷点：if 后面的语句需要用"{}"括起，否则只进行下一行代码，return -1总是会被执行，此处为结构死代码
  return 0;    
}

/**
 * Validate the pointer and process the pointed integer when present.
 *
 * @param p Pointer to an integer; if non-NULL its value is processed, if NULL an error handler is invoked.
 * @returns `-1` if `p` is NULL after invoking the error handler, `0` on success.
 */
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