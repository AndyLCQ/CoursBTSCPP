#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
    public:
        void lancer();
    private:
        void saisietableau(int tab[],int taille);
        int maximum(int tab[],int taille);
        int minimum(int tab[],int taille);
        float moyenne(int tab[],int taille);
        void Affiche(int min,int max, float moy);
};

#endif // APPLICATION_H
