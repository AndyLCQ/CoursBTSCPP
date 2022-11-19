//---------------------------------------------------------------------------

#include <conio.h>
#include "IHM.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
/*******************************************************************************
*   Instanciation de la classe Chaine
*
*   remarque:
*       initialisation de FIN à 8
******************************************************************************/
IHM::IHM():FIN('8')
{
    int taille;

    system("cls");
    cout<<"Entrer la taille maxi de la chaine : ";
	cin>>taille;
    c1 = new Chaine(taille);
}

/*******************************************************************************
*   Libération de la mémoire allouée à l'objet de type Chaîne
******************************************************************************/
IHM::~IHM()
{
    delete c1;
}

/*******************************************************************************
*   Lancement du programme
******************************************************************************/
void IHM::lancer()
{

	do
	{
		saisirChoix();
		traiteChoix();
	}
	while(choix != FIN);

}

/*******************************************************************************
*   Traitement du choix de l'utilisateur
******************************************************************************/
void IHM::traiteChoix()
{
	switch(choix)
	{
		case '1':
            ajouterCaratere();
			break;
		case '2':
            retirerCaractere();
			break;
		case '3':
            afficherChaine();
			break;
		case '4':
            viderChaine();
			break;
		case '5':
            tailleChaine();
			break;
		case '6':
            mettreEnMinuscule();
			break;
		case '7':
            mettreEnMajuscule();
			break;
	}
}

/*******************************************************************************
*   Affichage du menu et saisie du choix de l'utilisateur
******************************************************************************/
void IHM::saisirChoix()
{
 	system("cls");
	cout<<"\t\t\tMenu";
	cout<<"\n\n\t1.Ajoute caractere";
	cout<<"\n\t2.Retire caractere";
	cout<<"\n\t3.Affiche chaine";
	cout<<"\n\t4.Vide chaine";
	cout<<"\n\t5.Taille de la chaine";
	cout<<"\n\t6.Caracteres en minuscule";
	cout<<"\n\t7.Caracteres en majuscule";
	cout<<"\n\t8.Fin";
	choix=(char)getch();
	system("cls");
}

/*******************************************************************************
*   Ajout si possible d'un caractère en fin de chaîne
*****************************************************************************/
void IHM::ajouterCaratere()
{
    char val;
	bool res;

    cout<<"Entrer le caractere a ajouter : ";
	cin>>val;

	res=c1->ajouteCaractere(val);

	if(res==true)
	    cout<<endl<<endl<<"Le caractere "<<val<<" a ete ajoute";
    else
	    cout<<endl<<endl<<"La chaine est pleine";

    getch();
}

/*******************************************************************************
*   Suppression si possible d'un caractère en fin de chaîne
******************************************************************************/
void IHM::retirerCaractere()
{
	char val;

    val=c1->retireCaractere();

	if(val!=0)
	    cout<<endl<<endl<<"Le caractere "<<val<<" a ete retire";
    else
	    cout<<endl<<endl<<"La chaine est vide";

    getch();
}

/*******************************************************************************
*   Affichage de la chaîne
******************************************************************************/
void IHM::afficherChaine()
{
    c1->affiche();
    getch();
}

/*******************************************************************************
*   Chaîne vide
******************************************************************************/
void IHM::viderChaine()
{
    c1->vide();
    cout<<"La chaine est vide";
    getch();
}

/*******************************************************************************
*   Taille de la chaîne
******************************************************************************/
void IHM::tailleChaine()
{
    cout<<"La taille de la chaine est : "<<c1->taille();
    getch();
}

/*******************************************************************************
*   Mise en minuscule des caractères de la chaîne
******************************************************************************/
void IHM::mettreEnMinuscule()
{
    c1->minuscule();
	cout<<"Chaine mis en minuscule";
    getch();
}

/*******************************************************************************
*   Mise en majuscule des caractères de la chaîne
******************************************************************************/
void IHM::mettreEnMajuscule()
{
    c1->majuscule();
	cout<<"Chaine mis en majuscule";
    getch();
}
//---------------------------------------------------------------------------
