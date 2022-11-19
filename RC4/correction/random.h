//---------------------------------------------------------------------------
#ifndef randomH
#define randomH

/* G�n�ration al�atoire d'un tableau d'entiers dans une fourchette fix�e */
class Random
{
    private:
        int *tabRandom;         // tableau des entiers
        unsigned int nbRandom;  // nombre d'entiers
        unsigned int maxi;      // valeur maxi de la fourchette
        unsigned int mini;      // valeur mini de la fourchette
    public:
        // contructeur
        Random(
            unsigned int valMini,                    // maxi fourchette
            unsigned int valMaxi,                    // mini fourchette
            unsigned int valNbRandom=1);    // nombre de valeurs
        // destructeur
        ~Random();
        // lit la taille du tableau
        unsigned int getNbRandom()const;
        // modifie la taille du tableau
        void setNbRandom(
            unsigned int valNbRandom);      // taille du tableau
        // lit la valeur maxi de la fourchette
        unsigned int getMaxi()const;
        // modifie la valeur maxi de la fourchette
        bool setMaxi(
            unsigned int Val);                       // valeur maxi
        // lit la valeur mini de la fourchette
        unsigned int getMini()const;
        // modifie la valeur mini de la fourchette
        bool setMini(
            unsigned int Val);                       // valeur mini
        // remplissage de tableau
        void remplirTab();
        // acc�s � une case du tableau
        int operator[](
            unsigned int indice)const;      // indice de la case
        // modifie la case sp�cifi�e
        unsigned int modifie(
            unsigned int indice=0);         // indice de la case
        // retourne une valeur al�atoire comprise dan la fourchette sp�cifi�e
        static unsigned int valeurUnique(
            unsigned int valMini,                    // mini de la fourchette
            unsigned int valMaxi);                   // maxi de la fourchette
    private:
        // retour une valeur al�atoire comprise dans la fourchette sp�cifi�e
        // dans les attributs
        int calculValeur()const;
        void inversionMaxiMini();
};
//---------------------------------------------------------------------------
#endif
