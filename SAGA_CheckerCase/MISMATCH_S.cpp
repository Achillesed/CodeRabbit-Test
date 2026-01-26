/**
    Filename: MISMATCH_S.cpp
    Vuln: MISMATCH_S
    SourceLine: -1
    SinkLine: 20
    Comment: 不匹配的内存管理例程
*/

#include <iostream>

typedef struct BarObj 
{
    int a;
    int b;
};

/**
 * @brief Demonstrates incorrect memory deallocation by freeing memory allocated with `new`.
 *
 * Allocates a `BarObj` instance using `new` and then releases it with `free`, which is a mismatched
 * memory management routine and leads to undefined behavior.
 *
 * @note This function is intentionally vulnerable and provided for demonstration; do not use this
 * pattern in production code. Use `delete` to release memory allocated with `new`.
 */
void MISMATCH_S_BAD()
{
    BarObj *ptr = new BarObj();
    free(ptr); // 缺陷点：错误使用 free 释放 new 分配出的内存
}

/**
 * @brief Demonstrates correct deallocation of an object allocated with `new`.
 *
 * Allocates a `BarObj` with `new` and frees it using `delete` to show the
 * proper pairing of allocation and deallocation routines in C++.
 */
void MISMATCH_S_GOOD()
{
    BarObj *ptr = new BarObj();
    delete(ptr); // 修复点：使用 delete 释放 new 分配的内存
}