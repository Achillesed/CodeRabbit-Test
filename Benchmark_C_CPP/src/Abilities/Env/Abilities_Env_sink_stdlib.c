#include "benchmark.h"
#include "string.h"

void Abilities_Env_sink_stdlib_printf_bad1()
{
	char *source = malloc(100);      // malloc
	scanf("%s", source); 
	free(source);                    // free
	printf("%s", source);            // use after free(bad)
}

void Abilities_Env_sink_stdlib_printf_good1()
{
	char *source = malloc(100);      // malloc
	scanf("%s", source);
	printf("%s", source);            // use before free(good)
	free(source);                    // free
}

void Abilities_Env_sink_stdlib_strlen_bad1()
{
    char *source = NULL;
    //scanf("%s", &s);
    int len = strlen(source);				// sink in strlen()
    (void)len;
}

#define SZ 10

void Abilities_Env_sink_stdlib_memcpy_bad()
{

	int i ;
	scanf("%d", &i);
	char dest[SZ],src[SZ+SZ];
	if(0<i && i <= SZ+SZ)
	{
		memcpy(dest, src, i);				// stack base buffer overflow
	}
}

void Abilities_Env_sink_stdlib_loop_memcpy_bad()
{

	int i ;
	char dest[SZ],src[SZ+SZ];
	for( i = 0 ; i <= SZ+SZ; i++)
	{
		memcpy(dest, src, i);				// stack base buffer overflow ( 0 < i < 20)
	}
}

void Abilities_Env_sink_stdlib_main()
{
    Abilities_Env_sink_stdlib_printf_bad1();
    Abilities_Env_sink_stdlib_printf_good1();
    Abilities_Env_sink_stdlib_strlen_bad1();
	Abilities_Env_sink_stdlib_memcpy_bad();
	Abilities_Env_sink_stdlib_loop_memcpy_bad();
}