#include "Ihm.h"

#include <iostream>

//-------------------------------------------------------------------------------//
using namespace std;
//-------------------------------------------------------------------------------//
/*M�thode lancer*/
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

/*M�thode pour traiter le choix de l'utilisateur*/
void Ihm::traiteChoix()
{
    switch(choix)
    {
        case '1':  break;
    }
}

/*M�thode pour le menu et la saisie du choix */
void Ihm::saisirChoix()
{

}

/*M�thode destructeur*/
Ihm::~Ihm()
{
    delete objTempo;
}
