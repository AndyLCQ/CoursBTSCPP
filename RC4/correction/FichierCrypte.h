//---------------------------------------------------------------------------

#ifndef FichierCrypteH
#define FichierCrypteH
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class RC4;
/* cryptage ou décryptage d'un fichier en rc4 */
class FichierCrypte
{
    private:
        RC4 * monRC4;               // classe de cryptage et décryptage
        string nomSource;           // nom du fichier source à crypter
        string nomDestination;      // nom du fichier destination crypté
        bool cryptage;              // cryptage (true), décryptage (false)
        fstream fichierSource;      // fichier source
        fstream fichierDestination; // fichier destination
    public:
        // contructeur : cryptage par défaut, cry extension par défaut pour le
        // crypatge, txt extension par défaut pour le décryptage
        FichierCrypte(string valSource,bool valCryptage=true,string valExtension="");
        // destructeur
        ~FichierCrypte();
        // décryptage du fichier
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
 