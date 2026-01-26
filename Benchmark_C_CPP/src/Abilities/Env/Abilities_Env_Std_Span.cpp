#include <span> // Required for std::span
#include <benchmark.h>
struct A {
    explicit A(int& i) : data(&i, 1) { // Initialize data to span over i
    }
    void foo() const {
        data[0]++; // Directly increment the first (and only) element of the span
    }
    std::span<int> data; // Keep using std::span<int>
};

int Abilities_Env_Std_Span_good() {
    int i = -1;
    A a{i}; // a.data spans over i
    i = 0;
    a.foo(); // Increments i to 1
    return 1 / i; // Returns 1 since i is now 1
}


struct B {
    int* data; // Use a pointer to int instead of std::span

    explicit B(int& i) : data(&i) { // Initialize data to point to i
    }

    void foo() const {
        (*data)++; // Increment the integer pointed by data
    }
};

int Abilities_Env_Std_Span_bad() {
    int i = -1;
    B b{i}; // a.data points to i
    b.foo(); // Increments i to 0
    return 1 / i; // dived by zero
}
