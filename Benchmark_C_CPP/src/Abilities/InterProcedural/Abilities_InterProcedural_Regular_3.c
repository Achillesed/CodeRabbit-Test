#include <stdio.h>

int *Abilities_InterProcedural_Regular_3_return(int flag, int *param0, int *param1)
{
    return flag == 0 ? param0 : param1;
}


int Abilities_InterProcedural_Regular_3_bad_main()
{
    int data, flag, *ptr;

    data = 1;

    scanf("%d", &flag);

    ptr = Abilities_InterProcedural_Regular_3_return(flag, (int*)0, &data);         //Source, 实参(int*)0

    *ptr = 2;           //Sink, NPD, cwe-476

    return data;
}
