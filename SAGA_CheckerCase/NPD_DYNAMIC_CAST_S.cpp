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
        Class_T_Object() {};
        virtual ~Class_T_Object() {};
        int a;
    bool classof(Class_T_Object *T)
    {
        return true;
    }
};
class Class_C_Object : public Class_T_Object
{
    bool classof(Class_T_Object *T)
    {
        return true;
    }
    bool classof(Class_C_Object *T)
    {
        return true;
    }
};

int NPD_DYNAMIC_CAST_S_BAD(Class_T_Object *p) 
{
    Class_C_Object* obj = dynamic_cast<Class_C_Object*>(p);
    return obj->a;   // 缺陷点：dynamic_cast没有进行空指针检查，存在空指针解引用风险
}

int NPD_DYNAMIC_CAST_S_GOOD(Class_T_Object *p) 
{
    Class_C_Object* obj = dynamic_cast<Class_C_Object*>(p);
    if(!obj) return -1;
    return obj->a;   // 修复点：dynamic_cast返回值进行了判空检查
}