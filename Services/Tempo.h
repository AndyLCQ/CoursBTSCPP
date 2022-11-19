#ifndef TEMPO_H
#define TEMPO_H


class Tempo
{
    /*Attributs*/
    private:
        char unite;             //unité de la temporisation ('s': seconde ou 'm': milliseconde)
        unsigned int valeurTempo;           // Valeur de la temporisation courante.
    /*Méthodes*/
    public:
        char getUnite();            //Indique l'unité de la temporisation.
        void setUnite(char paraUnite);      //Modifie la valeur de l'unité 's' s'il le paramètre est 's' ou 'S', 'm' dans les autres cas.
        unsigned int getValeurTempo();      //Indique la valeur de la tempo.
        void setValeurTempo(unsigned int val);  //Modifie la valeur de la tempo.
        Tempo(unsigned int val=100,char paraUnite='m');     // Ce constructeur permet d’initialiser la valeur de la temporisation, ainsi que l'unité
                                              //temporisation (valeur par défaut 100 pour la valeur et milliseconde pour l'unité).
       void temporisation();        //Réalise la temporisation.
       ~Tempo();
    private:


};

#endif // TEMPO_H
