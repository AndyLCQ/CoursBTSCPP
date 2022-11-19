//---------------------------------------------------------------------------
#pragma hdrstop
#include <ctype.h>
#include <iostream>
#include "chaine.h"
using namespace std;
/*******************************************************************************
*   Initialisation des attributs
*
*   paramètres :
*       Entrée valNbCars : nombre de caractères de la chaîne
/******************************************************************************/
Chaine::Chaine(int valNbCar)
{
    nbMaxCar=valNbCar;          //nombre maxi de caractères dans la chaîne
    nbCar=0;                    //nombre de carcatères courants à 0
    tab=new char[nbMaxCar+1];   //création de la chaîne
    init();                     //initialisation de la chaîne à 0
}

/*******************************************************************************
*   Mise à zéro des cases de la chaîne
*
/******************************************************************************/
void Chaine::init()
{
    //cases de la chaîne mises à 0
    for(int i=0;i<=nbMaxCar;i++)
		tab[i]=0;
}

/*******************************************************************************
*   Libération de la mémoire allouée pour la chaîne
/******************************************************************************/
Chaine::~Chaine()
{
    delete [] tab;
}

/*******************************************************************************
*   Réinitialisation de la chaîne
/******************************************************************************/
void Chaine::vide()
{
	nbCar=0;
	init();
}

/*******************************************************************************
*   Ajouter d'un caractère en fin de chaîne
*
*   paramètres :
*       Entrée cara : caractère à rajouter
*
*   retour :
*       Booléen indiquant si le caractère a pu être rajouté
*
*   remarque :
*        Si la chaîne est pleine le caractère n'est pas rajouté
/******************************************************************************/
bool Chaine::ajouteCaractere(char cara)
{
	bool res=false;

	if(nbCar<nbMaxCar)
	{
		tab[nbCar]=cara;
		nbCar=nbCar+1;
		res=true;
	}

	return res;
}

/*******************************************************************************
*   Retirer le caractère en fin de chaîne
*
*   retour :
*       Caractère retiré
*
*   remarque :
*        On retourne 0 si la chaîne est vide
/******************************************************************************/
char Chaine::retireCaractere()
{
	char res=0;

	if(nbCar>0)
	{
		nbCar=nbCar-1;
		res=tab[nbCar];
		tab[nbCar]=0;
	}
	return res;
}

/*******************************************************************************
*   Afficher la chaîne
/******************************************************************************/
void Chaine::affiche()
{
	if(nbCar>0)
		cout<<"La chaine est : "<<tab<<endl;
	else
		cout<<"La chaine est vide"<<endl;
}

/*******************************************************************************
*   Mettre la chaîne en miniscule
/******************************************************************************/
void Chaine::minuscule()
{
	int i;

	if(nbCar!=0)
		for(i=0;i<nbCar;i++)
			if(tab[i]>='A' && tab[i]<='Z')
				tab[i]=(char)(tab[i]+0x20);
}

/*******************************************************************************
*   Mettre la chaîne en majuscule
/******************************************************************************/
void Chaine::majuscule()
{
	int i;

	if(nbCar!=0)
		for(i=0;i<nbCar;i++)
			if(tab[i]>='a' && tab[i]<='z')
				tab[i]=(char)(tab[i]-0x20);
}

/*******************************************************************************
*   Indiquer la taille courante de la chaîne
*
*   retour :
*       Taille de la chaîne
/******************************************************************************/
int Chaine::taille()
{
	return nbCar;
}
//---------------------------------------------------------------------------
