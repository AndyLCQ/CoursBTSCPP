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
#include <iostream>
#include "RC4.h"

/******************************************************************************
* ACTION			:FichierCrypte
* DESCRIPTION		:Constructeur
*
* ENTREES   		:valSource:string(nom du fichier)
*                    valCryptage:booléen(true:cryptage,false:décryptage)
*                    valExtension:string(extension du fichier crypté,
*                    par défaut cry)
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
* DESCRIPTION		:génère le nom du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypté)
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:nomSource,nomDestination,cryptage
* LOCALES			:indice:entier(position du point dans la chaîne)
******************************************************************************/
void FichierCrypte::nomFichierDestination(string valExtension)
{
    int indice=nomSource.find(".");
    nomDestination.assign(nomSource,0,indice);
    // si l'extension n'est pas présente ou est invalide on génère l'extension
    if(!controleExtensionFichier(valExtension))
        if(cryptage)
            // cry en cas de cryptage
            nomDestination.insert(nomDestination.size(),".cry");
            // txt en cas de décryptage
        else
            nomDestination.insert(nomDestination.size(),".txt");
    else
        nomDestination.insert(nomDestination.size(),"."+valExtension);
}

/******************************************************************************
* ACTION			:controleExtensionFichier
* DESCRIPTION		:controle la validité de l'extension du fichier destination
*
* ENTREES   		:valExtension:string(extension du fichier crypté)
* SORTIES       	:
* E/S				:
* RESULTAT			:booléen(indique si l'extension est valide)
*
* ATTRIBUTS			:
* LOCALES			:resu:booléen(résultat du test)
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
* DESCRIPTION		:cryptage du fichier, avec insertion après le 3ème octet de
*                    la taille de la clé, suivie de la clé. Après la clé on
*                    trouve le reste du fichier crypté
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:fichierSource,fichierDestination
* LOCALES			:monRC4:RC4(classe de cryptage),
*                    donnée:octet(donnée courante),compteur:entier,
*                    tailleCle:entier,cle:vector(clé de cryptage)
*                    sauve:booléen(indique si la clé, ainsi que la taille,
*                    ont été sauvé dans le fichier destination)
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
        if(compteur==3)    // si 4 ème octets on sauve la taille de la clé et la clé
        {
            //sauvegarde de la taille
            fichierDestination.write((char *)&tailleCle,sizeof(tailleCle));

            //sauvegarde de la clé
            recupCle=new char [tailleCle];

            copy(cle.begin(),cle.end(),recupCle);
            fichierDestination.write(recupCle,tailleCle);
            delete [] recupCle;
        }
        //compteur de données
        compteur++;

        //cryptage de la donnée courante
        donnee = donnee ^ monRC4->chiffrage();

        //écriture dans le fichier de destination
        fichierDestination.write((char *)&donnee,sizeof(donnee));
    }

    delete monRC4;
}

/******************************************************************************
* ACTION			:decrypteFichier
* DESCRIPTION		:décryptage du fihcier
*
* ENTREES   		:
* SORTIES       	:
* E/S				:
* RESULTAT			:
*
* ATTRIBUTS			:fichierSource,fichierDestination
* LOCALES			:donnee:octet(donnée courante),
*                    tailleCle:entier,i:entier(compteur de boucle)
******************************************************************************/
void FichierCrypte::decrypteFichier()
{
    unsigned char donnee;
    unsigned char * recupCle;

    // positionnement pour récupérer la taille de la clé
    fichierSource.seekg(3,ios::beg);
    fichierDestination.seekp(0,ios::beg);

    unsigned int tailleCle;

    //lecture de la taille de la clé
    fichierSource.read((char*)&tailleCle,sizeof(tailleCle));

    //initialisation de la longueur de la clé
    vector <unsigned char> cle(tailleCle);

    //récupération de la clé
    recupCle=new unsigned char [tailleCle];

    fichierSource.read((char *)recupCle,tailleCle);
    copy(recupCle,recupCle+tailleCle,cle.begin());
    delete [] recupCle;

    monRC4=new RC4(cle);

    //décrypyage et sauvegarde des 3 premiers octets du fichier
    fichierSource.seekg(0,ios::beg);
    for(unsigned int i=0;i<3;i++)
    {
        fichierSource.read((char *)&donnee,sizeof(donnee));
        donnee=donnee ^ monRC4->chiffrage();
        fichierDestination.write((char *)&donnee,sizeof(donnee));
    }

    //décryptage et sauvegarde du reste du fichier
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
