#include "pkme.h"

using namespace std;

Pkme::Pkme(string num) : QWidget()
{
    m_vivant=true;
    string temp=recupLigne(num,2);
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

    m_pkmennemie = 0;

    m_frame=new QFrame(this);
    m_frame->setFixedSize(600,200);

    m_labelNom= new QLabel(m_frame);
    m_labelNom->setText(stringQstring(m_nom));


    m_vie = new QLabel(m_frame);
    temp =intString(m_pdv)+"/"+intString(m_pdvmax);
    m_vie->setText(stringQstring(temp));

    m_bouton = new QPushButton("Attaquer",m_frame);

    m_progressbar = new QProgressBar(m_frame);
    m_progressbar->setValue(100);
    m_progressbar->setTextVisible(false);



    temp="C:\\Users\\Eddy\\Desktop\\Projet_pkm_Fenetre\\Pkm\\Image\\"+num;
    QImage image(temp);
    image=image.scaled(100,100);
    m_labelImage = new QLabel(m_frame);
    QPixmap pixmap;
    pixmap=QPixmap::fromImage(image);
    m_labelImage->setPixmap(pixmap);//on donne l'image au label*/


    m_layout = new QGridLayout(m_frame);
    m_layout->addWidget(m_bouton,1,3);
    m_layout->addWidget(m_progressbar,2, 4,1,6);
    m_layout->addWidget(m_vie, 2, 3);
    m_layout->addWidget(m_labelImage, 0,0,3,3);
    m_layout->addWidget(m_labelNom, 1, 4);


    m_frame->setLayout(m_layout);

    try{
         QObject::connect(m_bouton,SIGNAL(clicked()), this, SLOT(attaquer(cible))) ;
    }


}
string Pkme::recupLigne(string fichier,int numLigne)
{
    int i=1;
    string ligne, ligneRecup;
    ifstream  myFile(fichier.c_str(),ios::in);
    if(myFile)
    {
        while(getline(myFile, ligne)&& i<=numLigne )
        {
            ligneRecup=ligne;
            i++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Pkm introuvable","Aucun pkm accessible au chemin :");
    }
    myFile.close();
    return ligneRecup;
}
void Pkme::recevoirdegat(int degats)
{
    srand(time(NULL));

    int pourcentagedegat = rand()%(30-10)+10;
    degats=degats-(pourcentagedegat*m_pdef/100);

    int pdvtemp=m_pdv;
    m_pdv=m_pdv-degats;

    if(m_pdv<=0){
        for(pdvtemp;pdvtemp>=0;pdvtemp--)
        {
            m_progressbar->setValue(pdvtemp);
            if(pdvtemp < (m_pdvmax/3))
            {
                 m_progressbar->setStyleSheet("QProgressBar::chunk{background-color:orange}");
            }
            else if(pdvtemp< (10*m_pdvmax/100))
            {
                m_progressbar->setStyleSheet("QProgressBar::chunk{background-color:red}");
            }
        }
        m_vivant=false;
        m_pdv=0;
    }
    else{
        for(pdvtemp;pdvtemp>=m_pdv;pdvtemp--)
        {
            m_progressbar->setValue(pdvtemp);
        }
    }
}
void Pkme::attaquer(Pkm *cible)
{
    srand(time(NULL));
    int degatmin =m_patt/2;
    int degats = rand()%(m_patt-degatmin)+degatmin;
    cout<<endl<<m_nom<<" attaque de "<<degats<<endl;
    cible->recevoirdegat(degats);
}
string Pkme ::intString(int nb)
{
    stringstream ss;
    ss << nb;
    string str = ss.str();
    return str;
}
QString Pkme::stringQstring(string str)
{
    QString qstr = QString::fromStdString(str);
    return qstr;
}
void Pkme::setEnnemie(string *cible)
{
   m_pkmennemie=cible;
}
