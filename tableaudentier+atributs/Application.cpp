#include "Application.h"

const int MAXI=10;

class Applicationn
{
    private:
        int tab;
        int min;
        int max;
        float moy;

    public:
        void lancer();
    private:
        void saisietableau(int tab[],int taille);
        int maximum(int tab[],int taille);
        int minimum(int tab[],int taille);
        float moyenne(int tab[],int taille);
        void Affiche(int min,int max, float moy);

};
