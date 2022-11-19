
#include "RC4.h"
#include <iostream>
#include "random.h"

/******************************************************************************
* ACTION			:Sequence
* DESCRIPTION		:Constructeur
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:valeur
* LOCALES			:
******************************************************************************/
Sequence::Sequence(unsigned char valValeur)
{
    valeur=valValeur;
}

/******************************************************************************
* ACTION			:operator()
* DESCRIPTION		:retourne valeur qui est ensuite incr�ment�
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:valeur
* LOCALES			:
******************************************************************************/
unsigned char Sequence::operator() ()
{
    return valeur++;
}
/*******************************************************************************
* NOM            :RC4
* TYPE           :classe de service
* SUJET          :crypte ou d�crypte des donn�es
*
* AUTEUR         :christian gu�z�nec
* VERSION        :1.0
* CREATION       :00/00/00
* DERNIERE MODIF :00/00/00
*
* ACCES SOURCE   :rc4.cpp
* ACCES OBJET    :rc4.obj
* ACCES EXE      :
* FABRICATION    :compilateur Borland c++ Builder 5
*
* LIMITES        :
* CONTRAINTES    : C++
*
*******************************************************************************/

/******************************************************************************
* ACTION			:RC4
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valTailleCle:entier(longueur de la cl�)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tableauEtat,tailleTableauEtat,tailleCle
* LOCALES			:
******************************************************************************/
RC4::RC4(unsigned int valTailleCle):tailleTableauEtat(256)
{
    tableauEtat.resize(tailleTableauEtat);
    if(valTailleCle==0)
        tailleCle=Random::valeurUnique(40,255);
    else
        tailleCle=valTailleCle;
    genereCle();
    initCodageDecodage();
}

/******************************************************************************
* ACTION			:RC4
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valMaCle:tableau d'octets(cl� de cryptage)
*                    valTaille:longueur de la cl�
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tableauEtat,tailleTableauEtat,tailleCle,maCle
* LOCALES			:
******************************************************************************/
RC4::RC4(unsigned char *valMaCle,int valTaille):tailleTableauEtat(256)
{
     tableauEtat.resize(tailleTableauEtat);
     tailleCle=valTaille;
     maCle.resize(tailleCle);
     copy(valMaCle,valMaCle+valTaille,maCle.begin());
/*     for(unsigned int i=0;i<tailleCle;i++)
        maCle[i]=valMaCle[i];*/
     initCodageDecodage();
}

/******************************************************************************
* ACTION			:RC4
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valMaCle:tableau d'octets(cl� de cryptage)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tableauEtat,tailleTableauEtat,tailleCle,maCle
* LOCALES			:
******************************************************************************/
RC4::RC4(vector <unsigned char> valMaCle):tailleTableauEtat(256)
{
    tableauEtat.resize(tailleTableauEtat);
    maCle=valMaCle;
    tailleCle=valMaCle.size();
    initCodageDecodage();
}

/******************************************************************************
* ACTION			:initCodageDecodage
* DESCRIPTION		:initialisation des diff�rents attributs avant un cryptage
*                    ou un d�cryptage
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tableauEtat,i,j
* LOCALES			:
******************************************************************************/
void RC4::initCodageDecodage()
{
    j=0;
    generate(tableauEtat.begin(),tableauEtat.end(),Sequence(0));
    melangeTableauEtat();
    i=0;
    j=0;
}

/******************************************************************************
* ACTION			:chiffrage
* DESCRIPTION		:retourne l'octet qui servira � crypter la donn�e
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:entier(octet pour le cryptage)
*
* ATTRIBUTS			:tableauEtat,tailleTableauEtat,i,j
* LOCALES			:n:entier(valeur de retour)
******************************************************************************/
unsigned char RC4::chiffrage()
{
    unsigned char n;

    i=(i+1)%tailleTableauEtat;
    j=(j+tableauEtat[i])%tailleTableauEtat;

    swap(&tableauEtat[i],&tableauEtat[j]);
    n=(tableauEtat[i]+tableauEtat[j])%tailleTableauEtat;

    return tableauEtat[n];
}

/******************************************************************************
* ACTION			:genereCle
* DESCRIPTION		:g�n�ration d'une cl� al�atoire dont la longueur est fix�e
*                    par tailleCle
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tailleCle,maCle
* LOCALES			:i:entier(compteur de boucle)
******************************************************************************/
void RC4::genereCle()
{
    Random cle(1,255,tailleCle);

    maCle.resize(tailleCle);
    for(unsigned int i=0;i<tailleCle;i++)
        maCle[i]=cle[i];
}

/******************************************************************************
* ACTION			:litCle
* DESCRIPTION		:retourne la cl�
*
* ENTREES   		:
* SORTIES       	:vector(cl� de cryptage)
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:maCle
* LOCALES			:
******************************************************************************/
vector <unsigned char> RC4::litCle()
{
    return maCle;
}


/******************************************************************************
* ACTION			:swap
* DESCRIPTION		:inversion de deux octets
*
* ENTREES   		:
* SORTIES       	:
* E/S				:val1:entier(premier octet)
*                    val2:entier(deuxi�me octet)
* RESULTAT			:
*
* ATTRIBUTS			:tableauEtat,tailleTableauEtat,tailleCle,maCle
* LOCALES			:inter:entier(valeur interm�diaire)
******************************************************************************/
void RC4::swap(unsigned char* val1,unsigned char * val2)
{
    unsigned char inter;

    inter=*val1;
    *val1=*val2;
    *val2=inter;
}

/******************************************************************************
* ACTION			:melangeTableauEtat
* DESCRIPTION		:m�lange le tableauEtat en fonction de la cl�
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:tailleTableauEtat,tailleTableauEtat,maCle
* LOCALES			:i,i:entier(indices de tableau)
******************************************************************************/
void RC4::melangeTableauEtat()
{
    unsigned int i,j=0,indiceCle;


    for(i=0;i<tailleTableauEtat;i++)
    {
        indiceCle=i % tailleCle;
        j=(j+tableauEtat[i]+maCle[indiceCle]) % tailleTableauEtat;

        swap(&tableauEtat[i],&tableauEtat[j]);
   }
}

/******************************************************************************
* ACTION			:litTailleCle
* DESCRIPTION		:retourne la longueur de la cl�
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:entier(longueur de la cl�)
*
* ATTRIBUTS			:tableauEtat,tailleTableauEtat,tailleCle,maCle
* LOCALES			:
******************************************************************************/
 unsigned int RC4::litTailleCle()
 {
    return  tailleCle;
 }
//---------------------------------------------------------------------------
/*int main(int argc, char* argv[])
{
    RC4 k(3);;
    string g="toto";

    vector <unsigned char> cle=k.litCle();
    cout<<cle.size()<<endl;
    cout<<cle[0]<<cle[1]<<cle[2];
    k.initCodageDecodage();
    for(unsigned int i=0;i<g.length();i++)
        g[i]=g[i]^k.chiffrage();
    k.initCodageDecodage();
    for(unsigned int i=0;i<g.length();i++)
        g[i]=g[i]^k.chiffrage();

   return 0;
}*/
//---------------------------------------------------------------------------
