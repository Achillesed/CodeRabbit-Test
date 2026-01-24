#include <math.h>

double returnZero()
{
    return 0.0;
}

void FLOAT_NAN_S_BAD(){
    double value = returnZero();
    double result = log(value); // 违规
}

void FLOAT_NAN_S_GOOD(){
    double value = returnZero();
    if(value > 0.0)
    {
        double result = log(value);  // 不违规
    }
}
