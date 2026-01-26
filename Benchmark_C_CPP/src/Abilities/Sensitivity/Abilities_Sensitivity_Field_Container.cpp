#include "benchmark.h"
#include <vector>
#include <iostream>

int Abilities_Sensitivity_Field_Container_bad1(int n) {
    int res = 0;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(n);
    vec.push_back(4);
    vec.push_back(5);

    if (n > 0 && n < 10) {
        res = 10 / (vec[2] - 3);
    }
    
    return res;
}

int Abilities_Sensitivity_Field_Container_bad2(int n) {
    int res = 0;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    if (n > 0 && n < 10) {
        res = 10 / (vec[2] - 3);
    }
    
    return res;
}

int Abilities_Sensitivity_Field_Container_good(int n) {
    int res = 0;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(n);
    vec.push_back(4);
    vec.push_back(5);

    if (n > 0 && n < 10) {
        res = 10 / (vec[4] - 3);
    }
    
    return res;
}

int Abilities_Sensitivity_Field_Container_bad1_main() {
    int input;
    scanf("%d\n", &input); 
    return Abilities_Sensitivity_Field_Container_bad1(input);
}

int Abilities_Sensitivity_Field_Container_bad2_main() {
    int input;
    scanf("%d\n", &input); 
    return Abilities_Sensitivity_Field_Container_bad2(input);
}

int Abilities_Sensitivity_Field_Container_good_main() {
    int input;
    scanf("%d\n", &input); 
    return Abilities_Sensitivity_Field_Container_good(input);
}