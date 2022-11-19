//---------------------------------------------------------------------------
#include <conio.h>
#include "caractere.h"
#include <stdlib.h>

int main()
{
Caractere c1;
Caractere c2;
system("cls");
c1.initialise('a');
c1.afficheCar();
c2=c1;
c2.afficheCar();
return 0;
}
