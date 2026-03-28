#include "benchmark.h"
#include "string.h"
void Abilities_env_stdlib_cond_good()
{
    char *arr = malloc(100* sizeof(char));
    arr = "Hello World!"; 
    size_t len = strlen(arr);
    int num = 0 ;
    int *source = NULL;
    if(strlen(arr)) {           // len == strlen(arr),source会被修改(很难不误报)
        source = &num;
    }
    if(len) {
        num = *source;
    }
    free(arr);
}

void Abilities_env_stdlib_cond_bad()
{
    char *arr = malloc(100* sizeof(char));
    arr = "Hello World!"; 
    size_t len = strlen(arr);
    int num = 0 ;
    int *source = NULL;
    arr = "";
    scanf("%s",arr);            // 这时arr被修改,可能导致strlen(arr)为零
    if(strlen(arr)) {
        source = &num;
    }
    if(len) {
        num = *source;
    }
    free(arr);
}

void Abilities_env_stdlib_cond_main()
{
    Abilities_env_stdlib_cond_bad();
    Abilities_env_stdlib_cond_good();
}