#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
       int premier_des;
       int deuxieme_des;
       int joueur1=0;
       int joueur2=0;
       srand(time(NULL));

do
{
        printf("Joueur 1\n");
        do
        {
            premier_des= rand() % 6 + 1;
            deuxieme_des= rand() % 6 + 1;
            joueur1=joueur1+premier_des+deuxieme_des;
            printf("de 1 = %d\n", premier_des);
            printf("de 2 = %d\n", deuxieme_des);
            printf("score = %d\n", joueur1);
        }
        while(premier_des==deuxieme_des);

        printf("Joueur 2\n");
        do
        {
            premier_des= rand() % 6 + 1;
            deuxieme_des= rand() % 6 + 1;
            joueur2=joueur2+deuxieme_des+premier_des;
            printf("de 1 = %d\n", premier_des);
            printf("de 2 = %d\n", deuxieme_des);
            printf("score = %d\n",joueur2 );
        }
        while(premier_des==deuxieme_des);
}
while(joueur1<50 && joueur2<50);

    if(joueur1>=50)
    {
        printf("Le joueur 1 a gagne\n");
    }
    if(joueur2>=50)
    {
        printf("Le joueur 2 a gagne\n");
    }

    return 0;
}
