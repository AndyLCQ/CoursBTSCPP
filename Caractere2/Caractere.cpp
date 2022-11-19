#include "Caractere.h"

#include <ctype.h>
#include <iostream>
//---------------------------------------------------------------------------
#include "caractere.h"
using namespace std;
//---------------------------------------------------------------------------
/* Initialise le caract�re en majuscule */
Caractere::Caractere(char valCar)
{
    car=toupper(valCar);
}
/***********************************************************************************/
/* Retourne le caract�re en minuscule */
char Caractere::minuscule()
{
    char a;
    a=tolower(car);
    return a;
}
/***********************************************************************************/
/* Retourne le caract�re en majuscule */
char Caractere::majuscule()
{
    char a;
    a=toupper(car);
    return a;
}

/***********************************************************************************/
/* Affiche le caract�re en majuscule ou en minuscule suivant le param�tre.
L�affichage se pr�sentera sous la forme : Le caract�re est A */
void Caractere::afficheCar(TypeCara minMaj)
{
        if(minMaj==MIN)
        {
            cout<<"Le caractere est : "<<minuscule()<<endl;
        }
        else
        {
            cout<<"Le caractere est : "<<majuscule()<<endl;
        }
}
/***********************************************************************************/
/* Affiche le code ASCII suivant le param�tre.
L�affichage se pr�sentera sous la forme : Le code ascii de A est 65 */
void Caractere::afficheCodeAscii(TypeCara minMaj)
{


        if(minMaj==MIN)
        {

            cout<<"Le code ASCII de  "<<minuscule()<<" est :" << (int)minuscule() <<endl;
        }
        else
        {

            cout<<"Le code ASCII de  "<<majuscule()<<" est :" << (int)majuscule() <<endl;
        }


}
/***********************************************************************************/
/* Renvoie �ventuellement le caract�re inf�rieur, sinon elle renvoie 0 */
char Caractere::carInferieur()
{
    char lettre=0;
    char resu = majuscule();
    if(resu !='A')
    {
        lettre=resu-1;
    }
    return lettre;
}
/***********************************************************************************/
/* Renvoie �ventuellement le caract�re sup�rieur, sinon elle renvoie 0 */
char Caractere::carSuperieur()
{

    char lettre=0;
    char resu = majuscule();
    if(resu!='Z')
    {
        lettre=resu+1;
    }

    return lettre;
}
