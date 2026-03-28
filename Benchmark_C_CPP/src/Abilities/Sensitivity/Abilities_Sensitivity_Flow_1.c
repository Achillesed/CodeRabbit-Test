//流敏感指针分析
#include "benchmark.h"
int Abilities_Sensitivity_Flow_1_Snk(int** p)
{
	return **p;   // Sink: 空指针解引用 (Null Pointer Dereference, CWE476)
}

void Abilities_Sensitivity_Flow_1_bad_Src(int ***p)
{
	*p = NULL;    //Source: 指针a为null
}

void Abilities_Sensitivity_Flow_1_good_Src(int ***p)
{
    int x = 1;
	int *a = &x;
	*p = &a;
}

int Abilities_Sensitivity_Flow_1_bad_main()
{
	int* a;
	int* b;
	int** c;

	c = &a;
	c = &b;
	Abilities_Sensitivity_Flow_1_bad_Src(&c);
	int x = Abilities_Sensitivity_Flow_1_Snk(c);
}

int Abilities_Sensitivity_Flow_1_good_main()
{
	int* a;
	int* b;
	int** c;

	c = &a;
	c = &b;
	Abilities_Sensitivity_Flow_1_good_Src(&c);
	int x = Abilities_Sensitivity_Flow_1_Snk(c);
}
