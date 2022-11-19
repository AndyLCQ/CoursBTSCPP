//---------------------------------------------------------------------------
#pragma hdrstop
#include <ctype.h>
#include <iostream>
#include "chaine.h"
using namespace std;
/*******************************************************************************
*   Initialisation des attributs
*
*   param�tres :
*       Entr�e valNbCars : nombre de caract�res de la cha�ne
/******************************************************************************/
Chaine::Chaine(int valNbCar)
{
    nbMaxCar=valNbCar;          //nombre maxi de caract�res dans la cha�ne
    nbCar=0;                    //nombre de carcat�res courants � 0
    tab=new char[nbMaxCar+1];   //cr�ation de la cha�ne
    init();                     //initialisation de la cha�ne � 0
}

/*******************************************************************************
*   Mise � z�ro des cases de la cha�ne
*
/******************************************************************************/
void Chaine::init()
{
    //cases de la cha�ne mises � 0
    for(int i=0;i<=nbMaxCar;i++)
		tab[i]=0;
}

/*******************************************************************************
*   Lib�ration de la m�moire allou�e pour la cha�ne
/******************************************************************************/
Chaine::~Chaine()
{
    delete [] tab;
}

/*******************************************************************************
*   R�initialisation de la cha�ne
/******************************************************************************/
void Chaine::vide()
{
	nbCar=0;
	init();
}

/*******************************************************************************
*   Ajouter d'un caract�re en fin de cha�ne
*
*   param�tres :
*       Entr�e cara : caract�re � rajouter
*
*   retour :
*       Bool�en indiquant si le caract�re a pu �tre rajout�
*
*   remarque :
*        Si la cha�ne est pleine le caract�re n'est pas rajout�
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
*   Retirer le caract�re en fin de cha�ne
*
*   retour :
*       Caract�re retir�
*
*   remarque :
*        On retourne 0 si la cha�ne est vide
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
*   Afficher la cha�ne
/******************************************************************************/
void Chaine::affiche()
{
	if(nbCar>0)
		cout<<"La chaine est : "<<tab<<endl;
	else
		cout<<"La chaine est vide"<<endl;
}

/*******************************************************************************
*   Mettre la cha�ne en miniscule
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
*   Mettre la cha�ne en majuscule
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
*   Indiquer la taille courante de la cha�ne
*
*   retour :
*       Taille de la cha�ne
/******************************************************************************/
int Chaine::taille()
{
	return nbCar;
}
//---------------------------------------------------------------------------
