#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    fstream monfstream("/home/eleve/Fichier/toto",ios::in);
    int tabEnt[30]; int i=0;
    if(!monfstream)
    {
        cout<< "Le fichier le n'existe pas !"<<endl;
        exit(0);
    }
    else
    {
        do
        {
            monfstream >>  tabEnt[i];
            i++;


        }while(monfstream.peek()!=EOF);
    }
    for(int j=0; j<i; j++)
    {
        cout << tabEnt[j] <<endl;

    }

    return 0;
}

