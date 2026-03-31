/**
    Filename: UNCAUGHT_EXCEPT.cpp
    Vuln: UNCAUGHT_EXCEPT
    SourceLine: -1
    SinkLine: 14
    Comment: 未捕获的异常
*/

#include <iostream>
using namespace std;
// Example
void divide_BAD(int a, int b){
  if(b == 0){
    throw "Division by zero";
  }
  cout << "Result " << a/b << endl;
}

void UNCAUGHT_EXCEPT_BAD()
{
  int num1 = 10;
  int num2 = 0;
  divide_BAD(num1, num2);
}

void divide_GOOD(int a, int b){
  try
  {
    if(b == 0)
    {
        throw "Division by zero";
    }
  }
  catch (const char* msg)
  {
    cerr << "Excetion caught" << msg << endl;
  }
  cout << "Result " << a/b << endl;
}

void UNCAUGHT_EXCEPT_GOOD()
{
  int num1 = 10;
  int num2 = 0;
  divide_GOOD(num1, num2);
}