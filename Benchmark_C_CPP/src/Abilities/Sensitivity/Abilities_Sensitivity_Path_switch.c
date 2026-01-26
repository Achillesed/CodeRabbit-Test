#include "benchmark.h"

void Abilities_Sensitivity_Path_Switch_good(int cond, int* p)
{
	switch(cond)
	{
		case 1:
			p = &cond;
			break;
		default:
			cond = *p; // NO NPD
	}
}
void Abilities_Sensitivity_Path_Switch_bad(int cond, int* p)
{
	switch(cond)
	{
		case 1:
			p = &cond;
			break;
		default:
			cond = *p; // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
	}
}

int Abilities_Sensitivity_Path_Switch_main(){
    int *p = NULL; // Source: 空指针
    Abilities_Sensitivity_Path_Switch_good(1, p);
    Abilities_Sensitivity_Path_Switch_bad(0, p);
}