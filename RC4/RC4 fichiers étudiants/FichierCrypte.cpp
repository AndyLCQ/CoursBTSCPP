/*******************************************************************************
* NOM            :FichierCrypte
* TYPE           :classe de service
* SUJET          :crypte ou décrypte un fichier. La clé de cryptage en cachée
*                 dans le fichier crypté
*
* AUTEUR         :christian guézénec
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
*                       valCryptage:booléen(true:cryptage,false:décryptage)
*                       valExtension:string(extension du fichier crypté,
*                       par défaut cry)
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
* DESCRIPTION		:génère le nom du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypté)
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:nomSource,nomDestination,cryptage
* LOCALES		:indice:entier(position du point dans la chaîne)
******************************************************************************/
void FichierCrypte::nomFichierDestination(string valExtension)
{

}

/******************************************************************************
* ACTION		:controleExtensionFichier
* DESCRIPTION		:controle la validité de l'extension du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypté)
* SORTIES       	:
* E/S			:
* RESULTAT		:booléen(indique si l'extension est valide)
*
* ATTRIBUTS		:
* LOCALES		:resu:booléen(résultat du test)
******************************************************************************/
bool FichierCrypte::controleExtensionFichier(string valExtension)
{

}

/******************************************************************************
* ACTION		:crypteFichier
* DESCRIPTION		:cryptage du fichier, avec insertion après le 3ème octet de
*                       la taille de la clé, suivie de la clé. Après la clé on
*                       trouve le reste du fichier crypté
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS		:fichierSource,fichierDestination
* LOCALES		:monRC4:RC4(classe de cryptage),
*                       donnée:octet(donnée courante),compteur:entier,
*                       tailleCle:entier,cle:vector(clé de cryptage)
*                       sauve:booléen(indique si la clé, ainsi que la taille,
*                       ont été sauvé dans le fichier destination)
*
******************************************************************************/
void FichierCrypte::crypteFichier()
{

}

/******************************************************************************
* ACTION		:decrypteFichier
* DESCRIPTION		:décryptage du fihcier
*
* ENTREES   		:
* SORTIES       	:
* E/S			:
* RESULTAT		:
*
* ATTRIBUTS	       	:fichierSource,fichierDestination
* LOCALES	       	:donnee:octet(donnée courante),
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

