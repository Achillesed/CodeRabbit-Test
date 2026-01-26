#include <stdio.h>

int Abilities_InterProcedural_callGraph_2_returnZero()
{
    return 0;
}

int Abilities_InterProcedural_callGraph_2_returnNegative()
{
    return -1;
}

int Abilities_InterProcedural_callGraph_2_bad_main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    int flag, index;

    int (*fptr)();

    scanf("%d", &flag);

    if(flag == 0)
    {
        fptr = Abilities_InterProcedural_callGraph_2_returnZero;
    }
    else
    {
        fptr = Abilities_InterProcedural_callGraph_2_returnNegative;
    }

    index = fptr();

    return arr[index];                  //cwe-125, out-of-bounds read
}
