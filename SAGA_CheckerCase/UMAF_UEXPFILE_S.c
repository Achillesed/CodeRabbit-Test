/**
    Filename: UMAF_UEXPFILE_S.c
    Vuln: UMAF_UEXPFILE_S
    SourceLine: -1
    SinkLine: 20
    Comment: 使用过期的文件描述符
*/

#include <stdio.h>
#include <stdlib.h>

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