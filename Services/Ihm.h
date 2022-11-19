#ifndef IHM_H
#define IHM_H
#include "tempo.h"


class Ihm
{
    private:
        char choix;
        Tempo * objTempo;
    public:
        void lancer();
        ~Ihm();
    private:
        void traiteChoix();
        void saisirChoix();
};

#endif // IHM_H
