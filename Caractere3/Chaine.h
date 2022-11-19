#ifndef ChaineH
#define ChaineH
//---------------------------------------------------------------------------
class Chaine
{
    private:
            int nbMaxCar; // nombre maxi de caractères
            int nbCar; // nombre courant de caractères
            char * tab; // chaîne (en dynamique)
    public:
            Chaine(int valNb); // constructeur
            ~Chaine(); // destructeur
            int taille(); // taille de la chaîne
            void vide(); // vide la chaîne
            void affiche(); // affiche la chaîne
            bool ajouteCaractere(char cara); // ajoute un caractère en fin
            char retireCaractere(); // tire le caractère de fin
            void minuscule(); // mise en minuscule de la chaîne
            void majuscule(); // mise en majuscule de la chaîne
    private:
            void init();
};
//---------------------------------------------------------------------------
#endif
