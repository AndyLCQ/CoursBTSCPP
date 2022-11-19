#include "ihm.h"
#include <iostream>

//-------------------------------------------------------------------------------//
using namespace std;
//-------------------------------------------------------------------------------//
/*M�thode lancer*/
void Ihm::lancer()
{
    char nIsbn[14];
    cout << "Entrer l'ISBN :"<< endl;
    cin >> nIsbn ;

    objIsbn=new Isbn(nIsbn);

    do
    {
        saisirChoix();
        traiteChoix();

    }
    while(choix!='f');
}

/*M�thode pour traiter le choix de l'utilisateur*/
void Ihm::traiteChoix()
{
    int retour=0;
    switch( choix )
    {
        case '1':
            cout << "Verification de controle :"<<endl;

            retour=objIsbn->verifChec();
            if(retour==1)
            {
                cout << "Verification OK !" <<endl;
            }
            else
            {
                cout << "Probleme de verification !"<<endl;
            }
            break;

        case '2' :
            cout << "Affichage des champs" <<endl;
            objIsbn->afficheChamp();
            break;


        case 'f':
            cout<<"Fin du programme"<<endl;
            break;

        default:
            cout << "Probleme de saisie ! "<<endl;  break;
  }

}

/*M�thode pour le menu et la saisie du choix */
void Ihm::saisirChoix()
{
    /*Affiche le Menu*/
    cout << "\n Menu"<<endl;
    cout << "1. Verifier le nombre de controle"<<endl
    << "2. Affichage des champs"<<endl
    <<"f.Fin"<<endl;

    /*Saisie du choix*/
    cin >> choix;
}

/*M�thode destructeur*/
Ihm::~Ihm()
{
    delete objIsbn;
}
