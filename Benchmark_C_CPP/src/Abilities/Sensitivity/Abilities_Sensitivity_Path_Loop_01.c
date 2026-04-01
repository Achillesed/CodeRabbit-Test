//#issue 15 循环依赖收集
#include "benchmark.h"

void Abilities_Sensitivity_Path_Loop_good_01()
{
    int i;
    int * data;
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        free(data);     //Source
    }
    printf("%d",data[0]);    // No (Use after free, exit)
}
