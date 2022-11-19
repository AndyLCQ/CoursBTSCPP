#include <iostream>
#include "Bits.h"

using namespace std;

int main()
{
    Bits bits(2);

    cout << bits << endl;
    bits++;
    cout << bits << endl;
    ~bits;
    cout << bits << endl;
    return 0;
}
