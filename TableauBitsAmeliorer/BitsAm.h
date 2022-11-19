#ifndef BITSAM_H
#define BITSAM_H
#include <ostream>
using namespace std;

class Bits
{
    private:
        int nBits;      //nombre de bits
        int nOctets;   //nombre d’octets et indice du tableau
        char * adb;     //pointe tableau de bits
    public:
         Bits(int nOctets=1);
         Bits(const Bits &);
        ~Bits();
        int getNBits();
        int getNOctets();
        Bits operator ++ ();
        Bits operator ++ (int n);
        Bits operator -- ();
        Bits operator -- (int n);
        Bits operator =(const Bits &bi);
        void operator += (int numeroBit);
        char & operator [] (int numeroBit);
        void operator -= (int numeroBit);
        Bits operator ~ ();
        friend ostream & operator << (ostream & affiche,const Bits & t);
};

#endif // BITSAM_H
