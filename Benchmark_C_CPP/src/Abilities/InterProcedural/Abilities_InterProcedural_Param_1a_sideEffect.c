void Abilities_InterProcedural_Param_1a_sideEffect(int *param)
{
    *param = 0;         //Source
}

int Abilities_InterProcedural_Param_1a_bad_main()
{
    int data, *ptr;

    data = 1;

    ptr = &data;

    Abilities_InterProcedural_Param_1a_sideEffect(ptr);

    return 1/data;      //Sink, divide by zero, cwe-369
}
