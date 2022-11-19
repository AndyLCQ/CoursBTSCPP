#include "section.h"
#include <iostream>

using namespace std;
Section::Section()
{
    TabEleve.clear();
}
//-----------------------------------------------------------------------------------------------------------//
void Section::SaisieSection()
{
    cout << "Nombre d'eleve dans la promotion :";
    cin >> nbreEleves;
    TabEleve.resize(nbreEleves);
    for(int i=0; i<nbreEleves;i++)
    {
        TabEleve[i].SaisieEleve();

    }

}
//-----------------------------------------------------------------------------------------------------------//
void Section::traitement()
{
     float somme =0;
     for(int i=0; i<nbreEleves; i++)
     {
         somme = somme+ TabEleve[i].RecupNote();
     }
     moy = somme / nbreEleves;
}

//-----------------------------------------------------------------------------------------------------------//
void Section::AfficheSection()
{
    for(int i=0; i<nbreEleves;i++)
    {
        TabEleve[i].AfficheEleve();
    }
    cout <<" La moyenne de section est de " << moy << endl;
}
//-----------------------------------------------------------------------------------------------------------//
void Section::enregistreSection()
{
    flux.open("../section/classe", ios::out);
    for(int i=0; i<nbreEleves; i++)
    {
        unEleve=TabEleve[i];
        unEleve.enregistreEleve(flux);
    }
    flux.close();
}
//-----------------------------------------------------------------------------------------------------------//
void Section::litSection()
{
    while(flux.peek()!=EOF)
    {
        unEleve.litEleve(flux);
        flux.seekg(1, ios::cur);
        nbreEleves++;
        TabEleve.push_back(unEleve);
    }
}

