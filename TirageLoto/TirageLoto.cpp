#include "TirageLoto.h"
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//---------------------------------------------------------------------------
/***********************************************************************************/
/* R�serve de la m�moire pour les trois tableaux
Copie nombreNumero dans nbNumero
Initialise le g�n�rateur de nombre al�atoires */
TirageLoto::TirageLoto(int nombreNumero): TOTALNUMERO (49)
{
    nbNumero=nombreNumero;
    tabNumero=new int [TOTALNUMERO+1];
    resultatNonTrier=new int [nbNumero];
    resultatTrier=new int [nbNumero];
    srand (time(NULL));

}

/***********************************************************************************/
/* Lib�re la m�moire */
TirageLoto::~TirageLoto()
{
    delete [] tabNumero;
    delete [] resultatNonTrier;
    delete [] resultatTrier;
}

/***********************************************************************************/
/* Initialise le tableau tabNumero � 0 */
void TirageLoto::initTabNumero()
{
    for(int i=0; i<TOTALNUMERO+1; i++)
    {
        tabNumero[i]=0;
    }
}
/***********************************************************************************/
/* R�alise le tirage
-  r�sultats dans resultatNonTrier
-  utilise random pour le tirage tabNumero
-  fait appel � trierTirage
-  fait appel � initTabNumero */
void TirageLoto::tirageNbr()
{
    int j=0;
    do
    {

        resultatNonTrier[j]=rand () %TOTALNUMERO +1;
       if(tabNumero[resultatNonTrier[j]]!=1)
       {
            tabNumero[resultatNonTrier[j]]=1;
            j++;
       }


    }while(j < nbNumero);
    trierTirage();
    initTabNumero();
}
/***********************************************************************************/
/* Remplit resultatTrier */
void TirageLoto::trierTirage()
{
    int i=0;
    for(int k=0; k<=TOTALNUMERO; k++)
    {
        if(tabNumero[k]== 1)
        {
            resultatTrier[i]=k;
            i++;
        }
    }
}
/***********************************************************************************/
/* Retourne le contenu de la case du tableau (resultat Trier : si select=TRIE ou resultat NonTrier : si
select=NON_TRIE) dont l'indice est sp�cifi� par i */
int TirageLoto::litNumeroTirer(selection select,int i)
{
    int indice=i;
    int resu;

    if(select==TRIE)
    {
        resu = resultatTrier[indice];
    }
    if(select==NON_TRIE)
    {
        resu = resultatNonTrier[indice];
    }
    return resu;
}
/***********************************************************************************/
/*Retourne le nombre de tirage a effectuer */
int TirageLoto::getNbNumero()
{
        return nbNumero;
}
