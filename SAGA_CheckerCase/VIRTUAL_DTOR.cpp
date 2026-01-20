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
    /**
 * @brief Constructs B and allocates an integer for member `p`.
 *
 * Allocates a new `int` on the heap and stores its pointer in `p`. The constructed object owns the allocated memory and is responsible for releasing it in its destructor.
 */
B(): p(new int) {}
    /**
 * @brief Releases the heap-allocated integer owned by this instance.
 *
 * Deletes the pointer member `p` to free the associated memory.
 */
~B() { delete p; }
    int *p;
};
/**
 * @brief Demonstrates deleting a derived object through a base pointer when the base has no virtual destructor.
 *
 * This function shows the defect where deleting a B object via an A* does not invoke B's destructor because A lacks a virtual destructor,
 * which can prevent cleanup in the derived class and lead to undefined behavior or resource leaks.
 */
void VIRTUAL_DTOR_BAD() 
{
    A *a = new B;   //缺陷点：当通过指向基类A的指针a删除派生类B的对象时，C++默认情况下不会调用派生类B的析构函数，而是调用基类A的析构函数。
                    //由于A没有定义析构函数，C++会自动生成一个默认的析构函数，该析构函数不会执行任何操作。
    delete a;
}


struct C {
    /**
 * @brief Virtual destructor for base class C to ensure derived destructors are invoked when deleted via a base pointer.
 *
 * Ensures proper resource cleanup through dynamic binding when objects of derived classes are deleted through a pointer to C.
 */
virtual ~C() {}     // 声明虚析构函数
};
struct D: public C
{
    /**
 * @brief Constructs D and allocates an int for member `p`.
 *
 * The constructor initializes the member pointer `p` by allocating a new `int`.
 */
D(): p(new int) {}
    /**
 * @brief Releases resources owned by D.
 *
 * Deletes the dynamically allocated integer pointed to by `p`.
 */
~D() { delete p; }
    int *p;
};
/**
 * @brief Demonstrates safe deletion of a derived object through a base-class pointer.
 *
 * Creates a D instance via a C pointer and deletes it through that pointer to ensure
 * D's destructor is invoked because C declares a virtual destructor.
 */
void VIRTUAL_DTOR_GOOD() 
{
    C *c = new D;
    delete c;   //修复点：在基类C中声明虚析构函数virtual ~C() {}，确保在通过指向C的指针删除派生类对象时，动态绑定机制生效，调用派生类D的析构函数。
}