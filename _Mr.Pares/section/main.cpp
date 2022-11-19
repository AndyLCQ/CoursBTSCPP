#include <iostream>
#include <fstream>
#include "section.h"
#include "eleve.h"
using namespace std;

int main()
{


    fstream flux;
    Section section;
    flux.open("../section/classe", ios::in);
    section.litSection();
    section.AfficheSection();

    return 0;
}

