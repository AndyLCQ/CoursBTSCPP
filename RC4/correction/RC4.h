//---------------------------------------------------------------------------

#ifndef RC4H
#define RC4H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// g�n�ration de valeurs successives � chaque appel
class Sequence
{
    private:
        unsigned char valeur;
    public:
        // constructeur : initialisation de valeur
        Sequence(unsigned char valValeur);
        // retourne valeur puis l'incr�mente
        unsigned char operator() ();
};

class Random;

// cryptage ou d�cryptage RC4
class RC4
{
    private:
        vector <unsigned char> tableauEtat;     // tableauEtat
        vector <unsigned char> maCle;           // cl� de cryptage
        unsigned int tailleCle;                 // longueur de la cl�
        const unsigned int tailleTableauEtat;   // longueur du tableauEtat
        unsigned int i;                         // indice du tableauEtat
        unsigned int j;                         // indice du tableauEtat
    public:
        // constructeur : g�n�ration automatique de la cl�, ainsi que de
        // sa longueur si le param�tre est 0 ou omis(entre 40 et 255)
        RC4(unsigned int valTailleCle=0);
        // constructeur : cl� et longueur sp�cifi�es
        RC4(unsigned char *valMaCle,int valTaille);
        // constructeur : cl� sp�cifi�e
        RC4(vector <unsigned char> valMaCle);
        // initialisation des diff�rents attributs avant cryptage ou d�cryptage
        void initCodageDecodage();
        // g�n�ration d'un octet pour le cryptage de la donn�e		
        unsigned char chiffrage();
        // lecture de la cl�
        vector <unsigned char> litCle();
        // lecture de la longueur de la cl�
        unsigned int litTailleCle();
    private:
        // g�n�ration de la cl�e
        void genereCle();
        // m�lange du tableau d'�tat
        void melangeTableauEtat();
        // inversion de deux octets
        void swap(unsigned char* val1,unsigned char* val2);
};
//---------------------------------------------------------------------------
#endif
