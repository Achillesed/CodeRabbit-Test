/**
    Filename: UNINIT_PTR_S.c
    Vuln: UNINIT_PTR_S
    SourceLine: -1
    SinkLine: 13
    Comment: 使用未初始化的指针
*/

int *getInit();
/**
 * Demonstrates dereferencing an uninitialized pointer, causing undefined behavior.
 *
 * @returns The integer value obtained by dereferencing the uninitialized pointer `sign`; the result and program behavior are undefined.
 */
int UNINIT_PTR_S_BAD() 
{
    int *sign;
    int sign1 = *sign;   //缺陷点：使用未初始化指针 sign
    return sign1;
}

/**
 * Retrieve value from an initialized int pointer provided by getInit.
 *
 * Calls getInit to obtain an int pointer and returns the integer it points to.
 * Assumes getInit returns a valid, dereferenceable pointer.
 *
 * @returns The integer value pointed to by the pointer returned from getInit.
 */
int UNINIT_PTR_S_GOOD() 
{
    int *sign = getInit();
    int sign1 = *sign;   //修复点
    return sign1;
}