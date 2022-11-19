#include "MotAleatoire.h"

MotAleatoire::MotAleatoire(Sqlite &laBase):maBase(laBase)
{

}

MotAleatoire::~MotAleatoire()
{
    //dtor
}
int MotAleatoire::nombreMots()
{
    maBase.requete("SELECT mot FROM dictionnaire ORDER BY idDictionnaire;");
    maBase.exec();
    return maBase.getNombreEnregistrements();

}
bool MotAleatoire::motPresent(string motRecherche)
{

    return false;
}
bool MotAleatoire::ajouterMot(string nouveauMot)
{
    maBase.requete("INSERT INTO dictionnaire(idDictionnaire, mot) VALUES(null, nouveauMot);");
    maBase.exec();
    return false;
}
bool MotAleatoire::supprimerMot(string motASupprimer)
{

    return false;
}
