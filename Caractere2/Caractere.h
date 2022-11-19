#ifndef CARACTERE_H
#define CARACTERE_H


#include "minmaj.h"
class Caractere
{
private:
    char car;
public:
    Caractere(char valCar);
    char minuscule();
    char majuscule();
    void afficheCar(TypeCara minMaj);
    void afficheCodeAscii(TypeCara minMaj);
    char carInferieur();
    char carSuperieur();
};

#endif // CARACTERE_H
