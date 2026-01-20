/**
 * Demonstrates a switch statement where `case 2` lacks a `break`, causing fall-through into `case 3`.
 *
 * The function increments a local counter for each executed case to illustrate the control-flow difference
 * when a `break` is omitted.
 *
 * @param what Selector value that determines which case(s) execute (commonly 1, 2, or 3).
 */

void MISSING_BREAK_BAD(int what)
{
  int num = 0;
    switch (what) 
    {
      case 1:
        num++;
        break;
      case 2:  //缺陷点：此 case 中缺少 break
        num++;
      case 3:
        num++;
        break;
    }
}

/**
 * Increment a local counter based on the selector value; each case is terminated with a break to prevent fall-through.
 *
 * @param what Selector determining which case increments the counter (1, 2, or 3). If `what` is not 1, 2, or 3, the function has no effect.
 */
void MISSING_BREAK_GOOD(int what)
{
  int num = 0;
    switch (what) 
    {
      case 1:
        num++;
        break;
      case 2:  // 修复点
        num++;
        break;
      case 3:
        num++;
        break;
    }
}