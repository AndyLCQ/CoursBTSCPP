#include <ctype.h>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
#pragma hdrstop
#include "caractere.h"
//---------------------------------------------------------------------------
void Caractere::initialise(char valCar)
{
car=toupper(valCar);
}
//---------------------------------------------------------------------------
void Caractere::afficheCar()
{
cout<<"Le caractere est : "<<car<<endl;
}
