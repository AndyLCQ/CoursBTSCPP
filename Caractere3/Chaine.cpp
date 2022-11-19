#include <ctype.h>
#include <iostream>
//---------------------------------------------------------------------------
#include "Chaine.h"
//---------------------------------------------------------------------------
using namespace std;
/***********************************************************************************/
/* Initialise nbMaxCar
Initialise nbCar
Réserve la mémoire pour la chaîne (en fonction du paramètre, ne pas oublier l’indicateur de fin de
chaîne)
Met à Zéro le tableau en utilisant la méthode init()*/
Chaine::Chaine(int valNbCar)
{
    nbMaxCar=valNbCar;
    nbCar=0;
    tab= new char [nbMaxCar+1];
    init();
}

/***********************************************************************************/
/* Met à Zéro les cases de la chaîne */
void Chaine::init()
{
        //Initialise le tableau a 0.
    for(int i=0; i<nbMaxCar+1; i++)
    {
        tab[i]=0;
    }
}
/***********************************************************************************/
/* libère la mémoire */
Chaine::~Chaine()
{
    delete [] tab;
}

/***********************************************************************************/
/* Vide la chaîne (appel à la méthode init()) */
void Chaine::vide()
{
    init();
    nbCar=0;
}
/***********************************************************************************/
/* Ajoute, si possible, un caractère en fin de chaîne
si l’opération a réussi on renvoie true, sinon on renvoie false */
bool Chaine::ajouteCaractere(char cara)
{
    bool reussi=false;
    if(nbCar<nbMaxCar)
    {
        tab[nbCar]=cara;
        nbCar++;
        reussi=true;
    }
    return reussi;
}
/***********************************************************************************/
/* Retire, si possible le dernier caractère de la chaîne
si l’opération a réussi on renvoie le caractère retiré, sinon on renvoie 0 */
char Chaine::retireCaractere()
{
    char caractere=0;

    if(nbCar!=0)
    {
        caractere=tab[nbCar-1];
        tab[nbCar-1]=0;
        nbCar--;

    }
    return caractere;
}
/***********************************************************************************/
/* Affichage de la chaîne ou du message « chaîne vide » */
void Chaine::affiche()
{
    if(nbCar==0)
    {
        cout << "La chaine est  vide !" <<endl;
    }
    else
    {
        for(int i=0; i<nbCar;i++)
        {
            cout << tab[i];
        }
    }
}
/***********************************************************************************/
/* Transformation de la chaîne en minuscule (sans utiliser de fonction) */
void Chaine::minuscule()
{
    for(int i=0; i<nbCar;i++)
    {
        tab[i]=tolower(tab[i]);
    }
}
/***********************************************************************************/
/* Transformation de la chaîne en majuscule (sans utiliser de fonction) */
void Chaine::majuscule()
{
    for(int i=0; i<nbCar;i++)
    {
        tab[i]=toupper(tab[i]);
    }

}
/***********************************************************************************/
/* Retourne la taille actuelle de la chaîne */
int Chaine::taille()
{
    int compt;
    compt=nbCar;

    return compt;
}
