/**
    Filename: FORMAT_STRING_S.c
    Vuln: FORMAT_STRING_S
    SourceLine: -1
    SinkLine: 17
    Comment: 使用外部控制的格式字符串
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates unsafe printing by passing an externally controlled string as printf's format specifier.
 *
 * If called with argc == 1, the function reads the PATH environment variable and passes it directly to printf
 * as the format string, which can cause format string vulnerabilities (e.g., unexpected memory access or crashes)
 * when the environment value contains format specifiers.
 *
 * @param argc Controls execution; the environment is printed only when argc == 1.
 * @param argv Unused.
 */
void FORMAT_STRING_S_BAD(int argc,char *argv[])
{ 
    char * environment = getenv("PATH");
    if(argc>0 && argc<2)
    { 
        printf(environment);    //缺陷点：printf 函数会解析传递给它的字符串中的格式说明符，environment来自用户输入，并作为格式化字符串传递给printf
                                //当用户输入的是 "%s%s%s%s%s%s" printf 可能会尝试访问未初始化的内存或未映射的地址，导致程序崩溃或被攻击
        /* do something */
    }
}

/**
 * Safely prints the PATH environment variable when the program is invoked with a single argument.
 *
 * Uses a fixed "%s" format specifier to print the value of the PATH environment variable, preventing uncontrolled format-string usage.
 */
void FORMAT_STRING_S_GOOD(int argc,char *argv[])
{ 
    
    char * environment = getenv("PATH");
    if(argc>0 && argc<2)
    { 
        printf("%s", environment);    //修复点：用 "%s" 将printf() 的格式化字符串确定下来
        /* do something */
    }
}
