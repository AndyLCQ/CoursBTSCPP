#include <iostream>
#include <iomanip>


using namespace std;

int main()
{

    const int TAILLE=3;                 /*Taille du tableau */
    int tableau[TAILLE];
    int compteur;
    int maximum;
    int minimum;
    unsigned int choix;
    int somme=0;
    float moyenne;



/*Saisie du contenue du tableau*/
    for(compteur=0;compteur<TAILLE;compteur++)
    {
        cout << "Entrer un entier\n";
        cin >> tableau[compteur];
    }

/*Affichage du tableau et du contenue*/
    cout << "Tableau :" << endl;
    for(compteur=0;compteur<TAILLE;compteur++)
    {
        cout << tableau[compteur] << endl;
    }

/*Menu des choix */
    cout << "Taper '1' pour savoir le maximum \nTaper '2' pour connaitre le minimum \nTaper '3' pour connaitre la moyenne \nTaper '0' pour finir le programme" << endl;
    do
    {

    do
    {
        cout << "Saisir le choix :" << endl;
        cin >> choix;
    }
    while(choix>3);


/*Traitement du maximum*/
    if(choix==1)
    {
        maximum=tableau[0];
        for(compteur=1;compteur<TAILLE;compteur++)
         {
             if(maximum<tableau[compteur])
             {
                 maximum=tableau[compteur];
             }
         }
         cout << "Le maximum est :" << maximum <<endl;
    }
    if(choix==2)
    {
        minimum=tableau[0];
        for(compteur=1;compteur<TAILLE;compteur++)
         {
             if(minimum>tableau[compteur])
             {
                 minimum=tableau[compteur];
             }
         }
         cout << "Le minimum est : " << minimum << endl;
    }
    if(choix==3)
    {
          for(compteur=0;compteur<TAILLE;compteur++)
         {
             somme=tableau[compteur]+somme;
         }
        moyenne= (float)somme/TAILLE;
        cout << setprecision(3) << fixed <<"La moyenne des entiers est : " << moyenne <<endl;
    }
    if(choix==0)
    {
          cout << "Fin du programme";
    }

    }while(choix!=0);





    return 0;
}
