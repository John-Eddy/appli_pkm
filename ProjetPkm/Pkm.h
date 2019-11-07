#ifndef PKM_H
#define PKM_H

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>


class Pkm
{
    public:

    Pkm(string num);
    string recupLigne(string fichier,int numLigne);
    void afficher();
    void attaquer(Pkm &cible);
    void recevoirdegat(int degats);

    void setm_nom(string nom);
    void setm_pdv(int pdv);
    void setm_pdvmax(int pdv);
    void setm_patt(int point);
    void setm_pdef(int point);
    void setm_vitesse(int vitesse);
    void setm_vivant(bool vivant);



    string getm_nom();
    int getm_pdv();
    int getm_pdvmax();
    int getm_patt();
    int getm_pdef();
    int getm_vitesse();
    bool getm_vivant();




    private:

    string m_nom;
    int m_pdv;
    int m_pdvmax;
    int m_patt;
    int m_pdef;
    int m_vitesse;
    bool m_vivant;

};

#endif // PKM_H
