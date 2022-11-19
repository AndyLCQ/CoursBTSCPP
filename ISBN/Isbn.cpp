#include <ctype.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
//---------------------------------------------------------------------------
#include "isbn.h"
//---------------------------------------------------------------------------
/***********************************************************************************/
/* Initialise TAILLE
R�serve de la m�moire pour TabIsbn
Copie Tab dans TabIsbn
Appel decompose */
Isbn::Isbn(char * tab):TAILLE(14)
{
    tabIsbn=new char [TAILLE];
    strcpy(tabIsbn, tab);
    decompose();
}
/***********************************************************************************/
/* Lib�re la m�moire */
Isbn::~Isbn()
{
    delete [] tabIsbn;
}
/***********************************************************************************/
/* Contr�le la validit� du chiffre de contr�le
Renvoie un bool�en fonction du r�sultat*/
bool Isbn::verifChec()
{
    bool reussite=false;
    int coeffmu=10;
    int somme=0;
    for(int i=0; i<TAILLE+1; i++)
    {
        if(tabIsbn[i]!='-')
        {
            somme=(tabIsbn[i]*coeffmu)+somme;
            coeffmu--;
        }
    }
    if((somme%11)==0)
    {
        reussite=true;
    }

    return reussite;
}
/***********************************************************************************/
/* Recherche une sous-cha�ne dans une cha�ne, en fonction d'un d�limiteur
exemple :
si source= "2-212-08251-7" et caractereFin=�-�
alors destination="2" et le retour est 1*/
int Isbn::recherche(char * source,char * destination,int debut,char caractereFin)
{

    int i=debut;
    int j=0;
        while(tabIsbn[i]!=caractereFin)
        {
            destination[j]=tabIsbn[i];
            i++;
            j++;
        }
        destination[j+1]=0;

        return i;


}
/***********************************************************************************/
/* D�compose l'isbn est sous cha�nes "pays", "editeur", "titre", "controle"
utilise la m�thode "recherche" */
void Isbn::decompose()
{
    int i;

        i=recherche(tabIsbn, pays, 0, '-');
        i++;
        i=recherche(tabIsbn, editeur, i, '-');
        i++;
        i=recherche(tabIsbn, titre, i, '-');
        i++;
        i=recherche(tabIsbn, controle, i, 0);

}
/***********************************************************************************/
/* Affiche les diff�rents champ : Code Pays, Editeur, Titre, Checksum*/
void Isbn::afficheChamp()
{
        cout << "Pays :" <<pays << endl;
        cout << "Editeur :" <<editeur << endl;
        cout << "Titre :" <<titre << endl;
        cout << "Controle :" <<controle << endl;

}
