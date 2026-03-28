#include <iostream>
#include <memory>

class Resource {
public:
    void performTask() {
        std::cout << "Performing a critical task." << std::endl;
    }
};

int Abilites_Env_Std_Move_bad(int param) {
    auto resource = std::make_unique<Resource>();
    auto mayAccessResource = [resource = std::move(resource)](int x) -> bool { //source: resource移动到lambda中
        x = x * 3;
        if(x > 0){
            return true;
        }else{
            return false;
        }
    };

    if (mayAccessResource(param)) {
        resource->performTask();  // sink: Null pointer dereference; 因为resource已经被移动到lambda中
    } else {
        std::cout << "Access denied or resource not available." << std::endl;
    }

    return 0;
}

int Abilites_Env_Std_Move_good(int param) {
    auto resource = std::shared_ptr<Resource>(); //共享资源，而不会遇到所有权被移动的问题。
    auto mayAccessResource = [resource = std::move(resource)](int x) -> bool {
        x = x * 3;
        if(x > 0){
            return true;
        }else{
            return false;
        }
    };

    if (mayAccessResource(param)) {
        resource->performTask(); 
    } else {
        std::cout << "Access denied or resource not available." << std::endl;
    }

    return 0;
}
