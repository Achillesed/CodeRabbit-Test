/**
    Filename: MISSING_BREAK.c
    Vuln: MISSING_BREAK
    SourceLine: -1
    SinkLine: 17
    Comment: Switch 中缺少 break
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