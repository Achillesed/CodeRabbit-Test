#include <iostream>

template<typename T>
T dereference(T* ptr) {
    return *ptr; // 如果ptr为nullptr，则这里会有未定义行为
}

int Features_Language_Template_bad() {
    int* intPtr = nullptr; // Source
    int value = dereference(intPtr); //Sink
    return value;
}

int Features_Language_Template_good() {
    int* intPtr = new int(1); 
    int value = dereference(intPtr); 
    delete intPtr;
    return value;
}