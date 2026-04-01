int Abilities_InterProcedural_summary_1_divideByZero(int i)
{
    int mod = i%4;

    return i/mod;
}

int Abilities_InterProcedural_summary_1_main()
{
    int i, j;

    for(i = 1; i < 100; i++)
    {
        j = i + 3;

        j = Abilities_InterProcedural_summary_1_divideByZero(j);
    }

    Abilities_InterProcedural_summary_1_divideByZero(201);

    Abilities_InterProcedural_summary_1_divideByZero(202);

    Abilities_InterProcedural_summary_1_divideByZero(203);

    Abilities_InterProcedural_summary_1_divideByZero(204);

    Abilities_InterProcedural_summary_1_divideByZero(205);

    Abilities_InterProcedural_summary_1_divideByZero(206);

    Abilities_InterProcedural_summary_1_divideByZero(207);

    Abilities_InterProcedural_summary_1_divideByZero(208);

    Abilities_InterProcedural_summary_1_divideByZero(209);

    Abilities_InterProcedural_summary_1_divideByZero(301);

    Abilities_InterProcedural_summary_1_divideByZero(302);

    Abilities_InterProcedural_summary_1_divideByZero(303);

    Abilities_InterProcedural_summary_1_divideByZero(304);

    Abilities_InterProcedural_summary_1_divideByZero(305);

    Abilities_InterProcedural_summary_1_divideByZero(306);

    Abilities_InterProcedural_summary_1_divideByZero(307);

    Abilities_InterProcedural_summary_1_divideByZero(308);

    Abilities_InterProcedural_summary_1_divideByZero(309);


    for(; i > 0; i--)
    {
        j = i + 5;

        j = Abilities_InterProcedural_summary_1_divideByZero(j);
    }

    return j;
}
