#include <iostream>
#include <algorithm>

class Widget {
public:
    void doWork() const {
        std::cout << "Widget is doing work." << std::endl;
    }
};

int Features_DataType_Array_bad() {
    Widget* widget1 = new Widget();
    Widget* widget2 = nullptr; // Source: nullptr 
    Widget* widget3 = new Widget();

    Widget* widgets[] = {widget1, widget2, widget3};
    
    // 使用lambda表达式遍历数组
    std::for_each(std::begin(widgets), std::end(widgets), [](Widget* w) {
        w->doWork(); // sink: 如果w是nullptr，这里会产生空指针解引用
    });

    delete widget1;
    delete widget3;

    return 0;
}

int Features_DataType_Array_good() {
    Widget* widget1 = new Widget();
    Widget* widget2 = nullptr; 
    Widget* widget3 = new Widget();

    Widget* widgets[] = {widget1, widget2, widget3};
    
    // 使用lambda表达式遍历数组
    std::for_each(std::begin(widgets), std::end(widgets), [](Widget* w) {
        if(w != nullptr)
            w->doWork(); 
    });

    delete widget1;
    delete widget3;

    return 0;
}