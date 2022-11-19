#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "tableau.h"
using namespace std;


int main ()

{
    const int TAILLE=3;
    int tab[TAILLE];
    int max, min;
    float moy;


    saisietableau(tab,TAILLE);

    max=maximum(tab, TAILLE);
    min=minimum(tab, TAILLE);
    moy=moyenne(tab, TAILLE);
    Affiche(min, max, moy);

    return 0;
}

