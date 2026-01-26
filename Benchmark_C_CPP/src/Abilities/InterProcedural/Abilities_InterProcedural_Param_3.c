#include <stdlib.h>

void Abilities_InterProcedural_Param_3_free(int *param0, int *param1)
{
    free(param0);

    free(param1);                                           //cwe-415, double free。报告点位在这里还是在第18行的函数调用点处，不同的检测工具可能有不同的处理。
}

int Abilities_InterProcedural_Param_3_bad_main()
{
    int *ptr;

    ptr = (int *)malloc(sizeof(int));

    if(ptr == NULL) return -1;

    Abilities_InterProcedural_Param_3_free(ptr, ptr);       //cwe-415, double free。报告点位在这里还是在第7行，不同的检测工具可能有不同的处理。

    return 0;
}

int Abilities_InterProcedural_Param_3_good_main()
{
    int *ptr0, *ptr1;

    ptr0 = (int *)malloc(sizeof(int));

    if(ptr0 == NULL) return -1;

    ptr1 = (int *)malloc(sizeof(int));

    if(ptr1 == NULL) return -1;

    Abilities_InterProcedural_Param_3_free(ptr0, ptr1);

    return 0;
}
