/*******************************************************************************
* NOM            :FichierCrypte
* TYPE           :classe de service
* SUJET          :crypte ou d�crypte un fichier. La cl� de cryptage en cach�e
*                 dans le fichier crypt�
*
* AUTEUR         :christian gu�z�nec
* VERSION        :1.0
* CREATION       :00/00/00
* DERNIERE MODIF :00/00/00
*
* ACCES SOURCE   :fichiercrypte.cpp
* ACCES OBJET    :fichiercrypte.obj
* ACCES EXE      :
* FABRICATION    :compilateur Borland c++ Builder 6
*
* LIMITES        :
* CONTRAINTES    : C++
*
*******************************************************************************/
/**************************** Inclusion de fichier ****************************/

#include "FichierCrypte.h"
#include <iostream.h>
#include "RC4.h"

/******************************************************************************
* ACTION		:FichierCrypte
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valSource:string(nom du fichier)
*                       valCryptage:bool�en(true:cryptage,false:d�cryptage)
*                       valExtension:string(extension du fichier crypt�,
*                       par d�faut cry)
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:nomSource,cryptage,fichierSource,fichierDestination
* LOCALES		:
******************************************************************************/
FichierCrypte::FichierCrypte(string valSource,bool valCryptage,string valExtension)
{

}

/******************************************************************************
* ACTION		:~FichierCrypte
* DESCRIPTION		:Destructeur
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:fichierSource,fichierDestination
* LOCALES		:
******************************************************************************/
FichierCrypte::~FichierCrypte()
{

}

/******************************************************************************
* ACTION		:nomFichierDestination
* DESCRIPTION		:g�n�re le nom du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypt�)
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:nomSource,nomDestination,cryptage
* LOCALES		:indice:entier(position du point dans la cha�ne)
******************************************************************************/
void FichierCrypte::nomFichierDestination(string valExtension)
{

}

/******************************************************************************
* ACTION		:controleExtensionFichier
* DESCRIPTION		:controle la validit� de l'extension du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypt�)
* SORTIES       	:
* E/S			:
* RESULTAT		:bool�en(indique si l'extension est valide)
*
* ATTRIBUTS		:
* LOCALES		:resu:bool�en(r�sultat du test)
******************************************************************************/
bool FichierCrypte::controleExtensionFichier(string valExtension)
{

}

/******************************************************************************
* ACTION		:crypteFichier
* DESCRIPTION		:cryptage du fichier, avec insertion apr�s le 3�me octet de
*                       la taille de la cl�, suivie de la cl�. Apr�s la cl� on
*                       trouve le reste du fichier crypt�
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:fichierSource,fichierDestination
* LOCALES		:monRC4:RC4(classe de cryptage),
*                       donn�e:octet(donn�e courante),compteur:entier,
*                       tailleCle:entier,cle:vector(cl� de cryptage)
*                       sauve:bool�en(indique si la cl�, ainsi que la taille,
*                       ont �t� sauv� dans le fichier destination)
*
******************************************************************************/
void FichierCrypte::crypteFichier()
{

}

/******************************************************************************
* ACTION		:decrypteFichier
* DESCRIPTION		:d�cryptage du fihcier
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS	       	:fichierSource,fichierDestination
* LOCALES	       	:donnee:octet(donn�e courante),
*                       tailleCle:entier,i:entier(compteur de boucle)
******************************************************************************/
void FichierCrypte::decrypteFichier()
{

}

/******************************************************************************
* ACTION		:getNomSource
* DESCRIPTION		:retourne le nom du fichier source
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:nomSource
* LOCALES		:
******************************************************************************/
string FichierCrypte::getNomSource()
{

}

/******************************************************************************
* ACTION		:getNomDestination
* DESCRIPTION		:retourne le nom du fichier destination
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:nomDestination
* LOCALES		:
******************************************************************************/
string FichierCrypte:: getNomDestination()
{

}

