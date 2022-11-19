#include "ihm.h"
#include <iostream>

//-------------------------------------------------------------------------------//
using namespace std;
//-------------------------------------------------------------------------------//
/*Méthode lancer*/
void Ihm::lancer()
{
int Nb;
    cout << "Bienvenue dans le Tirage du Loto !"<< endl;

    cout << "Nombre de tirage :"<<endl;
    cin >> Nb;
    objTirageLoto = new TirageLoto(Nb);

    do
    {
        saisirChoix();
        traiteChoix();

    }
    while(choix!='f');
}

/*Méthode pour traiter le choix de l'utilisateur*/
void Ihm::traiteChoix()
{

    switch( choix )
    {
        case '1':
            cout << "Tirage en cours . . ."<<endl;
            objTirageLoto->tirageNbr();
            break;

        case '2' :
            cout << "Affichage du tirage trié" <<endl;
            for(int i=0; i<objTirageLoto->getNbNumero(); i++)
                cout << objTirageLoto->litNumeroTirer(TRIE,i)<<endl;
            break;

        case '3' :
            cout << "Affichage du tirage non trié" <<endl;
            for(int i=0; i<objTirageLoto->getNbNumero(); i++){
                cout << objTirageLoto->litNumeroTirer(NON_TRIE,i)<<endl;
            }
            break;

        case 'f':
            cout<<"Fin du programme"<<endl;
            break;

        default:
            cout << "Probleme de saisie ! "<<endl;  break;
  }

}

/*Méthode pour le menu et la saisie du choix */
void Ihm::saisirChoix()
{
    /*Affiche le Menu*/
    cout << "\n Menu"<<endl;
    cout << "1. Proceder au tirage "<<endl
    << "2. Afficher le tirage triee"<<endl
    << "3. Afficher le tirage non trie"<<endl
    <<"f.Fin"<<endl;

    /*Saisie du choix*/
    cin >> choix;
}

/*Méthode destructeur*/
Ihm::~Ihm()
{
    delete objTirageLoto;
}
