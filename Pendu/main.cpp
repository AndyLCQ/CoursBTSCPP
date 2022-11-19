#include <iostream>
#include <sqlite.h>
#include "MotAleatoire.h"
using namespace std;


int main()
{

    Sqlite sqlite("dictionnaire.s3db");

    MotAleatoire motAleatoire(sqlite);
    int nombreEnregistrement;
    map <string,string> enregistrement;

    nombreEnregistrement=motAleatoire.nombreMots();
    cout << "Nombre d'enregistrement : "<<nombreEnregistrement << endl;
/*
sqlite.requete("SELECT idDictionnaire,mot FROM dictionnaire;");
sqlite.exec();

nombreEnregistrement= sqlite.getNombreEnregistrements();
for(int i=0;i<nombreEnregistrement;i++)
{
enregistrement=sqlite.getResultMap(i);
cout<< "id : "<< enregistrement["idDictionnaire"]<<", mot : " << enregistrement["mot"] <<endl;
}*/
    return 0;

}
