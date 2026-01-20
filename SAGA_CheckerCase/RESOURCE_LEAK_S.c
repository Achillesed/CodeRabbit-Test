/**
    Filename: RESOURCE_LEAK_S.c
    Vuln: RESOURCE_LEAK_S
    SourceLine: -1
    SinkLine: 16
    Comment: 文件使用后未关闭
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates opening a file without closing it, causing a resource leak.
 *
 * Opens "BadSource_fopen.txt" in "w+" mode and leaves the resulting FILE* unclosed.
 */
void RESOURCE_LEAK_S_BAD() 
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+"); // 缺陷点：文件使用后未关闭
    /* do something */
}

/**
 * Open "BadSource_fopen.txt" for read/write and ensure the file is closed.
 *
 * Attempts to open "BadSource_fopen.txt" with mode "w+"; if the open fails the
 * function returns immediately. If the file is opened successfully, it is
 * closed with fclose() after use to avoid a resource leak.
 */
void RESOURCE_LEAK_S_GOOD() 
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+"); // 修复点：后续存在关闭
    if(!data) return;
    /* do something */
    fclose(data);
}