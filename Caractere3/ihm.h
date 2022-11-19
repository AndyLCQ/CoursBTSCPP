//---------------------------------------------------------------------------

#ifndef IhmH
#define IhmH
#include "Chaine.h"
class Ihm
{
    private:
        char choix;
        Chaine * objChaine;
    public:
        void lancer();
        ~Ihm();
    private:
        void traiteChoix();
        void saisirChoix();
};
//---------------------------------------------------------------------------
#endif
