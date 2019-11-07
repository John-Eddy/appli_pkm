using namespace std;
#include "Pkm.h"
 
Pkm::Pkm(string num)
{
  string fichier="/Pkm/"+num;
  string temp;
  temp=recupLigne(fichier,3);
  m_pdv =21;//atoi(temp.c_str());
  m_pdvmax=m_pdv;
  /*m_patt=recupLigne(fichier,4);
  m_pdef =recupLigne(fichier,5);
  m_vitesse = recupLigne(fichier,8);*/
 
}
void Pkm::afficher(){
          cout<<"Pdv : "<<m_pdv<<" Point att : ";/*<<m_patt<<" Point def : "<<m_pdef<<" Vitesse : "<<m_vitesse<<endl;*/
}

string recupLigne(string fichier,int numLigne)
{
 int i=1;
 string ligne, ligneRecup;
 ifstream file(fichier.c_str());
 if(file){
            while(getline(file, ligne)&& i<=numLigne ){
                                   ligneRecup=ligne;
                                   i++;
            }
  }
    else{
         cerr<<"Erreur"<<endl;
        }
  file.close();
  return ligneRecup;
}

void Pkm::setm_pdv(int pdv){
        m_pdv=pdv;
}
void Pkm::setm_pdvmax(int pdv){
        m_pdvmax=pdv;
}
void Pkm::setm_patt(int point){
         m_patt=point;
}
void Pkm::setm_pdef(int point){
        m_pdef=point;
}
void Pkm::setm_vitesse(int vitesse){
         m_vitesse=vitesse;
}
    
int Pkm::getm_pdv(){
        return m_pdv;
}
int Pkm::getm_pdvmax(){
        return m_pdvmax;
}
int Pkm::getm_patt(){
        return m_patt;
}
int Pkm::getm_pdef(){
        return m_pdef;
}
int Pkm::getm_vitesse(){
        return m_vitesse;
}
