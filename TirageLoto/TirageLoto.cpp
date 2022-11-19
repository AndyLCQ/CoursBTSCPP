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
/* Réserve de la mémoire pour les trois tableaux
Copie nombreNumero dans nbNumero
Initialise le générateur de nombre aléatoires */
TirageLoto::TirageLoto(int nombreNumero): TOTALNUMERO (49)
{
    nbNumero=nombreNumero;
    tabNumero=new int [TOTALNUMERO+1];
    resultatNonTrier=new int [nbNumero];
    resultatTrier=new int [nbNumero];
    srand (time(NULL));

}

/***********************************************************************************/
/* Libère la mémoire */
TirageLoto::~TirageLoto()
{
    delete [] tabNumero;
    delete [] resultatNonTrier;
    delete [] resultatTrier;
}

/***********************************************************************************/
/* Initialise le tableau tabNumero à 0 */
void TirageLoto::initTabNumero()
{
    for(int i=0; i<TOTALNUMERO+1; i++)
    {
        tabNumero[i]=0;
    }
}
/***********************************************************************************/
/* Réalise le tirage
-  résultats dans resultatNonTrier
-  utilise random pour le tirage tabNumero
-  fait appel à trierTirage
-  fait appel à initTabNumero */
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
select=NON_TRIE) dont l'indice est spécifié par i */
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
