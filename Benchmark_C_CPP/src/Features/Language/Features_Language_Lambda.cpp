#include <memory>
#include <iostream>
#include <algorithm>
#include <array>

int Features_Language_Lambda_bad0(int a) {
    int* p = nullptr; // source
    auto mayAccessResource = [](int x) -> bool {
        x = x * 3;
        if(x > 0){
            return true;
        }else{
            return false;
        }
    };

    if (mayAccessResource(a)) {
        return *p; //NPD
    } else {

        return 0;
    }
}

int Features_Language_Lambda_good0(int a) {
    int* p = new int(1); 
    auto mayAccessResource = [](int x) -> bool {
        x = x * 3;
        if(x > 0){
            return true;
        }else{
            return false;
        }
    };

    if (mayAccessResource(a)) {
        int ret = *p;
        delete p;
        return ret;
    } else {
        delete p;
        return 0;
    }
}


int Features_Language_Lambda_bad1() {
    int* w1 = new int(1); 
    int* w2 = nullptr; //Source: 空指针

    // 定义lambda表达式，不检查空指针
    auto displayInt = [](int* w) {
        std::cout<<*w; // 如果w是nullptr，这里会触发空指针解引用
    };

    displayInt(w1);
    displayInt(w2); // Sink

    delete w1; // 清理资源，w2是空指针，所以不需要删除
    return 0;
}

int Features_Language_Lambda_good1() {
    int* w1 = new int(1); 
    int* w2 = nullptr; //Source: 空指针

    // 定义lambda表达式，检查空指针
    auto displayInt = [](int* w) {
        if(w != nullptr)
            std::cout<<*w; // 如果w是nullptr，这里会触发空指针解引用
    };

    displayInt(w1);
    displayInt(w2); // Sink

    delete w1; // 清理资源，w2是空指针，所以不需要删除
    return 0;
}
