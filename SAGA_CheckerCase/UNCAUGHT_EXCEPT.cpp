/**
    Filename: UNCAUGHT_EXCEPT.cpp
    Vuln: UNCAUGHT_EXCEPT
    SourceLine: -1
    SinkLine: 14
    Comment: 未捕获的异常
*/

#include <iostream>
using namespace std;
/**
 * @brief Performs integer division and prints the quotient to standard output.
 *
 * @param a Numerator.
 * @param b Divisor.
 * @throws const char* Thrown with message "Division by zero" if `b` is zero.
 */
void divide_BAD(int a, int b){
  if(b == 0){
    throw "Division by zero";
  }
  cout << "Result " << a/b << endl;
}

/**
 * @brief Demonstrates an uncaught division-by-zero scenario.
 *
 * This function sets up a division where the divisor is zero and performs the operation,
 * causing a division-by-zero exception that is not caught within this call and therefore
 * propagates to the caller.
 */
void UNCAUGHT_EXCEPT_BAD()
{
  int num1 = 10;
  int num2 = 0;
  divide_BAD(num1, num2);
}

/**
 * @brief Checks for a zero divisor, reports the error if present, then prints the division result.
 *
 * If `b` equals zero, an error message is printed to `std::cerr`. The function then prints "Result " followed
 * by the value of `a / b` to `std::cout`; this may perform a division by zero at runtime.
 *
 * @param a Numerator.
 * @param b Denominator.
 */
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

/**
 * @brief Demonstrates a division-by-zero scenario with local exception handling.
 *
 * Sets two operands (10 and 0) and performs the division; any exception raised
 * during the operation is expected to be handled by the division implementation.
 */
void UNCAUGHT_EXCEPT_GOOD()
{
  int num1 = 10;
  int num2 = 0;
  divide_GOOD(num1, num2);
}