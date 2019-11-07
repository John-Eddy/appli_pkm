#ifndef DEF_PKM
#define DEF_PKM
using namespace std;
#include <string>
#include <fstream>
#include <iostream>


class Pkm
{
    public:
    
    Pkm(string num);
    string recupLigne(string fichier,int numLigne);
    void afficher();
    
    void setm_pdv(int pdv);
    void setm_pdvmax(int pdv);
    void setm_patt(int point);
    void setm_pdef(int point);
    void setm_vitesse(int vitesse);
    
    int getm_pdv();
    int getm_pdvmax();
    int getm_patt();
    int getm_pdef();
    int getm_vitesse();
    
    

    private:

    
    int m_pdv;
    int m_pdvmax;
    int m_patt;
    int m_pdef;
    int m_vitesse;
    
    
    
};

#endif
