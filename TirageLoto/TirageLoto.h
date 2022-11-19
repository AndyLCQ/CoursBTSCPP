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
        int * resultatTrier; // contient les 6 num�ros du tirage (tableau tri�)
        int * resultatNonTrier; // contient les 6 num�ros du tirage (tableau non tri�)
        int * tabNumero; // tableau de 50 cases l'indice du tableau repr�sente un des nombres
                        // parmi les 49 (case 0 non utilis�e). Le contenu d'une case sera 0 si
                        // le nombre (donc l'indice) n'a pas �t� encore tir� et 1 s'il a d�j� �t�
                        // tir�
        int nbNumero; // nombre de nombres a tirer
        const int TOTALNUMERO; // nombre de nombres possibles (49)
    public:
        TirageLoto(int nombreNumero); // constructeur, re�oit le nombre de num�ros � tirer
        ~TirageLoto();
        void tirageNbr(); // tirage des num�ro
        int litNumeroTirer(selection select,int i); // indique le num�ro dont l'indice est sp�cifi� par
                                                    // i, select indique si on utilise le tableau tri� ou non
        int getNbNumero();
    private:
        void initTabNumero(); // remet � 0 le tableau tabNumero
        void trierTirage(); // tri du tirage
};

#endif // TIRAGELOTO_H
