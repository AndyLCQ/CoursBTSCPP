//---------------------------------------------------------------------------

#ifndef IHMApplicationH
#define IHMApplicationH

#include "FichierCrypte.h"

/* IHM pour le cryptage et le decryptage de fichier en RC4*/
class IHMApplication
{
    private:
        // fichier à traiter
        FichierCrypte * fic;
        // nom du fichier à traiter
        string nomFic;
        // extension du fichier destination
        string extension;
        // choix de l'utilisateur
        char choixUtilisateur;
        // fin de programme
        const char FIN;
    public:
        IHMApplication();
        void lancer();
        ~IHMApplication();
    private:
        // affichage du menu
        void afficherChoix();
        // traitement du choix de l'utilisateur
        void traiterChoix();
        // cryptage d'un fichier
        void crypter();
        // décryptage d'un fichier
        void decrypter();
        // saisie de nom du fichier source, vérification de son existance et
        // saisie de l'extension du fichier destination
        bool saisieFichier();
};
//---------------------------------------------------------------------------
#endif
