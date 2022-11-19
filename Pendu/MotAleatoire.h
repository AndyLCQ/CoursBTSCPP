#ifndef MOTALEATOIRE_H
#define MOTALEATOIRE_H
#include <sqlite.h>

class MotAleatoire
{
    public:
        MotAleatoire(Sqlite &laBase);
        int nombreMots();
        bool motPresent(string motRecherche);
        bool ajouterMot(string nouveauMot);
        bool supprimerMot(string motASupprimer);
        virtual ~MotAleatoire();
    protected:
    private:
        Sqlite &maBase;
};

#endif // MOTALEATOIRE_H
