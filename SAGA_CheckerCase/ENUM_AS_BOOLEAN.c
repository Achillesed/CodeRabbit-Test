/**
    Filename: ENUM_AS_BOOLEAN.c
    Vuln: ENUM_AS_BOOLEAN
    SourceLine: -1
    SinkLine: 21
    Comment: 滥用了枚举
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum{
	TRIG_0000,
	TRIG_0001,
	TRIG_0002,
	TRIG_0003
}TRIG_TYPE_ENUM;

/**
 * Demonstrates an incorrect use of a TRIG_TYPE_ENUM value as a boolean condition.
 *
 * Evaluates `mTrig` in a boolean context and executes the action block when `mTrig` is non-zero;
 * this is ambiguous when the enum defines multiple non-zero values and can hide logical intent.
 *
 * @param mTrig Enum value being evaluated as a boolean.
 */
void ENUM_AS_BOOLEAN_BAD(TRIG_TYPE_ENUM mTrig) 
{
	if (mTrig)      //缺陷点：枚举值有三个以上，但是被用作bool表达式
	{
		/* do something */
	}
}

/**
 * Execute the action when the provided trigger value is not TRIG_0000.
 *
 * @param mTrig Trigger value to evaluate; the function performs the action if `mTrig` is not `TRIG_0000`.
 */
void ENUM_AS_BOOLEAN_GOOD(TRIG_TYPE_ENUM mTrig) 
{
	if (mTrig != TRIG_0000)      //修复点
	{
		/* do something */
	}
}