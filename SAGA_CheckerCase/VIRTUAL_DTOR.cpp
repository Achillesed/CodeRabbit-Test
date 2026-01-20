/**
    Filename: VIRTUAL_DTOR.cpp
    Vuln: VIRTUAL_DTOR
    SourceLine: -1
    SinkLine: 23
    Comment: 非虚析构函数
*/

#include <iostream>
using namespace std;

struct A {};
struct B: public A 
{
    B(): p(new int) {}
    ~B() { delete p; }
    int *p;
};
void VIRTUAL_DTOR_BAD() 
{
    A *a = new B;   //缺陷点：当通过指向基类A的指针a删除派生类B的对象时，C++默认情况下不会调用派生类B的析构函数，而是调用基类A的析构函数。
                    //由于A没有定义析构函数，C++会自动生成一个默认的析构函数，该析构函数不会执行任何操作。
    delete a;
}


struct C {
    virtual ~C() {}     // 声明虚析构函数
};
struct D: public C
{
    D(): p(new int) {}
    ~D() { delete p; }
    int *p;
};
void VIRTUAL_DTOR_GOOD() 
{
    C *c = new D;
    delete c;   //修复点：在基类C中声明虚析构函数virtual ~C() {}，确保在通过指向C的指针删除派生类对象时，动态绑定机制生效，调用派生类D的析构函数。
}