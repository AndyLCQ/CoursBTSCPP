#ifndef ISBN_H
#define ISBN_H



class Isbn
{
    private:
        char * tabIsbn; // chaîne contenant l’isbn
        const int TAILLE; // taille de la chaîne isbn 13+1
        char pays[3]; // code du pays
        char editeur[9]; // code de l’éditeur
        char titre [9]; // code du titre
        char controle[3]; // code du contrôle
    public:
        Isbn(char *Tab); // initialisation de taille, chaîne, et décomposition des codes
        ~Isbn(); // libération de la mémoire
        bool verifChec(); // vérification du chiffre de contrôle
        void afficheChamp(); // affiche les différents champs de l’isbn
    private:
        void decompose(); // décompose l’isbn
        int recherche(char *source,char *destination,int debut,char caractereFin); // recherche d’une sous
                                                                                   //chaîne dans une chaîne
};


#endif // ISBN_H
