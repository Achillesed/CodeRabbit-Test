#include <iostream>

class Obj {
public: 
    int data;

    Obj(int n) {
        data = n;
    }
};

int Abilities_Sensitivity_Object_Regular_bad1(int n) {
    Obj o1(n);
    Obj o2(10);
    return 100 / (o1.data - 5);
}

int Abilities_Sensitivity_Object_Regular_bad2(int n) {
    Obj o1(n);
    Obj o2(5);
    return 100 / (o2.data - 5);
}

int Abilities_Sensitivity_Object_Regular_good(int n) {
    Obj o1(n);
    Obj o2(10);
    return 100 / (o2.data - 5);
}

int Abilities_Sensitivity_Object_Regular_bad1_main() {
    int input;
    std::cin >> input;
    return Abilities_Sensitivity_Object_Regular_bad1(input);
}

int Abilities_Sensitivity_Object_Regular_bad2_main() {
    int input;
    std::cin >> input;
    return Abilities_Sensitivity_Object_Regular_bad2(input);
}

int Abilities_Sensitivity_Object_Regular_good_main() {
    int input;
    std::cin >> input;
    return Abilities_Sensitivity_Object_Regular_good(input);
}