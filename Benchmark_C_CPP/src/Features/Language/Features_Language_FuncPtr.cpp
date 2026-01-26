#include <iostream>
struct box {
  int *p;

  box() {
    p = NULL; //source
  }
  ~box() {
    delete p;
  }
};

void Features_Language_FuncPtr_bad() {
  auto fn = [c = box()] {std::cout<<*(c.p);}; // NPD
  fn();
}

void Features_Language_FuncPtr_good() {
  auto fn = [c = box()](int* param) {
    if(c.p){
      std::cout<<*(c.p);
    }else{
      std::cout<<*param;
    }
  };
  fn(new int(2));
}

int main(){
  Features_Language_FuncPtr_good();
}