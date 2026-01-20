/**
    Filename: NPD_DYNAMIC_CAST_S.cpp
    Vuln: NPD_DYNAMIC_CAST_S
    SourceLine: -1
    SinkLine: 39
    Comment: dynamic_cast的返回值未检查
*/

#include <iostream>

using namespace std;

class Class_T_Object
{
    public:
        /**
 * @brief Default constructor for Class_T_Object.
 *
 * Constructs a Class_T_Object instance.
 */
Class_T_Object() {};
        /**
 * @brief Ensures derived-class destructors are invoked when an object is deleted through a pointer to Class_T_Object.
 */
virtual ~Class_T_Object() {};
        int a;
    /**
     * @brief Determines whether the provided object is an instance of Class_T_Object.
     *
     * @param T Pointer to the object to test.
     * @return true if the object is an instance of Class_T_Object, false otherwise.
     */
    bool classof(Class_T_Object *T)
    {
        return true;
    }
};
class Class_C_Object : public Class_T_Object
{
    /**
     * @brief Determines whether the provided object is an instance of Class_T_Object.
     *
     * @param T Pointer to the object to test.
     * @return true if the object is an instance of Class_T_Object, false otherwise.
     */
    bool classof(Class_T_Object *T)
    {
        return true;
    }
    /**
     * @brief Determines whether the given pointer refers to a Class_C_Object.
     *
     * @param T Pointer to the object being tested.
     * @return true if the pointer refers to a Class_C_Object, false otherwise.
     */
    bool classof(Class_C_Object *T)
    {
        return true;
    }
};

/**
 * @brief Retrieve the `a` member from a `Class_C_Object` by dynamic_cast-ing the given pointer.
 *
 * @param p Pointer to a `Class_T_Object` expected to refer to a `Class_C_Object`.
 * @return int The `a` member of the casted `Class_C_Object`. If `p` does not refer to a `Class_C_Object` (so the cast yields `nullptr`), the function dereferences a null pointer, resulting in undefined behavior.
 */
int NPD_DYNAMIC_CAST_S_BAD(Class_T_Object *p) 
{
    Class_C_Object* obj = dynamic_cast<Class_C_Object*>(p);
    return obj->a;   // 缺陷点：dynamic_cast没有进行空指针检查，存在空指针解引用风险
}

/**
 * @brief Safely obtain the derived-class member `a` from a base-class pointer.
 *
 * Attempts a `dynamic_cast` of `p` to `Class_C_Object*` and returns the `a`
 * member when the cast succeeds.
 *
 * @param p Pointer to a `Class_T_Object` that may point to a `Class_C_Object`.
 * @return int The `a` value from the casted `Class_C_Object`, or `-1` if the cast fails.
 */
int NPD_DYNAMIC_CAST_S_GOOD(Class_T_Object *p) 
{
    Class_C_Object* obj = dynamic_cast<Class_C_Object*>(p);
    if(!obj) return -1;
    return obj->a;   // 修复点：dynamic_cast返回值进行了判空检查
}