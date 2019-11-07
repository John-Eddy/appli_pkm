using namespace std;

#include "Pkm.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<windows.h>
int nombrepkm;

void pkmAffciher(Pkm monPkm,Pkm pkmEnnemie){
    pkmEnnemie.afficher();
    cout<<"\n\n\n\n\n\n\n";
    monPkm.afficher();
    cout<<"\n\n\n\n";
}

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
void comptepkm(){
    int i=1;
    string numpkm ="Pkm\\"+convertInt(i);
    bool pkm=true;

    while(pkm==true){
        ifstream  myFile(numpkm.c_str(),ios::in);
        if(myFile){
            i+=1;
        }
        else{
            pkm=false;
        }
        myFile.close();
       numpkm ="Pkm\\"+convertInt(i);

    }
    nombrepkm=i-1;
}
int main(int argc, char *argv[])
{
  
    comptepkm();//compte le nombre de pkm disponible dans le fichier

    Pkm monPkm("Pkm\\1");//creation des objet pkm
    Pkm pkmEnnemie("Pkm\\2");

    char reponse;
    bool pkmvivant=true;
    do{
        pkmAffciher(monPkm,pkmEnnemie);
       cout<<"Voulez  attaquez ?(o pour oui, n pour non) :";
       cin>>reponse;
       if(reponse=='o'){
          monPkm.attaquer(pkmEnnemie);//monPkm attaque
          if(pkmEnnemie.getm_vivant()==false){//si  pkm ennemie est Hs
              pkmvivant=false;
              system("cls");
              pkmAffciher(monPkm,pkmEnnemie);
              cout<<monPkm.getm_nom()<<" remport le combat !"<<endl;
          }
          Sleep(2000); //pause
          if(pkmvivant==true){
            pkmEnnemie.attaquer(monPkm);
            if(monPkm.getm_vivant()==false){//si mon pkm est Hs
                  pkmvivant=false;
                  system("cls");
                  pkmAffciher(monPkm,pkmEnnemie);
                cout<<pkmEnnemie.getm_nom()<<" remport le combat !"<<endl;
            }
          }
       }
       Sleep(4000); //pause
       system("cls");
    }while(reponse == 'o' && pkmvivant == true );


    return 0;
}
