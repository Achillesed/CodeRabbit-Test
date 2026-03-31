/**
    Filename: SPECULATIVE_EXECUTION_DATA_LEAK_S.c
    Vuln: SPECULATIVE_EXECUTION_DATA_LEAK_S
    SourceLine: -1
    SinkLine: 18
    Comment: 推测的执行数据泄露
*/

#include <stdio.h>
#include <stdlib.h>
#include <emmintrin.h>
void SPECULATIVE_EXECUTION_DATA_LEAK_S_BAD(int array_size, int index)
{
	char arr1[105] = {0};
	char arr2[104] = {0};
	if(index < array_size) 
    {
		int i = arr2[arr1[index]];
	}
}

void SPECULATIVE_EXECUTION_DATA_LEAK_S_GOOD(int array_size, int index)
{
	char arr1[105] = {0};
	char arr2[104] = {0};
	if(index < array_size) 
    {
        _mm_lfence();
		int i = arr2[arr1[index]];
	}
}
