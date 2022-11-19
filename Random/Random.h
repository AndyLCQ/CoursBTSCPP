#ifndef RANDOM_H
#define RANDOM_H
#include <stdlib.h>

class Random
{
    public:
        Random(int paraMini,int paraMaxi,unsigned int paraNbRandom=1,bool paraUnique=false); //Ce constructeur permet d�initialiser les attributs (taille par d�faut du tableau 1 et
                                                                                            //unique � faux).
        ~Random(); //Lib�ration de la m�moire.
        void initTab();  //Rempli le tableau avec des valeurs al�atoires (unique ou pas selon le cas)
        unsigned int getNbRandom();  //Indique la taille du tableau.
        void setNbRandom(unsigned int nbVal);  //Modifie la taille du tableau et le rempli.
        unsigned int getMaxi(); //Indique la valeur al�atoire maxi possible.
        unsigned int getMini();   //Indique la valeur al�atoire mini possible.
        void setMaxi(int val);  //Modifie la valeur al�atoire maxi possible.
        void setMini(int val);  //Modifie la valeur al�atoire mini possible.
        int getDonnee(unsigned int indice);   //Indique la valeur al�atoire de la case sp�cifi�e.
                                                //Si l�indice n�est pas valide, on retournera unevaleur �gale � mini-1
        int operator[](unsigned int indice);  //Indique la valeur al�atoire de la case sp�cifi�e.
                                            //Si l�indice n�est pas valide, on retournera une valeur �gale � mini-1

        int modifie(unsigned int indice=0);  //Modifie la donn�e al�atoire de la case sp�cifi�e (si l�indice est valide) et la
                                                //retourne (sinon retourne -1).
    private:
        int * tabRandom; //tableau de sauvegarde des nombres al�atoire.
        bool unique;  //indique si les donn�es sont uniques
        unsigned int nbRandom;  //nombre de donn�es al�atoires
        unsigned int maxi;  //valeur maxi des nombres al�atoires.
        unsigned int mini;  //valeur mini des nombres al�atoires.
        int calculValeur(); //retourne une valeur al�atoire comprise dans la fourchette.
        bool rechercheValeur(int donnee); //indique si la valeur sp�cifi�e est d�j� dans le tableau
};

#endif // RANDOM_H
