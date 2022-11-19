#include "Random.h"
/*Ce constructeur permet d’initialiser les attributs (taille par défaut du tableau 1 et
unique à faux).*/
Random::Random(int paraMini,int paraMaxi,unsigned int paraNbRandom,bool paraUnique)
{
   mini=paraMini;
   maxi=paraMaxi;
   nbRandom=paraNbRandom;
   unique=paraUnique;
}
Random::~Random()
{
    //dtor
}
/*Rempli le tableau avec des valeurs aléatoires (unique ou pas selon le cas)*/
void Random::initTab()
{

    for (unsigned int i=0;i<nbRandom+1;i++)
    {
        tabRandom[i]=rand()%mini; // + maxi;

    }

}
/*Indique la taille du tableau.*/
unsigned int Random::getNbRandom()
{
    return nbRandom;
}
/*Modifie la taille du tableau et le rempli. */
void Random::setNbRandom(unsigned int nbVal)
{
    nbRandom=nbVal;
}
/*Indique la valeur aléatoire maxi possible. */
unsigned int Random:: getMaxi()
{
    return maxi;
}
/* Indique la valeur aléatoire mini possible.  */
unsigned int Random:: getMini()
{
    return mini;
}
/*Modifie la valeur aléatoire maxi possible. */
void Random:: setMaxi(int val)
{
    maxi=val;
}
/*Modifie la valeur aléatoire mini possible. */
void Random:: setMini(int val)
{
    mini=val;
}
/*Indique la valeur aléatoire de la case spécifiée.
Si l’indice n’est pas valide, on retournera une valeur égale à mini-1.*/
int Random::getDonnee(unsigned int indice)
{
    return tabRandom[indice];
}
/*retourne une valeur aléatoire comprise dans la fourchette.*/
int Random::calculValeur()
{
    int calcule=rand()%mini + maxi;
    return calcule;
}
/*indique si la valeur spécifiée est déjà dans le tableau. */
bool Random::rechercheValeur(int donnee)
{
    for(unsigned int i=0; i<nbRandom+1;i++)
    {
        if (tabRandom[i]==donnee)
            unique=true;
    }
    return unique;

}
