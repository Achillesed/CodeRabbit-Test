/**
    Filename: DELETE_ARRAY.cpp
    Vuln: DELETE_ARRAY
    SourceLine: -1
    SinkLine: 13
    Comment: 对象的非数组删除
*/

#include <iostream>

/**
 * @brief Demonstrates incorrect deletion of memory allocated as an array using scalar `delete`.
 *
 * Allocates a character array with `new char[10]` and then frees it with `delete`, which produces undefined behavior.
 *
 * @warning Deleting an array allocated with `new[]` using `delete` is undefined behavior.
 */
void DELETE_ARRAY_BAD() 
{
    char *buf = new char [10];
    /* do something */
    delete buf; // 缺陷点：数组 delete 应该用 delete[]
}

/**
 * @brief Demonstrates correct deletion of a heap-allocated char array.
 *
 * Allocates a 10-character array with `new[]` and deallocates it using `delete[]`
 * to illustrate the proper pairing of array allocation and deletion.
 */
void DELETE_ARRAY_GOOD() 
{
    char *buf = new char [10];
    /* do something */
    delete[] buf; // 修复点
}