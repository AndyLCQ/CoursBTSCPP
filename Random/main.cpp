#include <iostream>
#include "Random.h"

using namespace std;

int main()
{
    Random * objRandom=new  Random(1, 10, 2, false);
    objRandom->initTab();


    return 0;
}
