//---------------------------------------------------------------------------
#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include "chaine.h"
//---------------------------------------------------------------------------
class IHM
{
    private:
        char choix;
        Chaine * c1;
        const char FIN;
    public:
        IHM();
        ~IHM();
        void lancer();
    private:
        void traiteChoix();
        void saisirChoix();
        void ajouterCaratere();
		void retirerCaractere();
        void afficherChaine();
		void viderChaine();
        void tailleChaine();
		void  mettreEnMinuscule();
        void mettreEnMajuscule();
};
//---------------------------------------------------------------------------
#endif
