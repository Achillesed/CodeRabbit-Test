/**
    Filename: WRITE_READONLY_FILE_S.c
    Vuln: WRITE_READONLY_FILE_S
    SourceLine: -1
    SinkLine: 14
    Comment: Rule 22.4（强制）不得试图写入以只读方式打开的流 [MISRAC2012-RULE_22_4]
*/

#include <stdio.h>
/**
 * Demonstrates writing to a stream opened for read-only access.
 *
 * Opens the file "tmp" with mode "r"; if the open succeeds, it writes to the resulting stream
 * using fprintf and then closes the stream. This attempts a write on a read-only stream and
 * illustrates a violation of MISRA 2012 Rule 22.4.
 */
void WRITE_READONLY_FILE_S_BAD(void)
{
    FILE *fp = fopen("tmp", "r");
    if(fp != NULL) {
        (void)fprintf(fp, "What happens now?"); //违规点
        (void)fclose(fp);
    }
    
}

#include <stdio.h>
/**
 * Open the file "tmp" in read/write mode and write a fixed message when the open succeeds.
 *
 * If the file is opened successfully with mode "r+", the function writes "What happens now?" to
 * the stream and then closes the file.
 */
void WRITE_READONLY_FILE_S_GOOD(void)
{
    FILE *fp = fopen("tmp", "r+"); /* 以 读/写 打开文件 */
    if(fp != NULL) {
        (void)fprintf(fp, "What happens now?");  //修复点
        (void)fclose(fp);
    }
}