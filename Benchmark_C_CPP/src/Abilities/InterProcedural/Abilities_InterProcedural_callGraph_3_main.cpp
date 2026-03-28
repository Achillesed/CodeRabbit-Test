#include "Abilities_InterProcedural_callGraph_3_base.h"
#include "Abilities_InterProcedural_callGraph_3_addition.h"
#include "Abilities_InterProcedural_callGraph_3_division.h"

#include <iostream>

int Abilities_InterProcedural_callGraph_3_main()
{
    int flag;

    Base *b;

    std::cin >> flag;

    if(flag == 0)
    {
        b = new Addition(123);
    }
    else
    {
        b = new Division(456);
    }

    flag =  b->calculate(0);

    return flag;
}
