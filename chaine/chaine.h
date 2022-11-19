#ifndef ChaineH
#define ChaineH
//---------------------------------------------------------------------------
class Chaine
{
	private:
		int nbMaxCar;  // nombre maxi de caract�res dans la cha�ne
		int nbCar;     // nombre courant de caract�res dans la cha�ne
		char *tab;     // cha�ne
	public:
		Chaine(int valNbCar);   // valNbCar : nombre max de caracteres
		~Chaine();              // lib�ration de la m"�moire pour la cha�ne
		int taille();           // taille de la cha�ne
		void vide();            // r�initialisation de la cha�ne
		void affiche();         // affichage de la cha�ne
		bool ajouteCaractere(char cara);    // ajout si possible d'un caract�re en fin de cha�ne
		char retireCaractere();        // retire si possible le dernier caract�re
		void minuscule();              // mise en minuscule des caract�res
		void majuscule();              // mise en majuscule des caract�res
	private:
		void init();                   // mise � z�ro des cases de la cha�ne
};
//---------------------------------------------------------------------------
#endif