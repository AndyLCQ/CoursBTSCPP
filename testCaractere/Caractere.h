#ifndef CaractereH // pour éviter les inclusions multiples
#define CaractereH
//---------------------------------------------------------------------------
class Caractere
{
private: // donnée encapsulée
    char car;


public:
    void initialise(char valCar); // permet d’initialiser le caractère
    void afficheCar(); // permet d’afficher le caractère

};

//---------------------------------------------------------------------------
#endif
