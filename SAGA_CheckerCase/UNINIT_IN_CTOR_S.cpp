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
      /**
       * @brief Constructs an UNINIT_IN_CTOR_S_B with a given integer and leaves the pointer member uninitialized.
       *
       * @param a Initial value for member `m_a`.
       *
       * Note: Member `m_p` is not initialized by this constructor; accessing or dereferencing it yields undefined behavior.
       */
      UNINIT_IN_CTOR_S_B(int a) : m_a(a) 
      {
        // Defect:  m_p not initialized in constructor
      }
      /**
       * @brief Returns the stored pointer to the integer member.
       *
       * The returned pointer is the raw `int*` held by the instance; it may be
       * `nullptr` or contain an indeterminate value if the constructor did not
       * initialize the member.
       *
       * @return int* The stored pointer to the integer. 
       */
      int * getm_p()
      {
        return m_p;
      }
private:
      int m_a;
      int *m_p;
};

/**
 * @brief Demonstrates undefined behavior caused by dereferencing an uninitialized member pointer.
 *
 * Constructs an UNINIT_IN_CTOR_S_B and then dereferences the pointer returned by getm_p(),
 * which is not initialized in the class constructor; the dereference results in undefined behavior.
 */
void UNINIT_IN_CTOR_S_BAD()
{
    int a = 1;
    UNINIT_IN_CTOR_S_B S(a);
    int b = *S.getm_p();    //缺陷点：成员变量未在构造函数中初始化
}

class UNINIT_IN_CTOR_S_G
{    
public:  
      /**
       * @brief Constructs the object, initializes `m_a`, and allocates storage for the internal pointer.
       *
       * Allocates a new `int` for `m_p`; the object assumes ownership and will free it in its destructor.
       *
       * @param a Initial value for `m_a`.
       */
      UNINIT_IN_CTOR_S_G(int a) : m_a(a) 
      {
         m_p = new int;
      }
      /**
       * @brief Returns the stored pointer to the integer member.
       *
       * The returned pointer is the raw `int*` held by the instance; it may be
       * `nullptr` or contain an indeterminate value if the constructor did not
       * initialize the member.
       *
       * @return int* The stored pointer to the integer. 
       */
      int * getm_p()
      {
        return m_p;
      }
      /**
       * @brief Releases the memory owned by the object's pointer member.
       *
       * Deletes the memory pointed to by `m_p` to free resources and prevent a memory leak.
       */
      ~UNINIT_IN_CTOR_S_G()
      {
        delete m_p;
      }
private:
      int m_a;
      int *m_p;
};

/**
 * @brief Demonstrates safe usage of UNINIT_IN_CTOR_S_G where member pointer is initialized.
 *
 * Creates a UNINIT_IN_CTOR_S_G instance with a local value and reads the integer pointed to by the class's initialized member pointer.
 */
void UNINIT_IN_CTOR_S_GOOD()
{
    int a = 1;
    UNINIT_IN_CTOR_S_G S(a);
    int b = *S.getm_p();        //修复点：构造函数中有初始化此成员变量
}