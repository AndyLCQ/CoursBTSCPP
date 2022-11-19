#ifndef SECTION_H
#define SECTION_H
#include "eleve.h"
#include <vector>
class Section
{
private:
    Eleve unEleve;  // lors de l'instanciation d'un objet section, un objet eleve est créé
    vector<Eleve>  TabEleve;   //pointeur utilisable comme nom de tableau d'objets eleve
    int nbreEleves; //nombre eleve de la section
    float moy; //moyenne de la section
    fstream flux;       //flux de type ftsream
public:
    Section();
    void SaisieSection();
    void traitement();
    void AfficheSection();
    void enregistreSection();
    void litSection();
};

#endif // SECTION_H
