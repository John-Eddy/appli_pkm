using namespace std;
#include "Pkm.h"

Pkm::Pkm(string num)
{
  m_vivant=true;
  string temp;
  temp=recupLigne(num,2);
  m_nom =temp;
  temp=recupLigne(num,3);
  m_pdv =atoi(temp.c_str());
  m_pdvmax=m_pdv;
  temp=recupLigne(num,4);
  m_patt=atoi(temp.c_str());
  temp=recupLigne(num,5);
  m_pdef =atoi(temp.c_str());
  temp = recupLigne(num,8);
  m_vitesse=atoi(temp.c_str());

}
void Pkm::attaquer(Pkm &cible){
    srand(time(NULL));
    int degatmin =m_patt/2;
    int degats = rand()%(m_patt-degatmin)+degatmin;
    cout<<endl<<m_nom<<" attaque de "<<degats<<endl;
    cible.recevoirdegat(degats);

}
void Pkm::recevoirdegat(int degats){
    srand(time(NULL));

    int pourcentagedegat = rand()%(30-10)+10;
    degats=degats-(pourcentagedegat*m_pdef/100);
    m_pdv=m_pdv-degats;
    if(m_pdv<=0){
        m_vivant=false;
        //cout<<m_nom<<" reduit les degat de "<<(pourcentagedegat*m_pdef/100)<<" et perd "<<degats<<" pdv !"<<endl;
        m_pdv=0;
    }
    else{
        //cout<<m_nom<<" reduit les degat de "<<(pourcentagedegat*m_pdef/100)<<" et perd "<<degats<<" pdv !"<<endl;
    }
}

void Pkm::afficher(){
          int pourcentagevie = m_pdv*100/m_pdvmax;
          string barre="";
          for(int i=0;i<pourcentagevie;i=i+2){
              barre=barre+"|";
          }
          cout<<" Nom : "<<m_nom<<endl<<"Pdv : " << m_pdv<<"/"<<m_pdvmax<<" "<<barre<<endl;

}

string Pkm::recupLigne(string fichier,int numLigne)
{
    int i=1;
    string ligne, ligneRecup;
    ifstream  myFile(fichier.c_str(),ios::in);
    if(myFile){
        while(getline(myFile, ligne)&& i<=numLigne ){
                                   ligneRecup=ligne;
                                   i++;
        }
    }
    else{
         cerr<<"Erreur"<<endl;
        }
    myFile.close();
    return ligneRecup;
}

void Pkm::setm_nom(string nom){
    m_nom=nom;
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
void Pkm::setm_vivant(bool vivant){
    m_vivant=vivant;
}
string Pkm::getm_nom(){
    return m_nom;
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
bool Pkm::getm_vivant(){
    return m_vivant;
}
