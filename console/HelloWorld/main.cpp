#include <iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream monFlux("C:/scores.txt");

if(monFlux)  //On teste si tout est OK
{
    cout<<"ficher texte crée"<<endl;
    monFlux<<"Un Deux Test"<<endl;
    monFlux<<"deuxieme ligne";
    monFlux<<"toujour deuxieme ligne";
}
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
}

    return 0;
}
