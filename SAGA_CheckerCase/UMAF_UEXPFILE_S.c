/**
    Filename: UMAF_UEXPFILE_S.c
    Vuln: UMAF_UEXPFILE_S
    SourceLine: -1
    SinkLine: 20
    Comment: 使用过期的文件描述符
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates a use-after-close by writing to a FILE* after it has been closed.
 *
 * Opens "1.txt" for writing, closes the stream, then attempts to write to the closed stream,
 * which may cause undefined behavior.
 *
 * @returns 0 on completion.
 */
int UMAF_UEXPFILE_S_BAD(void) 
{
    FILE * file ;
    file = NULL;
    file = fopen("1.txt","w+");
    if(file != NULL)
    {
        fclose(file);
        fprintf(file,"example string\n");   //缺陷点：关闭了文件句柄之后使用文件
    }
    return 0;
}

/**
 * Open and close the file "1.txt" without performing any operations after the stream is closed.
 *
 * The function opens "1.txt" with mode "w+" (creating or truncating the file) and closes the stream if opened,
 * avoiding use-after-close on the FILE pointer.
 *
 * @returns Always returns 0.
 */
int UMAF_UEXPFILE_S_GOOD(void) 
{
    FILE * file ;
    file = NULL;
    file = fopen("1.txt","w+");
    if(file != NULL)
    {
        fclose(file);   //修复点
    }
    return 0;
}