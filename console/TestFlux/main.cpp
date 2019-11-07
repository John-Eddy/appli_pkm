#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream monFlux("scores.txt");  //Ouverture d'un fichier en lecture

    if(monFlux)
    {
        //Tout est pr�t pour la lecture.
        string ligne;
        getline(monFlux, ligne); //On lit une ligne compl�te
        cout<<ligne;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
    }
