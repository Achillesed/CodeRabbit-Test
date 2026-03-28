void Abilities_InterProcedural_Param_2a_swap(int *param0, int *param1)
{
    int tmp = *param0;

    *param0 = *param1;

    *param1 = tmp;
}

int Abilities_InterProcedural_Param_2a_bad_main()
{
    int data0, data1, *ptr0, *ptr1;

    data0 = 0;              //Source

    data1 = 1;

    ptr0 = &data0;

    ptr1 = &data1;

    Abilities_InterProcedural_Param_2a_swap(ptr0, ptr1);

    return 1/data1;         //Sink, divide by zero, cwe-369
}

