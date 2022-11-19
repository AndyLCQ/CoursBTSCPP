#ifndef BITS_H
#define BITS_H
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
        ~Bits();
        int getNBits();
        int getNOctets();
        Bits operator ++ ();
        Bits operator ++ (int n);
        Bits operator -- ();
        Bits operator -- (int n);
        void operator ~ ();
        friend ostream & operator << (ostream & affiche,const Bits & t);
};

#endif // BITS_H
