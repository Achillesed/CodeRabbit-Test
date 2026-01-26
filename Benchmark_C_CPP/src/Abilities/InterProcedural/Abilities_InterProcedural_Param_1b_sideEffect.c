void Abilities_InterProcedural_Param_1b_sideEffect(int **param)
{
    *param = (int *)0;      //Source
}

int Abilities_InterProcedural_Param_1b_bad_main()
{
    int data, *ptr;

    data = 1;

    ptr = &data;

    Abilities_InterProcedural_Param_1b_sideEffect(&ptr);

    *ptr = 2;               //Sink, NPD, CWE476

    return data;
}
