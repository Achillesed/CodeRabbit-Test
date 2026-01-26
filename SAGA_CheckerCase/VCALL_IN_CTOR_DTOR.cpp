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
    /**
     * @brief Constructs an A and invokes its virtual method from the constructor.
     *
     * Invokes virtMethod() during construction; because virtual dispatch is limited during construction,
     * the call resolves to A::virtMethod.
     */
    A() {
        virtMethod();
    }
    virtual ~A();
    /**
     * @brief Write the class identifier "A::virtMethod" to standard output.
     *
     * This virtual override prints the text "A::virtMethod" to std::cout.
     */
    virtual void virtMethod() {
        cout << "A::virtMethod";
    }
};

class B: public A
{
public:
    B();
    virtual ~B();
    /**
     * @brief Outputs this class's virtual-method identifier to standard output.
     *
     * Writes the literal string "B::virtMethod" to std::cout.
     */
    virtual void virtMethod() {
        cout << "B::virtMethod";
    }
};

/**
 * @brief Demonstrates the unsafe pattern of invoking a virtual method during construction, causing the base-class implementation to be used.
 *
 * Constructs a B instance to trigger the base-class constructor's virtual call and illustrate static binding in constructors.
 *
 * @return 0 indicating the function completed.
 */
int VCALL_IN_CTOR_DTOR_BAD() {
    B b; // 缺陷点：构造函数中调用虚方法时，C++使用静态绑定而不是动态绑定，导致调用的是父类的虚方法而不是子类的重写方法。
    return 0;
}
 
 class C
{
public:
    /**
 * @brief Constructs a C instance.
 */
C() {}
    virtual ~C();
    /**
     * @brief Emits the class-specific identifier to standard output.
     *
     * Writes the string "C::virtMethod" to stdout to indicate C's implementation of the virtual method.
     */
    virtual void virtMethod() {
        cout << "C::virtMethod";
    }
};

class D: public C
{
public:
    D();
    virtual ~D();
    /**
     * @brief Print the D-specific virtual method message.
     *
     * Outputs "D::virtMethod" to standard output.
     */
    virtual void virtMethod() {
        cout << "D::virtMethod";
    }
};

/**
 * @brief Demonstrates safe construction of class D while avoiding virtual calls from constructors.
 *
 * Constructs a D instance using its default constructor to illustrate the corrected pattern
 * where constructors do not invoke virtual methods.
 *
 * @return int Always returns 0.
 */
int VCALL_IN_CTOR_DTOR_GOOD() {
    D d; // 修复点：不在构造函数中直接调用虚方法
    return 0;
}
 