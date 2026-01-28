int *Abilities_InterProcedural_callGraph_1_returnNull(int i)
{
    return (int *)0;
}

int Abilities_InterProcedural_callGraph_1_bad_main()
{
    int data, *ptr;

    int *(*fun)(int);

    data = 2;

    fun = Abilities_InterProcedural_callGraph_1_returnNull;

    ptr = fun(data);

    data = *ptr;

    return data;
}
