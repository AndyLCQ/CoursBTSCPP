#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int somme;


    printf("Entrer A :");
    scanf("%d", &a);
    printf("Entrer B :");
    scanf("%d", &b);

    do
    {
        somme=abs(a-b);
        if (a>b)
        {
            a=somme;
        }
    }

}
