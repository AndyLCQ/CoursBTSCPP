#include <stdio.h>
#include <stdlib.h>


int main()

{
    int age;
    int permis;
    int accident;
    int contrat;
    int points=0;

/*saisie Permis et age*/

    printf("Entrez l'age de la personne :\n");
    scanf("%d", &age);
    printf("Entrez le nombre d'annee de permis :\n");
    scanf("%d", &permis);


/*Traitement de l'age*/
    if(age>=25)
    {
        points=points+1;
    }

/*Traitement du nombre d'annee de permis*/
    if(permis>=2)
    {
        points=points+1;
    }

/*Saisie du nombre d'accident */
    printf("Entrer le nombre d'accident :\n");
    scanf("%d", &accident);

/*Traitement du nombre d'accident*/
    points=points-accident;

    if(points<0)
    {
        printf("REFUSE !!!!! \n");
    }
    else
    {

/*Saisie fidelite*/
    printf("Entrer le nombre d'annee de fidelite:\n");
    scanf("%d", &contrat);

/*Traitement fidelite*/
    if(contrat>=1)
    {
        points=points+1;
    }
    }





/*affichage*/

    printf("Nombre de points: %d \n", points);

    if(points==0)
    {
        printf("Contrat rouge\n");
    }

    if(points==1)
    {
        printf("Contrat orange\n");

    }
    if(points>1)
    {
        printf("Contract vert\n");
    }



    return 0;
}


