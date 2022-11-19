#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{

    fstream monfstream("/home/eleve/Fichier/toto",ios::in);
    if(!monfstream)
    {
        cout << "Fichier non trouve !"<< endl;
        exit(0);
    }
    else
    {
        char caract;
        do
        {
            monfstream.get(caract);
            cout << caract;
        }while(monfstream.peek()!=EOF);
    }

    return 0;
}

