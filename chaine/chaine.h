#ifndef ChaineH
#define ChaineH
//---------------------------------------------------------------------------
class Chaine
{
	private:
		int nbMaxCar;  // nombre maxi de caractères dans la chaîne
		int nbCar;     // nombre courant de caractères dans la chaîne
		char *tab;     // chaîne
	public:
		Chaine(int valNbCar);   // valNbCar : nombre max de caracteres
		~Chaine();              // libération de la m"émoire pour la chaîne
		int taille();           // taille de la chaîne
		void vide();            // réinitialisation de la chaîne
		void affiche();         // affichage de la chaîne
		bool ajouteCaractere(char cara);    // ajout si possible d'un caractère en fin de chaîne
		char retireCaractere();        // retire si possible le dernier caractère
		void minuscule();              // mise en minuscule des caractères
		void majuscule();              // mise en majuscule des caractères
	private:
		void init();                   // mise à zéro des cases de la chaîne
};
//---------------------------------------------------------------------------
#endif