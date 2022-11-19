/*******************************************************************************
* NOM            :Random
* TYPE           :classe de service
* SUJET          :génération aléatoire d'un tableau d'entiers dans
*                 une fouchette fixée
*
* AUTEUR         :christian guézénec
* VERSION        :1.0
* CREATION       :00/00/00
* DERNIERE MODIF :00/00/00
*
* ACCES SOURCE   :random.cpp
* ACCES OBJET    :random.obj
* ACCES EXE      :
* FABRICATION    :compilateur Borland c++ Builder 6
*
* LIMITES        :
* CONTRAINTES    : C++
*
*******************************************************************************/

/**************************** Inclusion de fichier ****************************/

#include "random.h"
#include <stdlib.h>
#include <time.h>

/******************************************************************************
* ACTION			:Random
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valMini:entier(valeur mini de la fourchette)
*                    valMaxi:entier(valeur maxi de la fourchette)
*                    valNbRandom:entier(nombre de valeur du tableau)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:maxi,mini,nbRandom,tabRandom
* LOCALES			:
******************************************************************************/
Random::Random(unsigned int valMini,unsigned int valMaxi,unsigned int valNbRandom)
{
    maxi=valMaxi;
    mini=valMini;
    inversionMaxiMini();
    nbRandom=valNbRandom;
    tabRandom=new int [nbRandom];
    srand (time (NULL));
    remplirTab();
}
/******************************************************************************
* ACTION			:testMaxiMini
* DESCRIPTION		:
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:maxi,mini,nbRandom,tabRandom
* LOCALES			:
******************************************************************************/
void Random::inversionMaxiMini()
{
    unsigned int inter;

    if(mini>maxi)
    {
        inter=mini;
        mini=maxi;
        maxi=inter;
    }
}
/******************************************************************************
* ACTION			:remplirTab
* DESCRIPTION		:remplit le tableau avec le nombre de valeurs aléatoires
*                    spécifiées.
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nbRandom,tabRandom
* LOCALES			:i:entier(compteur de bouble)
******************************************************************************/
void Random::remplirTab()
{
    unsigned int i;

    for(i=0;i<nbRandom;i++)
    {
        tabRandom[i]=calculValeur();
    }
}
/******************************************************************************
* ACTION			:calculValeur
* DESCRIPTION		:calcule une valeur aléatoire dans la fourchette
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:entier(nombre aléatoire)
*
* ATTRIBUTS			:maxi,mini
* LOCALES			:
******************************************************************************/
int Random::calculValeur() const
{
    return mini + (rand () % (maxi - mini + 1));
}

/******************************************************************************
* ACTION			:valeurUnique
* DESCRIPTION		:méthode statique qui retourne une valeur aléatoire, dans
*                    la fourchette spécifiée
*
* ENTREES   		:valMini:entier(valeur mini de la fourchette)
*                    valMaxi:entier(valeur maxi de la fourchette)
* SORTIES       	:
* E/S				:
* RESULTAT			:entier(nombre aléatoire)
*
* ATTRIBUTS			:
* LOCALES			:
******************************************************************************/
unsigned int Random::valeurUnique(unsigned int valMini,unsigned int valMaxi)
{
    srand (time (NULL));
    return valMini + (rand () % (valMaxi - valMini + 1));
}

/******************************************************************************
* ACTION			:getNbRandom
* DESCRIPTION		:retourne la taille du tableau
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nbRandom
* LOCALES			:
******************************************************************************/
unsigned int Random::getNbRandom()const
{
    return nbRandom;
}

/******************************************************************************
* ACTION			:setNbRandom
* DESCRIPTION		:redimensionne le tableau et le rempli
*
* ENTREES   		:valnbRandom:entier(taille du tableau)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nbRandom,tabRandom
* LOCALES			:
******************************************************************************/
void Random::setNbRandom(unsigned int valnbRandom)
{
    delete [] tabRandom;
    nbRandom=valnbRandom;
    tabRandom=new int [nbRandom];
    remplirTab();
}

/******************************************************************************
* ACTION			:getMaxi
* DESCRIPTION		:retourne la valeur haute de la fourchette
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:maxi
* LOCALES			:
******************************************************************************/
unsigned int Random::getMaxi()const
{
    return maxi;
}

/******************************************************************************
* ACTION			:setMaxi
* DESCRIPTION		:positionne la valeur haute de la fourchette
*
* ENTREES   		:valMaxi:entier(valeur maxi de la fourchette)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:maxi,mini,nbRandom,tabRandom
* LOCALES			:
******************************************************************************/
bool Random::setMaxi(unsigned int valMaxi)
{
    bool resu=false;

    if(valMaxi>mini)
    {
        maxi=valMaxi;
        remplirTab();
        resu=true;
    }

    return resu;
}

/******************************************************************************
* ACTION			:setMini
* DESCRIPTION		:positionne la valeur basse de la fourchette
*
* ENTREES   		:valMini:entier(valeur mini de la fourchette)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:mini
* LOCALES			:
******************************************************************************/
bool Random::setMini(unsigned int valMini)
{
    bool resu=false;

    if(valMini<maxi)
    {
        mini=valMini;
        remplirTab();
        resu=true;
    }

    return resu;
}
/******************************************************************************
* ACTION			:getMini
* DESCRIPTION		:retourne la valeur basse de la fourchette
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:mini
* LOCALES			:
******************************************************************************/
unsigned int Random::getMini()const
{
    return mini;
}

/******************************************************************************
* ACTION			:~Random
* DESCRIPTION		:Destructeur, libère le tableau
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tabRandom
* LOCALES			:
******************************************************************************/
Random::~Random()
{
    delete [] tabRandom;
};

/******************************************************************************
* ACTION			:operator[]
* DESCRIPTION		:permet de lire le contenu de la case, dont l'indice
*                    est spécifiée
*
* ENTREES   		:indice:entier(indice de la case)
* SORTIES       	:
* E/S				:
* RESULTAT			:entier(contenu de la case)
*
* ATTRIBUTS			:mini,nbRandom,tabRandom
* LOCALES			:res:entier(contenu de la case)
******************************************************************************/
int Random::operator[](unsigned int indice)const
{
    int res=mini-1;

    if(indice<nbRandom)
        res=tabRandom[indice];
    return res;
};

/******************************************************************************
* ACTION			:modifie
* DESCRIPTION		:modifie la valeur de la case dont l'indice est spécifié
*
* ENTREES   		:indice:entier(indice de la case)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nbRandom,tabRandom
* LOCALES			:
******************************************************************************/
unsigned int Random::modifie(unsigned int indice)
{
    if(indice<nbRandom)
        tabRandom[indice]=calculValeur();
    return tabRandom[indice];
}
