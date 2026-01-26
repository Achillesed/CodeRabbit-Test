/**
 * Demonstrates an unsafe cast from an int pointer to a long pointer that can cause undefined behavior.
 *
 * This function casts the address of an `int` to `long*` and dereferences it to store into `*pl`,
 * which may produce misaligned accesses, memory overread, or other undefined behavior.
 *
 * @param pl Pointer to a `long` that will receive the value read via the improper cast.
 */

void INCOMPATIBLE_CAST_S_BAD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = *(long*)pi;  // 缺陷点：指针指向的有效类型被解引用为较宽的对象，这可能导致内存崩溃
}

/**
 * Safely assigns a long value constructed from a local int to the provided pointer.
 *
 * Reads a local `int` value and promotes it to `long` before storing to `*pl`,
 * avoiding reinterpreting an `int*` as a `long*`.
 *
 * @param pl Pointer to a `long` where the promoted value will be stored.
 */
void INCOMPATIBLE_CAST_S_GOOD(long* pl)
{
    int i, *pi;
    i = 32;
    pi = &i;
    *pl = 0L | *(int*)pi;  // 修复点：将结果提升为 long 类型
}