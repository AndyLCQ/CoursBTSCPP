#include "tableau.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;



/**Saisie tableau**/
void saisietableau(int tab[],int taille)
{
        int i;
        for(i=0;i<taille;i++)

    {
        cout<<"Entrez la valeur d'une case : \n";
        cin>>tab[i];
    }
}


/**Calcule max**/
    int maximum (int tab[],int taille)
{
        int i;
        int max=tab[0];
        for(i=1;i<taille;i++)
    {
        if(tab[i]>max)
        max=tab[i];
    }
    return max;
}

/**Calcule du MIN**/
    int minimum  (int tab[],int taille)
{

         int i;
        int min=tab[0];
        for(i=1;i<taille;i++)
    {
        if(tab[i]<min)
        min=tab[i];
    }
   return min;
}

/**Calcule de la moyenne**/
float moyenne (int tab[],int taille)
{
    int i;
    int somme=0;
    float moy;

    for(i=0;i<taille;i++)
    {
        somme=somme+tab[i];
    }
    moy=(float)somme/taille;
    return moy;
}


/**Affiche**/
void Affiche(int min,int max, float moy)
{
    cout << "maxi : " << max << "\n ";
    cout << "mini : " << min <<"\n";
    cout << "moyenne : " << moy <<"\n";
}
