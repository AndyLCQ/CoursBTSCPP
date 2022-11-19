#ifndef ELEVE_H
#define ELEVE_H
#include <fstream>
#include <iostream>

using namespace std;
class Eleve
{
public:
    Eleve();
    void SaisieEleve();     //Saisie d'un éleve
    void AfficheEleve();        //Affiche les donnees
    float RecupNote();  //accesseur de Note
    void enregistreEleve(fstream & flux);   //Ecrit de façon formaté un éléve dans le fichier
    void litEleve(fstream & flux);  //Permet de lire de façon formatée
private:
    char nomT[29];  //Tableau pour le nom d'eleve
    float note;
};

#endif // ELEVE_H
