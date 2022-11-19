#include "tableau.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;






/**Saisie tableau*/
   int saisietableau(int tab[],int taille)
{
        int i;
        for(i=0;i<taille;i++)

    {
        cout<<"Entrez la valeur d'une case";
        cin>>tab[i];
    }
    return 0;
}
/**Calcule max*/
    int max (int tab[],int taille, int max)
{
        int i;
        max=tab[0];
        for(i=1;i<taille;i++)
    {
        if(tab[i]>max)
        max=tab[i];
    }
    return 0;
}
/**Calcule du MIN*/
    int min (int tab[],int taille, int min)
{

         int i;
        min=tab[0];
        for(i=1;i<taille;i++)
    {
        if(tab[i]<min)
        min=tab[i];
    }
   return 0;
}
/******************************************Calcule de la moyenne******************************/
    int moy (int tab[],int taille, int moy)
{
         int i;
         int somme;
        for(i=0;i<taille;i++)
    {
        somme=somme+tab[i];
    }
    moy=(float)somme/taille;
    return 0;
}

