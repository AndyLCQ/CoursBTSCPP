#ifndef IHM_H
#define IHM_H
#include "calcul.h"
class Ihm
{
    private:
        char choix;
        Calcul calcul;
    public:
        void lancer();
    private:
        void traiteChoix();
        void menu();
};
#endif // IHM_H
