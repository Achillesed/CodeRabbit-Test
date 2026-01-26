#ifndef _CG_BASE_H

#define _CG_BASE_H

#endif

class Base
{
    public:

        Base() = default;

        Base(int v) : value(v)
        {
        }

        virtual int calculate(int i) = 0;

        virtual ~Base() = default;

    protected:

        int value = 0;
};

