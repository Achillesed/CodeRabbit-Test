/**
    Filename: DELETE_VOID.cpp
    Vuln: DELETE_VOID
    SourceLine: -1
    SinkLine: 14
    Comment: 删除了 void 指针
*/

#include <iostream>

/**
 * @brief Deletes the object pointed to by p.
 *
 * @param p Pointer to the object to be deleted. Must point to memory obtained from `new` and refer to a complete object type; deleting a `void*` that does not meet those conditions results in undefined behavior.
 */
void DELETE_VOID_BAD(void *p)
{
    /* do something */
    delete p;
}

/**
 * @brief Deallocates a character pointer that the caller previously allocated.
 *
 * @param p Pointer to a single `char` object allocated with `new`. Ownership is transferred to this function and the memory is freed with `delete`.
 */
void DELETE_VOID_GOOD(char *p)
{
    /* do something */
    delete p;
}