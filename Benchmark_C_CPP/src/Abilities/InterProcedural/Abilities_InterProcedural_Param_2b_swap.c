void Abilities_InterProcedural_Param_2b_swap(int **param0, int **param1)
{
    int *tmp = *param0;

    *param0 = *param1;

    *param1 = tmp;
}

int Abilities_InterProcedural_Param_2b_bad_main()
{
    int data, *ptr0, *ptr1;

    data = 1;

    ptr0 = (int *)0;        //Source

    ptr1 = &data;

    Abilities_InterProcedural_Param_2b_swap(&ptr0, &ptr1);

    *ptr1 = 2;              //Sink, NPD, CWE476

    return data;
}

