#include <string.h>
#include "benchmark.h"
void Abilities_Env_Strcpy_cond_bad()
{
    char *src = (char*)malloc(1000*sizeof(char));
    //src = "Hello World!";
    scanf("%s",src);
    src[999] = '\0';
    char *dest = (char*)malloc(1000*sizeof(char));
    strcpy(dest, src);
    int *source = NULL;
    if(strlen(src) == 5)
    {
        source = (int*)alloca(1000);
    }
    int sink;
    if(strlen(dest) != 5 )
        sink = *source;          // 当strlen(src) != 5 时,有空指针解引用
    (void)sink;
    free(src);
    free(dest);
}

void Abilities_Env_Strcpy_cond_good()
{
    char *src = (char*)malloc(1000*sizeof(char));
    //src = "Hello World!";
    scanf("%s",src);
    src[999] = '\0';
    char *dest = (char*)malloc(1000*sizeof(char));
    strcpy(dest, src);
    int *source = NULL;
    if(strlen(src) == 5)
    {
        source = (int*)alloca(1000);
    }
    int sink;
    if(strlen(dest) == 5)
        sink = *source;          // 没有空指针解引用
    (void)sink;
    free(src);
    free(dest);
}

int main()
{
    Abilities_Env_Strcpy_cond_bad();
    Abilities_Env_Strcpy_cond_good();
}