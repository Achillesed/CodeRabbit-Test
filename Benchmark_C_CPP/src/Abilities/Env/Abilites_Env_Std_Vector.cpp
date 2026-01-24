#include <iostream>
#include <vector>

class Widget {
public:
    void doWork() const {
        std::cout << "Widget is doing work." << std::endl;
    }
};

int Abilites_Env_Std_Vector_bad() {
    std::vector<Widget*> widgets{new Widget(), nullptr, new Widget()}; // Souce: widgets contains nullptr
    
    for (auto w : widgets) {
        w->doWork(); // Sink: NPD
    }

    for(auto& w : widgets) {
        delete w; 
    }
    widgets.clear();

    return 0;
}

int Abilites_Env_Std_Vector_good() {
    std::vector<Widget*> widgets{new Widget(), nullptr, new Widget()}; // Souce: widgets contains nullptr
    
    for (auto w : widgets) {
        if(w)
            w->doWork(); // Sink: NPD
    }

    for(auto& w : widgets) {
        delete w; 
    }
    widgets.clear();

    return 0;
}
