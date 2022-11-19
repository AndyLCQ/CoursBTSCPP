#include "ihm.h"
#include <iostream>

//---------------------------------------------------------------------------------------------------------//
using namespace std;
void Ihm::lancer()
{
    do
    {
        menu();
        traiteChoix();
    }
    while(choix!='f');
}
//---------------------------------------------------------------------------------------------------------//
void Ihm::traiteChoix()
{
    float nombre;
    int m, n;
    float a, b, c, d;
    switch(choix)
    {
    case 'i' :
        cout << "Entrer un nombre" <<endl;
        cin >> nombre;
        cout << calcul.inverse(nombre) << endl; break;
    case 'd':
        cout << "Entrer le numerateur "<< endl;
        cin >> m;
        cout << "Entrer le denonimateur "<< endl;
        cin >> n;
        cout << " Quotient :" << calcul.quotient(m,n);
        cout << " Reste :" << calcul.reste(m, n); break;
    case 'm' :
        cout << "Entrer a" <<endl;
        cin >> a;
        cout << "Entrer b" <<endl;
        cin >> b;
        cout << "Entrer c" <<endl;
        cin >> c;
        cout << "Entrer d" <<endl;
        cin >> d;
        cout << "Maximum :" << calcul.max(a, b, c, d) <<endl;
        cout << "Minimum :" << calcul.min(a, b, c, d) <<endl; break;
    case 'f' :
        cout << "Fin du programme" << endl;break;
    default :
        cout << "Valeur du choix incorrect !" <<  endl;
    }
}
//---------------------------------------------------------------------------------------------------------//
void Ihm::menu()
{
    cout << "Inverse\t\t\ti\nReste et quotient\td\nMini et maxi\t\tm\n"<<endl;
    cout << "Arret\t\t\tf" << endl;
    cout << "Renter votre choix : " <<endl;
    cin >> choix;
}
