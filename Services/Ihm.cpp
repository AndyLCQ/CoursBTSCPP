#include "Ihm.h"

#include <iostream>

//-------------------------------------------------------------------------------//
using namespace std;
//-------------------------------------------------------------------------------//
/*Méthode lancer*/
void Ihm::lancer()
{
int nbTempo;
char uniteTempo;

    do
    {
        cout << "Valeur de la temporisation"<<endl;
        cin >> nbTempo;
        if(nbTempo<=0)
            cout << " Un temps ne peut pas etre negatif !" <<endl;
    }while(nbTempo<=0);

    cout << "Unite du temps"<<endl;
    cin >> uniteTempo;
    objTempo = new Tempo(nbTempo,uniteTempo);

    cout << objTempo->getValeurTempo();
    objTempo->temporisation();

}

/*Méthode pour traiter le choix de l'utilisateur*/
void Ihm::traiteChoix()
{
    switch(choix)
    {
        case '1':  break;
    }
}

/*Méthode pour le menu et la saisie du choix */
void Ihm::saisirChoix()
{

}

/*Méthode destructeur*/
Ihm::~Ihm()
{
    delete objTempo;
}
