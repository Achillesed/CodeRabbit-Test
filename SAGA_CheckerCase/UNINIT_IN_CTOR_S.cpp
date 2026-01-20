/**
    Filename: UNINIT_IN_CTOR_S.cpp
    Vuln: UNINIT_IN_CTOR_S
    SourceLine: -1
    SinkLine: 31
    Comment: 使用未在构造函数中初始化的变量
*/

#include <iostream>

class UNINIT_IN_CTOR_S_B
{    
public:  
      UNINIT_IN_CTOR_S_B(int a) : m_a(a) 
      {
        // Defect:  m_p not initialized in constructor
      }
      int * getm_p()
      {
        return m_p;
      }
private:
      int m_a;
      int *m_p;
};

void UNINIT_IN_CTOR_S_BAD()
{
    int a = 1;
    UNINIT_IN_CTOR_S_B S(a);
    int b = *S.getm_p();    //缺陷点：成员变量未在构造函数中初始化
}

class UNINIT_IN_CTOR_S_G
{    
public:  
      UNINIT_IN_CTOR_S_G(int a) : m_a(a) 
      {
         m_p = new int;
      }
      int * getm_p()
      {
        return m_p;
      }
      ~UNINIT_IN_CTOR_S_G()
      {
        delete m_p;
      }
private:
      int m_a;
      int *m_p;
};

void UNINIT_IN_CTOR_S_GOOD()
{
    int a = 1;
    UNINIT_IN_CTOR_S_G S(a);
    int b = *S.getm_p();        //修复点：构造函数中有初始化此成员变量
}
