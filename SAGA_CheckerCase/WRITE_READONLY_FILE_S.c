/**
    Filename: WRITE_READONLY_FILE_S.c
    Vuln: WRITE_READONLY_FILE_S
    SourceLine: -1
    SinkLine: 14
    Comment: Rule 22.4（强制）不得试图写入以只读方式打开的流 [MISRAC2012-RULE_22_4]
*/

#include <stdio.h>
void WRITE_READONLY_FILE_S_BAD(void)
{
    FILE *fp = fopen("tmp", "r");
    if(fp != NULL) {
        (void)fprintf(fp, "What happens now?"); //违规点
        (void)fclose(fp);
    }
    
}

#include <stdio.h>
void WRITE_READONLY_FILE_S_GOOD(void)
{
    FILE *fp = fopen("tmp", "r+"); /* 以 读/写 打开文件 */
    if(fp != NULL) {
        (void)fprintf(fp, "What happens now?");  //修复点
        (void)fclose(fp);
    }
}