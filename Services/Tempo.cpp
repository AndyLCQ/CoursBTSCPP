#include "Tempo.h"
#include <windows.h>

using namespace std;
//---------------------------------------------------------------------------//
/***********************************************************************************/
/* Ce constructeur permet d�initialiser la valeur de la temporisation, ainsi que l'unit�
de temporisation (valeur par d�faut 100 pour la valeur et milliseconde pour l'unit�).*/
Tempo::Tempo(unsigned int val,char paraUnite)
{
    valeurTempo=val;
    unite=paraUnite;
}
/***********************************************************************************/
Tempo::~Tempo()
{
    //dtor
}
/***********************************************************************************/
/*Indique l'unit� de la temporisation.*/
char Tempo::getUnite()
{
    return unite;
}
/***********************************************************************************/
/*Modifie la valeur de l'unit� 's' s'il le param�tre est 's' ou 'S', 'm' dans les autres cas.*/
void Tempo::setUnite(char paraUnite)
{
        switch (paraUnite)
        {
        case 's':
             unite='s';break;
        case 'S':
             unite='s';break;
        default :
            unite='m';break;
        }
}
/***********************************************************************************/
/*Indique la valeur de la tempo*/
unsigned int Tempo::getValeurTempo()
{
    return valeurTempo;
}
/***********************************************************************************/
/*R�alise la temporisation*/
void Tempo::temporisation()
{
    int seconde=getValeurTempo();
    if(getUnite()=='s')
    {
        seconde=getValeurTempo()*1000;
    }
    Sleep(seconde);
}
