#ifndef RANDOM_H
#define RANDOM_H
#include <stdlib.h>

class Random
{
    public:
        Random(int paraMini,int paraMaxi,unsigned int paraNbRandom=1,bool paraUnique=false); //Ce constructeur permet d’initialiser les attributs (taille par défaut du tableau 1 et
                                                                                            //unique à faux).
        ~Random(); //Libération de la mémoire.
        void initTab();  //Rempli le tableau avec des valeurs aléatoires (unique ou pas selon le cas)
        unsigned int getNbRandom();  //Indique la taille du tableau.
        void setNbRandom(unsigned int nbVal);  //Modifie la taille du tableau et le rempli.
        unsigned int getMaxi(); //Indique la valeur aléatoire maxi possible.
        unsigned int getMini();   //Indique la valeur aléatoire mini possible.
        void setMaxi(int val);  //Modifie la valeur aléatoire maxi possible.
        void setMini(int val);  //Modifie la valeur aléatoire mini possible.
        int getDonnee(unsigned int indice);   //Indique la valeur aléatoire de la case spécifiée.
                                                //Si l’indice n’est pas valide, on retournera unevaleur égale à mini-1
        int operator[](unsigned int indice);  //Indique la valeur aléatoire de la case spécifiée.
                                            //Si l’indice n’est pas valide, on retournera une valeur égale à mini-1

        int modifie(unsigned int indice=0);  //Modifie la donnée aléatoire de la case spécifiée (si l’indice est valide) et la
                                                //retourne (sinon retourne -1).
    private:
        int * tabRandom; //tableau de sauvegarde des nombres aléatoire.
        bool unique;  //indique si les données sont uniques
        unsigned int nbRandom;  //nombre de données aléatoires
        unsigned int maxi;  //valeur maxi des nombres aléatoires.
        unsigned int mini;  //valeur mini des nombres aléatoires.
        int calculValeur(); //retourne une valeur aléatoire comprise dans la fourchette.
        bool rechercheValeur(int donnee); //indique si la valeur spécifiée est déjà dans le tableau
};

#endif // RANDOM_H
