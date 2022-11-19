#ifndef TEMPO_H
#define TEMPO_H


class Tempo
{
    /*Attributs*/
    private:
        char unite;             //unit� de la temporisation ('s': seconde ou 'm': milliseconde)
        unsigned int valeurTempo;           // Valeur de la temporisation courante.
    /*M�thodes*/
    public:
        char getUnite();            //Indique l'unit� de la temporisation.
        void setUnite(char paraUnite);      //Modifie la valeur de l'unit� 's' s'il le param�tre est 's' ou 'S', 'm' dans les autres cas.
        unsigned int getValeurTempo();      //Indique la valeur de la tempo.
        void setValeurTempo(unsigned int val);  //Modifie la valeur de la tempo.
        Tempo(unsigned int val=100,char paraUnite='m');     // Ce constructeur permet d�initialiser la valeur de la temporisation, ainsi que l'unit�
                                              //temporisation (valeur par d�faut 100 pour la valeur et milliseconde pour l'unit�).
       void temporisation();        //R�alise la temporisation.
       ~Tempo();
    private:


};

#endif // TEMPO_H
