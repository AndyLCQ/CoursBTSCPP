#include "Bits.h"

/*Constructeur*/
Bits::Bits(int nOctets)
{
    this->nOctets=nOctets;
    this->nBits= nOctets * 8;
    adb = new char[nOctets];
    for (int i=0; i<nBits; i++)
    {
        adb[i]=0b00000000;
    }
}
/**********************************************************************************************************************/
/*Destructeur*/
Bits::~Bits()
{
    delete [] adb;
}
/**********************************************************************************************************************/
/*Accesseur */
int Bits::getNBits()
{
    return nBits;
}
/**********************************************************************************************************************/
/*Accesseur */
int Bits::getNOctets()
{
    return nOctets;
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération << */
ostream & operator << (ostream & affiche,const Bits & t)
{
    int i,j;
    affiche << "<* ";
    unsigned char val, reste;
    for(i= 0 ; i <t. nOctets ; i++)
    {
        reste = t.adb[i];
        for(j = 128; j > 0; j = j >> 1)
        {
            val = reste / j;
            affiche << (int) val;
            reste = reste % j;
        }
        affiche << " ";
    }
    affiche << " *>";
    return affiche;
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération ++ */
Bits Bits::operator ++ ()
{
    for(int i=0; i<nBits; i++)
    {
        adb[i]=0b11111111;
    }

    return *this;
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération ++(postfixé) */
Bits Bits::operator ++ (int n)
{
    Bits tempo = *this;
    ++(*this);
    return tempo;
}

/**********************************************************************************************************************/
/*Sur-définition de l'opération -- */
Bits Bits::operator -- ()
{
    for(int i=0; i<nBits; i++)
    {
        adb[i]=0b00000000;
    }
    return *this;
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération --(postfixé) */
Bits Bits::operator -- (int n)
{
    Bits tempo = *this;
    --(*this);
    return tempo;
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération ~ */
void Bits::operator ~ ()
{

    for(int i=0; i<nBits; i++)
    {
        adb[i]=~adb[i];
    }
}
