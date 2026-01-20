/**
 * Performs placeholder work then calls itself recursively.
 *
 * This function invokes itself unconditionally, resulting in unbounded recursion (stack overflow).
 */
void func() 
{
    /* do something */
    func(); // 缺陷点
}

/**
 * Demonstrates unsafe usage by invoking a function that performs a direct self-call (recursive without termination).
 * @returns 0 on success.
 */
int SELFCALL_S_BAD() 
{
    func();
    return 0;
}

/**
 * Perform placeholder work without calling itself.
 *
 * This non-recursive helper performs its intended task (currently a placeholder)
 * and then returns to the caller.
 */
void func2() 
{
    /* do something */
}

/**
 * Demonstrates the corrected entry point that invokes a non-recursive helper to avoid self-calling.
 *
 * @returns 0 on success.
 */
int SELFCALL_S_GOOD() 
{
    func2();    //修复点
    return 0;
}