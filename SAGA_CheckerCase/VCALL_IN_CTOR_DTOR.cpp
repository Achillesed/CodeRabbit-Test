/**
    Filename: VCALL_IN_CTOR_DTOR.cpp
    Vuln: VCALL_IN_CTOR_DTOR
    SourceLine: -1
    SinkLine: 18
    Comment: 对虚拟方法的错误调用
*/

#include <iostream>
using namespace std;

class A
{
public:
    A() {
        virtMethod();
    }
    virtual ~A();
    virtual void virtMethod() {
        cout << "A::virtMethod";
    }
};

class B: public A
{
public:
    B();
    virtual ~B();
    virtual void virtMethod() {
        cout << "B::virtMethod";
    }
};

int VCALL_IN_CTOR_DTOR_BAD() {
    B b; // 缺陷点：构造函数中调用虚方法时，C++使用静态绑定而不是动态绑定，导致调用的是父类的虚方法而不是子类的重写方法。
    return 0;
}
 
 class C
{
public:
    C() {}
    virtual ~C();
    virtual void virtMethod() {
        cout << "C::virtMethod";
    }
};

class D: public C
{
public:
    D();
    virtual ~D();
    virtual void virtMethod() {
        cout << "D::virtMethod";
    }
};

int VCALL_IN_CTOR_DTOR_GOOD() {
    D d; // 修复点：不在构造函数中直接调用虚方法
    return 0;
}
 