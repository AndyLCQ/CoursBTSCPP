#include "calcul.h"

Calcul::Calcul()
{
}
//---------------------------------------------------------------------------------------------------//
/*Prend en paramètre un float et return l'inverse du nombre entrer en paramètre(float)*/
float Calcul::inverse(float nombre)
{
    return 1/nombre;
}
//---------------------------------------------------------------------------------------------------//
/*Prend les paramètres et retourne leur rapport*/
float Calcul::quotient(int m, int n)
{
    return m/n;
}
//---------------------------------------------------------------------------------------------------//
/*Prend les paramètres et retourne le reste du rapport des deux*/
int Calcul::reste(int m, int n)
{
    return m%n;
}
//---------------------------------------------------------------------------------------------------//
/*Prend en paramètres 4 floats et retourne le plus petit*/
float Calcul::min(float a, float b, float c, float d)
{
    float min1, min2;
    float resultat;
    min1=(a<b)?a:b;
    min2=(c<d)?c:d;
    return resultat=(min1<min2)?min1:min2;
}
//---------------------------------------------------------------------------------------------------//
/*Prend en paramètres 4 floats et retourne le plus grand*/
float Calcul::max(float a, float b, float c, float d)
{
    float max1, max2;
    float resultat;
    max1=(a>b)?a:b;
    max2=(c>d)?c:d;
    return resultat=(max1>max2)?max1:max2;
}
