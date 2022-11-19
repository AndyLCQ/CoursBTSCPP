#include "BitsAm.h"

/*Constructeur*/
Bits::Bits(int nOctets)
{
    this->nOctets=nOctets;
    this->nBits= nOctets * 8;
    adb = new char[nOctets];
    --(*this);
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
    for(int i=0; i<nOctets; i++)
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
    for(int i=0; i<nOctets ; i++)
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
Bits Bits::operator ~ ()
{

    for(int i=0; i<nOctets; i++)
    {
        adb[i]=~adb[i];
    }
    return *this;
}
/**********************************************************************************************************************/
/*Constructeur par recopie*/
Bits::Bits(const Bits & bi)
{
    nOctets=bi.nOctets;
    nBits=bi.nBits;
    adb=new char[nOctets];
    for(int i=0; i<nOctets;i++)
    {
        adb[i]=bi.adb[i];
    }
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération = */
Bits Bits::operator=(const Bits &bi)
{
    if(this != &bi)
    {

        delete [] adb;
        nOctets=bi.nOctets;
        nBits=bi.nBits;
        adb = new char [nOctets];
        for(int i=0;i < nOctets; i++)
        {

            adb[i]=bi.adb[i];
        }

    }
    return *this;
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération += */
void Bits::operator += (int numeroBit)
{
    int numOctetDonnee;
    int numBitDonneeTab;
    int numIndiceTab;

    numOctetDonnee=numeroBit/8;
    numBitDonneeTab=numeroBit%8;
    numIndiceTab=(nOctets-numOctetDonnee)-1;
    char masque=1;
    masque=masque << numBitDonneeTab ;
    adb[numIndiceTab] = masque | adb[numIndiceTab];
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération -= */
void Bits::operator -= (int numeroBit)
{
    int numOctetDonnee;
    int numBitDonneeTab;
    int numIndiceTab;

    numOctetDonnee=numeroBit/8;
    numBitDonneeTab=numeroBit%8;
    numIndiceTab=(nOctets-numOctetDonnee)-1;
    char masque=1;
    masque=masque << numBitDonneeTab ;
    masque = ~masque;
    adb[numIndiceTab] = masque & adb[numIndiceTab];
}
/**********************************************************************************************************************/
/*Sur-définition de l'opération [] */
char & Bits::operator [] (int numeroBit)
{
    return adb[numeroBit];
}
