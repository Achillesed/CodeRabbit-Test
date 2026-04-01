#include <iostream>
#include <exception>
int Features_Language_TryCatch_bad() {
    int* ptr = nullptr; // source

    try {
        throw std::runtime_error("Failed to complete initialization.");
        ptr = new int(10); 
        *ptr = 10;
    } catch (const std::exception& e) {
        //do nothing
    }

    return *ptr; //Sink: null pointer dereference
}

int Features_Language_TryCatch_good() {
    int* ptr = nullptr;

    try {
        throw std::runtime_error("Failed to complete initialization.");
        ptr = new int(10); 
        *ptr = 10;
    } catch (const std::exception& e) {
        if (ptr == nullptr) {
            ptr = new int(10); 
            *ptr = 10;
        }
    }
    return *ptr;
}