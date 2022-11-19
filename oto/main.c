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

        /*Saisie du nombre � traiter*/
        printf("Calcul d'une racine carr�e :\n Enter un reel positif :\n");
        scanf("%f", &nombreTraiter);

        /*Calcul de la racine racine carr�e*/
        ui=nombreTraiter/DIVISEUR;
        do
        {
            uiPlus1=(ui+nombreTraiter/ui)/DIVISEUR;
            precision=fabs(uiPlus1-ui)/ui;
            ui=uiPlus1;
        }
        while(precision>EPSILON);

        /*Affichage du r�sultat*/
        printf("La racine carr�e de %f est %.2f", nombreTraiter, ui);

        return 0;
}
