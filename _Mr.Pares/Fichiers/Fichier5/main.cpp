#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int tableau[10];
    fstream monfstream("/home/eleve/Fichier/totoentier",ios::out);
   for(int i=0; i<10;i++)
    {
        cout << "Entrer un entier";
        cin >> tableau[i];
    }
    monfstream.write((char *)tableau, sizeof(tableau));
    monfstream.close();

    fstream monfstream2("/home/eleve/Fichier/totoentier",ios::in);
    monfstream2.read((char*)tableau, sizeof(tableau));
    for(int i=0; i<10;i++)
    {
        cout << tableau[i]<< endl;
    }
    return 0;
}

