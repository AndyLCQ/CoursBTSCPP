#include "ihm.h"
#include <iostream>

//-------------------------------------------------------------------------------//
using namespace std;
//-------------------------------------------------------------------------------//
/*Méthode lancer*/
void Ihm::lancer()
{
    int taille;
    cout << "Saisir le nombre de caractere maximal"<< endl;
    cin >> taille;


//objet
    objChaine = new Chaine(taille);

    do
    {
        saisirChoix();
        traiteChoix();

    }
    while(choix!='8');
}

/*Méthode pour traiter le choix de l'utilisateur*/
void Ihm::traiteChoix()
{
    switch( choix )
    {
        case '1':
            char caractere;
            cout << " Entrer le caractere a ajouter :"<< endl;
            cin >> caractere;
            objChaine->ajouteCaractere(caractere);
                  break;

        case '2':
            objChaine->retireCaractere();
            cout << " Le dernier caractere a ete retiré."<< endl;
                  break;

        case '3':
            objChaine->affiche();
                  break;

        case '4':
            objChaine->vide();
            cout << "La chaine a été videe."<<endl;
                  break;

        case '5':
            cout << "Le nombre actuel de caractere dans la chaine est de :"<<objChaine->taille()<<endl;
                ; break;

        case '6':
            cout << "Le programme met en minuscule la chaine :"<<endl;
            objChaine->minuscule();
            objChaine->affiche();

                break;

        case '7':
            cout << "Le programme met en majuscule la chaine :"<<endl;
            objChaine->majuscule();
            objChaine->affiche();
                  break;

        case '8':
            cout<<"Fin du programme"<<endl;
            break;

        default:
            cout << "Probleme de saisie ! Entrez un chiffre entre 1 et 8"<<endl;  break;
  }

}

/*Méthode pour le menu et la saisie du choix */
void Ihm::saisirChoix()
{
    /*Affiche le Menu*/
    cout << "\n Menu"<<endl;
    cout << "1.Ajoute caractere" <<endl<<"2.Retire caractere"<<endl<<"3.Affiche chaîne"<<endl <<"4.Vide chaine"<<endl <<"5.Taille de la Chaine"<<endl<<"6.Caracteres en minuscule"<<endl<<"7.Caracteres en majuscule"<<endl<<"8.Fin"<<endl;

    /*Saisie du choix*/
    cin >> choix;
}

/*Méthode destructeur*/
Ihm::~Ihm()
{
    delete objChaine;
}
