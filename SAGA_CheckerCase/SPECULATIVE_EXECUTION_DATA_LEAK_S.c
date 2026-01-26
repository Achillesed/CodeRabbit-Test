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
/**
 * Demonstrates a speculative-execution-dependent memory access that can cause data leakage.
 *
 * @param array_size Upper bound used in the runtime check that guards the subsequent access.
 * @param index Index used to read from a local buffer and then index a second buffer based on that value.
 */
void SPECULATIVE_EXECUTION_DATA_LEAK_S_BAD(int array_size, int index)
{
	char arr1[105] = {0};
	char arr2[104] = {0};
	if(index < array_size) 
    {
		int i = arr2[arr1[index]];
	}
}

/**
 * Demonstrates a speculative-execution-safe access pattern by serializing execution
 * before performing a data-dependent memory access.
 *
 * @param array_size Upper bound used to validate `index` before the access.
 * @param index Index into the local `arr1` buffer whose value is used to index `arr2`.
 */
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