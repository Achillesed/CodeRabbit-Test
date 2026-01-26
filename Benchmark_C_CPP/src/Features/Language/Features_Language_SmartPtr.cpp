#include <memory>

class Divider {
public:
    int divisor;

    Divider(int divisor) : divisor(divisor) {}

    int divide(int dividend) {
        return dividend / this->divisor;
    }
};

int Features_Language_SmartPtr_bad() {
    std::unique_ptr<Divider> divider = std::make_unique<Divider>(0); // source
    int dividend = 10;
    int result = divider->divide(dividend); //sink 除零错误
    return result;
}

int Features_Language_SmartPtr_good() {
    std::unique_ptr<Divider> divider = std::make_unique<Divider>(1);
    int dividend = 10;
    int result = divider->divide(dividend);
    return result;
}

