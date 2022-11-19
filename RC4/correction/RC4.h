//---------------------------------------------------------------------------

#ifndef RC4H
#define RC4H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// génération de valeurs successives à chaque appel
class Sequence
{
    private:
        unsigned char valeur;
    public:
        // constructeur : initialisation de valeur
        Sequence(unsigned char valValeur);
        // retourne valeur puis l'incrémente
        unsigned char operator() ();
};

class Random;

// cryptage ou décryptage RC4
class RC4
{
    private:
        vector <unsigned char> tableauEtat;     // tableauEtat
        vector <unsigned char> maCle;           // clé de cryptage
        unsigned int tailleCle;                 // longueur de la clé
        const unsigned int tailleTableauEtat;   // longueur du tableauEtat
        unsigned int i;                         // indice du tableauEtat
        unsigned int j;                         // indice du tableauEtat
    public:
        // constructeur : génération automatique de la clé, ainsi que de
        // sa longueur si le paramètre est 0 ou omis(entre 40 et 255)
        RC4(unsigned int valTailleCle=0);
        // constructeur : clé et longueur spécifiées
        RC4(unsigned char *valMaCle,int valTaille);
        // constructeur : clé spécifiée
        RC4(vector <unsigned char> valMaCle);
        // initialisation des différents attributs avant cryptage ou décryptage
        void initCodageDecodage();
        // génération d'un octet pour le cryptage de la donnée		
        unsigned char chiffrage();
        // lecture de la clé
        vector <unsigned char> litCle();
        // lecture de la longueur de la clé
        unsigned int litTailleCle();
    private:
        // génération de la clée
        void genereCle();
        // mélange du tableau d'état
        void melangeTableauEtat();
        // inversion de deux octets
        void swap(unsigned char* val1,unsigned char* val2);
};
//---------------------------------------------------------------------------
#endif
