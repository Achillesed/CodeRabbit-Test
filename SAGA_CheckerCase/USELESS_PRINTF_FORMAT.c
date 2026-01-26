/**
    Filename: USELESS_PRINTF_FORMAT.c
    Vuln: USELESS_PRINTF_FORMAT
    SourceLine: -1
    SinkLine: 14
    Comment: 无效 printf 格式化字符串
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Print a 64-bit integer using the "%Ld" printf format specifier.
 *
 * On some platforms (for example Windows) the "%Ld" specifier may not be recognized.
 *
 * @param ll 64-bit integer value to print.
 */
void USELESS_PRINTF_FORMAT_BAD(long long ll) 
{
  printf("%Ld\n", ll); //缺陷点：%Ld 在 Windows环境下可能不被正确解析
}

/**
 * Print a 64-bit integer to standard output followed by a newline.
 * @param ll The integer value to print.
 */
void USELESS_PRINTF_FORMAT_GOOD(long long ll) 
{
  printf("%lld\n", ll); 
}