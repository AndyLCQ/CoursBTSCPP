#include <stdio.h>
#include <stdlib.h>

int main()
{
        int DIVISEUR=2;
        int EPSILON=0.0001;
        float ui;
        float uiPlus1;
        float nombreTraiter;
        float precision;

        /*Saisie du nombre à traiter*/
        printf("Calcul d'une racine carrée :\n Enter un reel positif :\n");
        scanf("%f", &nombreTraiter);

        /*Calcul de la racine racine carrée*/
        ui=nombreTraiter/DIVISEUR;
        do
        {
            uiPlus1=(ui+nombreTraiter/ui)/DIVISEUR;
            precision=fabs(uiPlus1-ui)/ui;
            ui=uiPlus1;
        }
        while(precision>EPSILON);

        /*Affichage du résultat*/
        printf("La racine carrée de %f est %.2f", nombreTraiter, ui);

        return 0;
}
