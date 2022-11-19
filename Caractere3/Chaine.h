#ifndef ChaineH
#define ChaineH
//---------------------------------------------------------------------------
class Chaine
{
    private:
            int nbMaxCar; // nombre maxi de caract�res
            int nbCar; // nombre courant de caract�res
            char * tab; // cha�ne (en dynamique)
    public:
            Chaine(int valNb); // constructeur
            ~Chaine(); // destructeur
            int taille(); // taille de la cha�ne
            void vide(); // vide la cha�ne
            void affiche(); // affiche la cha�ne
            bool ajouteCaractere(char cara); // ajoute un caract�re en fin
            char retireCaractere(); // tire le caract�re de fin
            void minuscule(); // mise en minuscule de la cha�ne
            void majuscule(); // mise en majuscule de la cha�ne
    private:
            void init();
};
//---------------------------------------------------------------------------
#endif
