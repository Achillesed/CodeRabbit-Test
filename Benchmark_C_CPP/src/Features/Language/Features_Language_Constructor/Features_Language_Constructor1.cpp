// 测试对于构造函数和析构函数的隐式调用能否正确处理
#include "Features_Language_Constructor.h"
int Features_Language_Constructor_good( ) //FP: memory-leak
{
    ABC abc(1); //隐式地调用了构造函数ABC
    abc.print();
    return 0; //隐式地调用了析构函数~ABC
}

int Features_Language_Constructor_bad( ) 
{
    ABC abc(1); //隐式地调用了构造函数ABC
    abc.print();
    delete abc.data; //source: free abc.data
    return 0; //sink：隐式地调用了析构函数~ABC，double free abc.data
}