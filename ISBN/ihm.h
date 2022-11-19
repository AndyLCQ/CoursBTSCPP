//---------------------------------------------------------------------------

#ifndef IhmH
#define IhmH
#include "Isbn.h"
class Ihm
{
    private:
        char choix;
        Isbn * objIsbn;
    public:
        void lancer();
        ~Ihm();
    private:
        void traiteChoix();
        void saisirChoix();
};
//---------------------------------------------------------------------------
#endif
