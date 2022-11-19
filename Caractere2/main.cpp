//---------------------------------------------------------------------------
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "caractere.h"
//---------------------------------------------------------------------------

using namespace std;

int main()
{
    Caractere c1('a');
    system("cls");
    c1.afficheCar(MIN);
    c1.afficheCar(MAJ);
    c1.afficheCodeAscii(MIN);
    c1.afficheCodeAscii(MAJ);
    cout<<endl<<"Le caractere est : "<<c1.minuscule();
    cout<<endl<<"Le caractere est : "<<c1.majuscule();


// Affichage du caractere supérieur
    char test;
    test=c1.carSuperieur();

    if(test==0) //Test erreur lettre  z
    {
        cout <<endl<<" Erreur ! Pas de caractere superieur";
    }
    else
    {
        cout<<endl<<"Le caractere superieur est : "<<c1.carSuperieur();
    }

// Affichage du caractere inférieur
    test=c1.carInferieur();
    if(test==0)  //Test erreur lettre  a
    {
        cout <<endl<<" Erreur ! Pas de caractere inferieur !";
    }
    else
    {
        cout<<endl<<"Le caractere inferieur est : "<<c1.carInferieur();
    }


    return 0;
}
