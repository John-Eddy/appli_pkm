#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;


// On suppose a<b
int rand_a_b(int a, int b)
{
    return rand()%(b-a)+a;
}
void test_format(int difficulte)
{
    while(difficulte  <1 || difficulte >3)
        {
            cout<<"\nFormat incorecte\nEntrez la difiulte: \n1: nombre de 0 a 10 \n2: nombre de 0 a 100 \n3: nombre de 0 a 1000"<<endl;
            cin>>difficulte;
        }
}
int jeu(int nb_hasard)
{
    int nb_essais=1,essais;
    cout<<"\nEssayer de trouver le nombre. \n\nEssai numero 1: ";
    cin>>essais;

    while(essais != nb_hasard)
    {
        nb_essais++;
        if(essais>nb_hasard)
        {
            cout<<"\nTROP GRAND !"<<endl;
        }
        else
        {
            cout<<"\nTROP PETIT"<<endl;
        }
        cout<<"Essai numero"<<nb_essais<<": ";
        cin>>essais;
    }
    return nb_essais;
}

int main()
{
    srand(time(NULL));

    int difficulte,reesayer;
    string pseudo;


    cout<<"Entrez un pseudo: ";
    cin>>pseudo;
    cout<<"\nBonjour "<<pseudo<<endl;

    do{
        cout<<"\nEntrez la difiulte: \n1: nombre de 0 a 10 \n2: nombre de 0 a 100 \n3: nombre de 0 a 1000"<<endl;
        cin>>difficulte;
        test_format(difficulte);

        if(difficulte == 1)
        {
            int nombre_hasard=rand_a_b(0,11);
            int nombre_essais=jeu(nombre_hasard);
            cout<<"\nTrouve! en "<<nombre_essais<<" essais"<<endl;

        }
        else if(difficulte == 2)
        {
            int nombre_hasard=rand_a_b(0,101);
            int nombre_essais=jeu(nombre_hasard);
            cout<<"\nTrouve! en "<<nombre_essais<<" essais"<<endl;
        }
        else
        {
            int nombre_hasard=rand_a_b(0,1001);
            int nombre_essais=jeu(nombre_hasard);
            cout<<"\nTrouve! en "<<nombre_essais<<" essais"<<endl;
        }

        cout<<"\nVoulez vous rejouer (1 oui) :";
        cin>>reesayer;
        cout<<endl;

    }while(reesayer==1);

    return 0;
}
