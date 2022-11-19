//---------------------------------------------------------------------------

#ifndef FichierCrypteH
#define FichierCrypteH
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class RC4;
/* cryptage ou d�cryptage d'un fichier en rc4 */
class FichierCrypte
{
    private:
        RC4 * monRC4;               // classe de cryptage et d�cryptage
        string nomSource;           // nom du fichier source � crypter
        string nomDestination;      // nom du fichier destination crypt�
        bool cryptage;              // cryptage (true), d�cryptage (false)
        fstream fichierSource;      // fichier source
        fstream fichierDestination; // fichier destination
    public:
        // contructeur : cryptage par d�faut, cry extension par d�faut pour le
        // crypatge, txt extension par d�faut pour le d�cryptage
        FichierCrypte(string valSource,bool valCryptage=true,string valExtension="");
        // destructeur
        ~FichierCrypte();
        // d�cryptage du fichier
        void decrypteFichier();
        // cryptage du fichier
        void crypteFichier();
        string getNomSource();
        string getNomDestination();
    private:
        // controle de l'extension du fichier destinatiob
        bool controleExtensionFichier(string valExtension);
        // contruction du nom du fichier destination
        void nomFichierDestination(string valExtension);
};
//---------------------------------------------------------------------------
#endif
 