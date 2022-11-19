#include <iostream>
#include "BitsAm.h"
using namespace std;

int main()
{
    Bits bits(2);



    cout << bits << endl;
    bits++;
    cout << bits << endl;
    bits-=7;
    cout << bits << endl;
    bits+=7;
     cout << bits << endl;
     bits[5];
    cout << bits<< endl;
    return 0;
}
