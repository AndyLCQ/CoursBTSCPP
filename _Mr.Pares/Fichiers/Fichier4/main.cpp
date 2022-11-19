#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{

    fstream monfstream("/home/eleve/Fichier/toto",ios::in);
    char caract;
    if(!monfstream)
    {
        cout<< "Le fichier le n'existe pas !"<<endl;
        exit(0);
    }
    else
    {


        monfstream.seekg(-10, ios::end);
        cout << "10 derniers caractere du fichier : ";
        do
        {
            monfstream.get(caract);
            cout << caract;
        }while(monfstream.peek()!=EOF);
        cout << endl;
    }
    return 0;
}

