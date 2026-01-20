/**
    Filename: DEAD_CODE_S.c
    Vuln: DEAD_CODE_S
    SourceLine: -1
    SinkLine: 24
    Comment: 逻辑死代码
*/

#include <stdio.h>
#include <stdlib.h>
void openWindow();
void closeWindow();
void moveWindowToTheBackground();
/**
 * Execute a window control action based on `param`.
 *
 * @param param Selector for the action: `1` opens the window, `2` closes the window; other values do nothing.
 *
 * Note: an additional `else if (param == 1)` branch exists in the implementation and is unreachable, so any code placed there will never execute.
 */
void DEAD_CODE_S_BAD(int param) 
{
    if(param == 1)
    {
        openWindow();
    }
    else if (param == 2)
    {
        closeWindow();
    }
    else if(param == 1)
    {
        moveWindowToTheBackground();    //缺陷点：前面 if 里已经判断 ‘param == 1’，在else if 分支里继续判断，此分支代码永远不会执行
    }
}

/**
 * Perform a window control action selected by `param`.
 *
 * Calls `openWindow()` when `param == 1`, `closeWindow()` when `param == 2`, and
 * `moveWindowToTheBackground()` when `param == 3`. No action is taken for other values.
 *
 * @param param Selector for the action: 1 = open window, 2 = close window, 3 = move window to background.
 */
void DEAD_CODE_S_GOOD(int param) 
{
    if(param == 1)
    {
        openWindow();
    }
    else if (param == 2)
    {
        closeWindow();
    }
    else if(param == 3)
    {
        moveWindowToTheBackground();    //修复点：此分支代码有执行的可能
    }
}