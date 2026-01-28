#include <stdio.h>

int Abilities_InterProcedural_Regular_2_return(int flag)
{
    return flag == 0? 0 : -1;
}

int Abilities_InterProcedural_Regular_2_bad_main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    int index, flag;

    scanf("%d", &flag);

    index = Abilities_InterProcedural_Regular_2_return(flag);

    return arr[index];          //cwe-125, out-of-bounds read
}
