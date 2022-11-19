/*******************************************************************************
* NOM            :Application
* TYPE           :classe d'interface
* SUJET          :cryptage et decryptage d'un fichier
*
* AUTEUR         :christian guézénec
* VERSION        :1.0
* CREATION       :00/00/00
* DERNIERE MODIF :00/00/00
*
* ACCES SOURCE   :IHMApplication.cpp
* ACCES OBJET    :IHMApplication.obj
* ACCES EXE      :
* FABRICATION    :compilateur Borland c++ Builder 6
*
* LIMITES        :
* CONTRAINTES    : C++
*
*******************************************************************************/
/**************************** Inclusion de fichier ****************************/
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "IHMApplication.h"


/******************************************************************************
* ACTION			:IHMApplication
* DESCRIPTION		:Constructeur
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:fic,FIN
* LOCALES			:
******************************************************************************/
IHMApplication::IHMApplication():FIN('3')
{
    fic=NULL;
}

/******************************************************************************
* ACTION			:traiterChoix
* DESCRIPTION		:traite le choix de l'utilisateur
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:choixUtilisateur
* LOCALES			:
******************************************************************************/
void IHMApplication::traiterChoix()
{
	switch (choixUtilisateur)
	{
		case '1':
			crypter();
			break;
		case '2':
			decrypter();
			break;
	}
}

/******************************************************************************
* ACTION			: afficherChoix()
* DESCRIPTION		: affiche le menu
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			: choixUtilisateur
* LOCALES			:
******************************************************************************/
void IHMApplication::afficherChoix()
{
	system("cls");
	cout << "\n\t\t\tCRYPTAGE ET DECRYPTAGE";
	cout << "\n\n\t\t\t1. Cryter un fichier";
	cout << "\n\t\t\t2. Decrypter un fichier";
	cout << "\n\t\t\t3. Fin\n\n";
	cout << "\t\t\tEntrer votre choix :";
	cin >> choixUtilisateur;
}

/******************************************************************************
* ACTION			: lancer
* DESCRIPTION		: point d'entree de l'application
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			: choixUtilisateur,FIN
* LOCALES			:
******************************************************************************/
void IHMApplication::lancer()
{
    do
    {
        afficherChoix();
        traiterChoix();
    }
    while (choixUtilisateur!=FIN);
}

/******************************************************************************
* ACTION			: ~IHMApplication
* DESCRIPTION		: destructeur
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:
* LOCALES			:
******************************************************************************/
IHMApplication::~IHMApplication()
{

}

/******************************************************************************
* ACTION			: crypter()
* DESCRIPTION		: cryptage d'un fichier
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			: fic,extension
* LOCALES			:
******************************************************************************/
void IHMApplication::crypter()
{
    if(fic!=NULL)
        delete fic;

    if(saisieFichier())
    {
        fic=new FichierCrypte(nomFic,true,extension);
        fic->crypteFichier();
        cout << "\nLe fichier est crypte sous le nom : " << fic->getNomDestination();
        delete fic;
        fic=NULL;
    }
    else
        cout << "\nLe fichier n'existe pas";
    getch();
}

/******************************************************************************
* ACTION			: decrypter
* DESCRIPTION		: décryptage d'un fichier
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			: fic,extension
* LOCALES			:
******************************************************************************/
void IHMApplication::decrypter()
{
    if(fic!=NULL)
        delete fic;

    if(saisieFichier())
    {
        fic=new FichierCrypte(nomFic,false,extension);
        fic->decrypteFichier();
        cout << "\nLe fichier est decrypte sous le nom : " << fic->getNomDestination();
        delete fic;
        fic=NULL;
    }
    else
        cout << "\nLe fichier n'existe pas";
    getch();
}

/******************************************************************************
* ACTION			: saisieFichier
* DESCRIPTION		: saisie du nom du fichier source, vérification de son
*                     existance (retour de la méhode) et saisie de l'extension
*                     du fichier destination.
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			: booleen(fichier trouve ou non)
*
* ATTRIBUTS			:
* LOCALES			: repExtension:caratere(choix ou non de l'extension)
*                     rechercheNom:booléen(fichier trouve ou non)
******************************************************************************/
bool IHMApplication::saisieFichier()
{
    char repExtension;
    bool rechercheNom=false;

    cout << "\nEntrer le nom du ficher : ";
    cin >> nomFic;
    if(GetFileAttributes(nomFic.c_str())!=(unsigned)-1)
    {
        rechercheNom=true;
        cout << "\nSaisie extension (O/N) : ";
        cin >> repExtension;
        if( toupper(repExtension)=='O')
        {
            cout << "\nEntrer entension : ";
            cin >> extension;
        }
        else
            extension.clear();
    }

    return rechercheNom;
}
//---------------------------------------------------------------------------
