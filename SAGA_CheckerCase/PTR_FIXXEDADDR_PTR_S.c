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
/**
 * Demonstrates unsafe binding of a function pointer to a fixed memory address and invokes it.
 *
 * Assigns the hard-coded address 0x08040000 to a function pointer and calls it, which may
 * produce undefined behavior or create a security vulnerability if that address is invalid
 * or not executable on the target platform.
 */
void PTR_FIXXEDADDR_PTR_S_BAD()
{
    int (*pt2Function)(float, char, char) = (int *)0x08040000;  //缺陷点
    int result = (*pt2Function) (12, 'a', 'b');

}

/**
 * Obtain a function pointer at runtime and invoke it with sample arguments.
 *
 * Calls the function pointer returned by `getPtr()` with the arguments 12, 'a', 'b'
 * and stores the integer result in a local variable.
 */
void PTR_FIXXEDADDR_PTR_S_GOOD()
{
    int (*pt2Function)(float, char, char) = getPtr();  //修复点
    int result = (*pt2Function) (12, 'a', 'b');

}