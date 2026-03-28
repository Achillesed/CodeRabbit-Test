#include "benchmark.h"
#include "string.h"
void Abilities_Env_source_stdlib_malloc_good()
{
    int *source = malloc(100);
    if(source == NULL)
        return ;
    int load = *source;
    (void)load;
    free(source);
}

void Abilities_Env_source_stdlib_malloc_bad()
{
    int *source = malloc(100);
    int load = *source;             // malloc返回值可能为空,会导致空指针解引用 
    (void)load;
    free(source);
}

void Abilities_Env_source_stdlib_scanf_good()
{
    int source ;
    scanf("%d",&source);            // source可能为0 
    if(source == 0)
        return ;
    float load = 3.1415926/source;      // 除数不为零 
    (void)load;
}

void Abilities_Env_source_stdlib_scanf_bad()
{
    int source ;
    scanf("%d",&source);             // source可能为0 
    float load = 3.1415926/source;   // 除数可能为零
    (void)load;
}

void Abilities_Env_source_stdlib_strlen_good()
{
    char strings[1000];
    scanf("%s",strings);             
    size_t source = strlen(strings);    // source可能为0 
    if(source == 0 )
        return ;
    float load = 3.1415926/source;      // 除数不可能为零
    (void)load;
}

void Abilities_Env_source_stdlib_strlen_bad()
{
    char strings[1000];
    scanf("%s",strings);
    size_t source = strlen(strings);    // source可能为0 

    float load = 3.1415926/source;      // 除数可能为零
    (void)load;
}


void Abilities_Env_source_stdlib_main()
{
    Abilities_Env_source_stdlib_malloc_bad();
    Abilities_Env_source_stdlib_malloc_good();
    Abilities_Env_source_stdlib_scanf_bad();
    Abilities_Env_source_stdlib_scanf_good();
    Abilities_Env_source_stdlib_strlen_good();
    Abilities_Env_source_stdlib_strlen_bad();
}