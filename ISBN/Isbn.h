#ifndef ISBN_H
#define ISBN_H



class Isbn
{
    private:
        char * tabIsbn; // cha�ne contenant l�isbn
        const int TAILLE; // taille de la cha�ne isbn 13+1
        char pays[3]; // code du pays
        char editeur[9]; // code de l��diteur
        char titre [9]; // code du titre
        char controle[3]; // code du contr�le
    public:
        Isbn(char *Tab); // initialisation de taille, cha�ne, et d�composition des codes
        ~Isbn(); // lib�ration de la m�moire
        bool verifChec(); // v�rification du chiffre de contr�le
        void afficheChamp(); // affiche les diff�rents champs de l�isbn
    private:
        void decompose(); // d�compose l�isbn
        int recherche(char *source,char *destination,int debut,char caractereFin); // recherche d�une sous
                                                                                   //cha�ne dans une cha�ne
};


#endif // ISBN_H
