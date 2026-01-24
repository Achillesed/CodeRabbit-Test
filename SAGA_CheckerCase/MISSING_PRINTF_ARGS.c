/**
    Filename: MISSING_PRINTF_ARGS.c
    Vuln: MISSING_PRINTF_ARGS
    SourceLine: -1
    SinkLine: 18
    Comment: 缺少 printf 格式说明符的参数
*/

#include <stdio.h>

int MISSING_PRINTF_ARGS_BAD() 
{
    char* name = "Alice";
    int age = 30;
    printf("Name %s"); //缺陷点：缺少了一个 %s 对 name 参数的格式说明符
    return 0;
}

int MISSING_PRINTF_ARGS_GOOD() 
{
    char* name = "Alice";
    int age = 30;
    printf("Name %s", name); //修复点：添加 %s 对 name 参数的格式说明符
    return 0;
}