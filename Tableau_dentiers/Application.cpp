#include "Application.h"
#include <iostream>

using namespace std;


        void Application::lancer()
        {
            const int TAILLE=3;
            int tab[TAILLE];
            int max, min;
            float moy;


            saisietableau(tab,TAILLE);

            max=maximum(tab, TAILLE);
            min=minimum(tab, TAILLE);
            moy=moyenne(tab, TAILLE);
            Affiche(min, max, moy);
        }

        /**Méthode de saisie**/
        void Application::saisietableau(int tab[],int taille)
        {
            int i;
            for(i=0;i<taille;i++)
            {
                cout<<"Entrez la valeur d'une case : \n";
                cin>>tab[i];
            }
        }

        /**Méthode Maximum**/
        int Application::maximum(int tab[],int taille)
        {
            int i;
            int max=tab[0];
            for(i=1;i<taille;i++)
            {
                if(tab[i]>max)
                max=tab[i];
            }
            return max;
        }

        /**Méthode Minimum**/
        int Application::minimum(int tab[],int taille)
        {
            int i;
            int min=tab[0];
            for(i=1;i<taille;i++)
            {
                if(tab[i]<min)
                min=tab[i];
            }
            return min;
        }

        /**Méthode Moyenne**/
        float Application::moyenne(int tab[],int taille)
        {
            int i;
            int somme=0;
            float moy;

            for(i=0;i<taille;i++)
            {
                somme=somme+tab[i];
            }
            moy=(float)somme/taille;
            return moy;
        }

        void Application::Affiche(int min,int max, float moy)
        {
            cout << "maxi : " << max << "\n ";
            cout << "mini : " << min <<"\n";
            cout << "moyenne : " << moy <<"\n";
        }
