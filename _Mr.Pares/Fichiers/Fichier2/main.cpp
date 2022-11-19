#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{

    fstream monfstream("/home/eleve/Fichier/toto",ios::in);
    char tabCaract[100];
    if(!monfstream)
    {
        cout << "Fichier non trouve !"<< endl;
        exit(0);
    }
    else
    {

        do
        {
            monfstream.getline(tabCaract, 100);
            cout << tabCaract <<endl;
        }while(monfstream.peek()!=EOF);
    }

    return 0;
}

