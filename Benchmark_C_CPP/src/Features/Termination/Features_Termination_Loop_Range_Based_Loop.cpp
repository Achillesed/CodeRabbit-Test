#include <benchmark.h>
#include <array>

struct A {
    explicit A(int& i) : data(&i) { // Store the address of i
    }
    void foo() const {
        for (auto& i : std::array<int*, 1>{data}) // Create a temporary array of pointers for iteration
            (*i)++; // Dereference the pointer to increment the value
    }
    int* data; // Pointer to an int
};

int Features_Termination_Loop_Range_Based_Loop_good() {
    int i = -1;
    A a{i}; // Pass i by reference
    i = 0;
    a.foo(); // Increments i to 1
    return 1 / i; // Returns 1 since i is now 1
}

int Features_Termination_Loop_Range_Based_Loop_bad() {
    int i = -1;
    A a{i}; // Pass i by reference
    i = -1;
    a.foo(); // Increments i to 0
    return 1 / i; // 除零 (Divide By Zero, CWE369)
}
