#ifndef _CG_BASE_H

#define _CG_BASE_H

#include "Abilities_InterProcedural_callGraph_3_base.h"

#endif

class Addition: public Base
{
    public:

        Addition() = default;

        Addition(int v): Base(v){}

        int calculate(int i) override;
};
