//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <string.h>

#include "Application.h"

void Application::lancer()
{
    const int MAXI=10;
    int tab[MAXI];
    int i;
    int max,min;
    float moy=0;



    cout<<"Entrer 10 entiers"<<endl;

    /* saisi du tableau */
    for(i=0;i<MAXI;i++)
    {
        cout<<"Entrer l'entier "<<i+1<<" : ";
        cin>>tab[i];
    }

    /* recherche du plus grand nombre */
    max=tab[0];
    for(i=1;i<MAXI;i++)
    {
        if(max<tab[i])
            max=tab[i];
    }

    /* recherche du plus petit nombre */
    min=tab[0];
    for(i=1;i<MAXI;i++)
    {
        if(min>tab[i])
            min=tab[i];
    }

    /* clacul de la moyenne des nombres */
    for(i=0;i<MAXI;i++)
    {
        moy=moy+tab[i];
    }
    moy=moy/MAXI;


    cout<<endl<<"Le plus petit entier est : "<<min<<endl;
    cout<<"Le plus grand entier est : "<<max<<endl;
    cout<<"La moyenne est : "<<moy;

    getch();

}
//---------------------------------------------------------------------------
#pragma package(smart_init)



