#include <ctype.h>
#include <iostream>
//---------------------------------------------------------------------------
#include "Chaine.h"
//---------------------------------------------------------------------------
using namespace std;
/***********************************************************************************/
/* Initialise nbMaxCar
Initialise nbCar
R�serve la m�moire pour la cha�ne (en fonction du param�tre, ne pas oublier l�indicateur de fin de
cha�ne)
Met � Z�ro le tableau en utilisant la m�thode init()*/
Chaine::Chaine(int valNbCar)
{
    nbMaxCar=valNbCar;
    nbCar=0;
    tab= new char [nbMaxCar+1];
    init();
}

/***********************************************************************************/
/* Met � Z�ro les cases de la cha�ne */
void Chaine::init()
{
        //Initialise le tableau a 0.
    for(int i=0; i<nbMaxCar+1; i++)
    {
        tab[i]=0;
    }
}
/***********************************************************************************/
/* lib�re la m�moire */
Chaine::~Chaine()
{
    delete [] tab;
}

/***********************************************************************************/
/* Vide la cha�ne (appel � la m�thode init()) */
void Chaine::vide()
{
    init();
    nbCar=0;
}
/***********************************************************************************/
/* Ajoute, si possible, un caract�re en fin de cha�ne
si l�op�ration a r�ussi on renvoie true, sinon on renvoie false */
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
/* Retire, si possible le dernier caract�re de la cha�ne
si l�op�ration a r�ussi on renvoie le caract�re retir�, sinon on renvoie 0 */
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
/* Affichage de la cha�ne ou du message � cha�ne vide � */
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
/* Transformation de la cha�ne en minuscule (sans utiliser de fonction) */
void Chaine::minuscule()
{
    for(int i=0; i<nbCar;i++)
    {
        tab[i]=tolower(tab[i]);
    }
}
/***********************************************************************************/
/* Transformation de la cha�ne en majuscule (sans utiliser de fonction) */
void Chaine::majuscule()
{
    for(int i=0; i<nbCar;i++)
    {
        tab[i]=toupper(tab[i]);
    }

}
/***********************************************************************************/
/* Retourne la taille actuelle de la cha�ne */
int Chaine::taille()
{
    int compt;
    compt=nbCar;

    return compt;
}
