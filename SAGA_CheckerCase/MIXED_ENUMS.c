/**
    Filename: MIXED_ENUMS.c
    Vuln: MIXED_ENUMS
    SourceLine: -1
    SinkLine: 20
    Comment: 混合了枚举类型
*/

typedef enum {E1, E2}e;
typedef enum {F0, F1, F2, F3}f;

/**
 * Demonstrates a switch on an `e` value that incorrectly includes a case from a different enum.
 *
 * This function switches on the input `ee` and increments a local counter for the handled branches;
 * it intentionally contains a mistaken `case F2` (which is not a member of `e`) to illustrate the mixed-enum defect.
 * 
 * @param ee Value of enum `e` to evaluate in the switch.
 */
void MIXED_ENUMS_BAD(e ee) 
{
    int num = 0;
    switch (ee) 
    {
        case E1:
            num++;
            break;
        case F2: //缺陷点：F2不为 e 的枚举类型
            num++;
            break;
        default:
            num++;
            break;
    }
}

/**
 * Increment a local counter based on the provided enum `e` value.
 *
 * The function increments an internal `int` counter for `E1`, `E2`, or any other value handled by the `default` case.
 *
 * @param ee Value of enum `e` to evaluate.
 */
void MIXED_ENUMS_GOOD(e ee) 
{
    int num = 0;
    switch (ee) 
    {
        case E1:
            num++;
            break;
        case E2: //修复点：E2 为 e 的枚举类型
            num++;
            break;
        default:
            num++;
            break;
    }
}