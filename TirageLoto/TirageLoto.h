#ifndef TIRAGELOTO_H
#define TIRAGELOTO_H

enum selection
{
NON_TRIE,
TRIE
};

class TirageLoto
{
    private:
        int * resultatTrier; // contient les 6 numéros du tirage (tableau trié)
        int * resultatNonTrier; // contient les 6 numéros du tirage (tableau non trié)
        int * tabNumero; // tableau de 50 cases l'indice du tableau représente un des nombres
                        // parmi les 49 (case 0 non utilisée). Le contenu d'une case sera 0 si
                        // le nombre (donc l'indice) n'a pas été encore tiré et 1 s'il a déjà été
                        // tiré
        int nbNumero; // nombre de nombres a tirer
        const int TOTALNUMERO; // nombre de nombres possibles (49)
    public:
        TirageLoto(int nombreNumero); // constructeur, reçoit le nombre de numéros à tirer
        ~TirageLoto();
        void tirageNbr(); // tirage des numéro
        int litNumeroTirer(selection select,int i); // indique le numéro dont l'indice est spécifié par
                                                    // i, select indique si on utilise le tableau trié ou non
        int getNbNumero();
    private:
        void initTabNumero(); // remet à 0 le tableau tabNumero
        void trierTirage(); // tri du tirage
};

#endif // TIRAGELOTO_H
