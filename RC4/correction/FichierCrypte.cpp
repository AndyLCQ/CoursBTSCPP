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
#include <iostream>
#include "RC4.h"

/******************************************************************************
* ACTION			:FichierCrypte
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valSource:string(nom du fichier)
*                    valCryptage:bool�en(true:cryptage,false:d�cryptage)
*                    valExtension:string(extension du fichier crypt�,
*                    par d�faut cry)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nomSource,cryptage,fichierSource,fichierDestination
* LOCALES			:
******************************************************************************/
FichierCrypte::FichierCrypte(string valSource,bool valCryptage,string valExtension)
{
    nomSource=valSource;
    cryptage=valCryptage;

    nomFichierDestination(valExtension);
    fichierSource.open(nomSource.c_str(),ios::in|ios::out|ios::binary);
    fichierDestination.open(nomDestination.c_str(),ios::out|ios::binary);
}

/******************************************************************************
* ACTION			:~FichierCrypte
* DESCRIPTION		:Destructeur
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:fichierSource,fichierDestination
* LOCALES			:
******************************************************************************/
FichierCrypte::~FichierCrypte()
{
    fichierSource.close();
    fichierDestination.close();
}

/******************************************************************************
* ACTION			:nomFichierDestination
* DESCRIPTION		:g�n�re le nom du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypt�)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nomSource,nomDestination,cryptage
* LOCALES			:indice:entier(position du point dans la cha�ne)
******************************************************************************/
void FichierCrypte::nomFichierDestination(string valExtension)
{
    int indice=nomSource.find(".");
    nomDestination.assign(nomSource,0,indice);
    // si l'extension n'est pas pr�sente ou est invalide on g�n�re l'extension
    if(!controleExtensionFichier(valExtension))
        if(cryptage)
            // cry en cas de cryptage
            nomDestination.insert(nomDestination.size(),".cry");
            // txt en cas de d�cryptage
        else
            nomDestination.insert(nomDestination.size(),".txt");
    else
        nomDestination.insert(nomDestination.size(),"."+valExtension);
}

/******************************************************************************
* ACTION			:controleExtensionFichier
* DESCRIPTION		:controle la validit� de l'extension du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypt�)
* SORTIES       	:
* E/S				:
* RESULTAT			:bool�en(indique si l'extension est valide)
*
* ATTRIBUTS			:
* LOCALES			:resu:bool�en(r�sultat du test)
******************************************************************************/
bool FichierCrypte::controleExtensionFichier(string valExtension)
{
    bool resu=true;

    if(valExtension.empty())
        resu=false;
    else if(valExtension.length()>3)
        resu=false;
    else if(valExtension[0]>='0' && valExtension[0]<='9')
        resu=false;

    return resu;
}

/******************************************************************************
* ACTION			:crypteFichier
* DESCRIPTION		:cryptage du fichier, avec insertion apr�s le 3�me octet de
*                    la taille de la cl�, suivie de la cl�. Apr�s la cl� on
*                    trouve le reste du fichier crypt�
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:fichierSource,fichierDestination
* LOCALES			:monRC4:RC4(classe de cryptage),
*                    donn�e:octet(donn�e courante),compteur:entier,
*                    tailleCle:entier,cle:vector(cl� de cryptage)
*                    sauve:bool�en(indique si la cl�, ainsi que la taille,
*                    ont �t� sauv� dans le fichier destination)
*
******************************************************************************/
void FichierCrypte::crypteFichier()
{
    monRC4=new RC4;
    fichierSource.seekg(0,ios::beg);
    fichierDestination.seekp(0,ios::beg);
    unsigned char donnee;
    unsigned int compteur=0;
    unsigned int tailleCle=monRC4->litTailleCle();
    vector <unsigned char> cle=monRC4->litCle();
    char * recupCle;

    // cryptage du fichier
    while(fichierSource.read((char *)&donnee,sizeof(donnee)))
    {
        if(compteur==3)    // si 4 �me octets on sauve la taille de la cl� et la cl�
        {
            //sauvegarde de la taille
            fichierDestination.write((char *)&tailleCle,sizeof(tailleCle));

            //sauvegarde de la cl�
            recupCle=new char [tailleCle];

            copy(cle.begin(),cle.end(),recupCle);
            fichierDestination.write(recupCle,tailleCle);
            delete [] recupCle;
        }
        //compteur de donn�es
        compteur++;

        //cryptage de la donn�e courante
        donnee = donnee ^ monRC4->chiffrage();

        //�criture dans le fichier de destination
        fichierDestination.write((char *)&donnee,sizeof(donnee));
    }

    delete monRC4;
}

/******************************************************************************
* ACTION			:decrypteFichier
* DESCRIPTION		:d�cryptage du fihcier
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:fichierSource,fichierDestination
* LOCALES			:donnee:octet(donn�e courante),
*                    tailleCle:entier,i:entier(compteur de boucle)
******************************************************************************/
void FichierCrypte::decrypteFichier()
{
    unsigned char donnee;
    unsigned char * recupCle;

    // positionnement pour r�cup�rer la taille de la cl�
    fichierSource.seekg(3,ios::beg);
    fichierDestination.seekp(0,ios::beg);

    unsigned int tailleCle;

    //lecture de la taille de la cl�
    fichierSource.read((char*)&tailleCle,sizeof(tailleCle));

    //initialisation de la longueur de la cl�
    vector <unsigned char> cle(tailleCle);

    //r�cup�ration de la cl�
    recupCle=new unsigned char [tailleCle];

    fichierSource.read((char *)recupCle,tailleCle);
    copy(recupCle,recupCle+tailleCle,cle.begin());
    delete [] recupCle;

    monRC4=new RC4(cle);

    //d�crypyage et sauvegarde des 3 premiers octets du fichier
    fichierSource.seekg(0,ios::beg);
    for(unsigned int i=0;i<3;i++)
    {
        fichierSource.read((char *)&donnee,sizeof(donnee));
        donnee=donnee ^ monRC4->chiffrage();
        fichierDestination.write((char *)&donnee,sizeof(donnee));
    }

    //d�cryptage et sauvegarde du reste du fichier
    fichierSource.seekg(3+sizeof(unsigned int)+sizeof(unsigned char)*tailleCle,ios::beg);

    while(fichierSource.read((char *)&donnee,sizeof(donnee)))
    {
        donnee=donnee ^ monRC4->chiffrage();
        fichierDestination.write((char *)&donnee,sizeof(donnee));
    }
    delete monRC4;
}

/******************************************************************************
* ACTION			:getNomSource
* DESCRIPTION		:retourne le nom du fichier source
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nomSource
* LOCALES			:
******************************************************************************/
string FichierCrypte::getNomSource()
{
    return nomSource;
}

/******************************************************************************
* ACTION			:getNomDestination
* DESCRIPTION		:retourne le nom du fichier destination
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nomDestination
* LOCALES			:
******************************************************************************/
string FichierCrypte:: getNomDestination()
{
    return nomDestination;
}
//---------------------------------------------------------------------------
/*int main(int argc, char* argv[])
{
   FichierCrypte *f=new FichierCrypte("toto.txt",true);
   f->crypteFichier();
   delete f;
   FichierCrypte *g=new FichierCrypte ("toto.cry",false,"ttt");
   g->decrypteFichier();
   delete g;
   return 0;
}*/
//---------------------------------------------------------------------------
