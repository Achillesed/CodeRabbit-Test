int Abilities_InterProcedural_Param_4_divide(int *param0, int *param1)
{
    int tmp;

    *param0 = 0;

    tmp = *param1;

    return 1/tmp;                                                       //cwe-369, divide by zero。报告点位在这里还是在第22行的函数调用点处，不同的检测工具可能有不同的处理。
}

int Abilities_InterProcedural_Param_4_bad_main()
{
    int data, *ptr0, *ptr1;

    data = 123;

    ptr0 = &data;

    ptr1 = &data;

    data = Abilities_InterProcedural_Param_4_divide(ptr0, ptr1);        //cwe-369, divide by zero。报告点位在这里还是在第9行的，不同的检测工具可能有不同的处理。

    return data;
}


int Abilities_InterProcedural_Param_4_good_main()
{
    int data0, data1, *ptr0, *ptr1;

    data0 = 0;

    data1 = 1;

    ptr0 = &data0;

    ptr1 = &data1;

    data0 = Abilities_InterProcedural_Param_4_divide(ptr0, ptr1);

    return data0;
}
