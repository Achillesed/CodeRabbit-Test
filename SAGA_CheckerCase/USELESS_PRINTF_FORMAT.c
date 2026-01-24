/**
    Filename: USELESS_PRINTF_FORMAT.c
    Vuln: USELESS_PRINTF_FORMAT
    SourceLine: -1
    SinkLine: 14
    Comment: 无效 printf 格式化字符串
*/

#include <stdio.h>
#include <stdlib.h>

void USELESS_PRINTF_FORMAT_BAD(long long ll) 
{
  printf("%Ld\n", ll); //缺陷点：%Ld 在 Windows环境下可能不被正确解析
}

void USELESS_PRINTF_FORMAT_GOOD(long long ll) 
{
  printf("%lld\n", ll); 
}