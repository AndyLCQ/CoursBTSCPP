#ifndef CaractereH // pour �viter les inclusions multiples
#define CaractereH
//---------------------------------------------------------------------------
class Caractere
{
private: // donn�e encapsul�e
    char car;


public:
    void initialise(char valCar); // permet d�initialiser le caract�re
    void afficheCar(); // permet d�afficher le caract�re

};

//---------------------------------------------------------------------------
#endif
