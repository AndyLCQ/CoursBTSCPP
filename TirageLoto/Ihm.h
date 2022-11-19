//---------------------------------------------------------------------------

#ifndef IhmH
#define IhmH
#include"TirageLoto.h"

class Ihm
{
    private:
        char choix;
        TirageLoto * objTirageLoto;
    public:
        void lancer();
        ~Ihm();
    private:
        void traiteChoix();
        void saisirChoix();
};
//---------------------------------------------------------------------------
#endif
