#include "Caractere.h"

#include <ctype.h>
#include <iostream>
//---------------------------------------------------------------------------
#include "caractere.h"
using namespace std;
//---------------------------------------------------------------------------
/* Initialise le caractère en majuscule */
Caractere::Caractere(char valCar)
{
    car=toupper(valCar);
}
/***********************************************************************************/
/* Retourne le caractère en minuscule */
char Caractere::minuscule()
{
    char a;
    a=tolower(car);
    return a;
}
/***********************************************************************************/
/* Retourne le caractère en majuscule */
char Caractere::majuscule()
{
    char a;
    a=toupper(car);
    return a;
}

/***********************************************************************************/
/* Affiche le caractère en majuscule ou en minuscule suivant le paramètre.
L’affichage se présentera sous la forme : Le caractère est A */
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
/* Affiche le code ASCII suivant le paramètre.
L’affichage se présentera sous la forme : Le code ascii de A est 65 */
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
/* Renvoie éventuellement le caractère inférieur, sinon elle renvoie 0 */
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
/* Renvoie éventuellement le caractère supérieur, sinon elle renvoie 0 */
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
