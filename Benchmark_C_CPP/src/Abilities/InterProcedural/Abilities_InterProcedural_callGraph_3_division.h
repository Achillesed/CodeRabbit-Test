#ifndef _CG_BASE_DIVISION_H

#define _CG_BASE_DIVISION_H

#include "Abilities_InterProcedural_callGraph_3_base.h"

#endif

class Division: public Base
{
    public:

        Division() = default;

        Division(int v): Base(v){}

        int calculate(int i) override;
};
