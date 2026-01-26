/**
    Filename: UNUSED_VAR_S.c
    Vuln: UNUSED_VAR_S
    SourceLine: -1
    SinkLine: 11
    Comment: 未使用的变量
*/
void useData(char);
/**
 * Demonstrates a function that declares a local variable without using it.
 *
 * The function declares a local `char` variable `data` which is never referenced,
 * illustrating an unused-variable (dead/store-only) pattern.
 */
void UNUSED_VAR_S_BAD()
{
    char data;   // 缺陷点：变量data被声明，但之后未被使用
}

/**
 * Initialize a local character and use it to demonstrate correct variable usage.
 *
 * The function sets a local `char` variable and uses it to avoid an unused-variable scenario.
 */
void UNUSED_VAR_S_GOOD()
{
    char data = 'C';    //修复点：在后有使用
    useData(data); 

}