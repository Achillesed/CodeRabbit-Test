#include <iostream>
#include "Features_Language_Constructor.h"
using namespace std;
ABC::ABC(int i)
{
    data = new int;
    *data = i;
}
ABC::~ABC( )
{
    delete data;
}
void ABC::print( )
{
    cout << *data << endl;
}