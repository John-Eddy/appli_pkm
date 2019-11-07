#include "pkm.h"

using namespace std;

Pkm::Pkm(QWidget *parent, string num, bool monpkm) : QWidget()
{

    this->setParent(parent);

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

    cible=0;
    QFontDatabase::addApplicationFont("C:\\Users\\Eddy\\Desktop\\Projet_pkm_Fenetre\\Pkm\\Police\\PokemonGB.ttf");


    m_frame=new QFrame(this);
    m_bouton = new QPushButton("Attaquer",m_frame);
    QFrame *infoframe=new QFrame(m_frame);
    m_labelNom= new QLabel(infoframe);
    QLabel *pv=new QLabel(infoframe);
    m_progressbar = new QProgressBar(infoframe);
    m_vie = new QLabel(infoframe);
    QPixmap pixmap;


    QObject::connect(this->m_bouton,SIGNAL(clicked()),this,SLOT(attaquer()));



    if(monpkm==true){

        m_frame->setFrameShape(QFrame::StyledPanel);
        m_frame->setFixedSize(310,130);


        infoframe->setFrameShape(QFrame::StyledPanel);
        infoframe->setFixedSize(180,80);
        infoframe->move(120,10);

        m_labelNom->setText(stringQstring(m_nom));
        m_labelNom->setFont(QFont("Pokemon Gb",15));
        m_labelNom->move(5,5);


        pv->setText("PV:");
        pv->setFont(QFont("Pokemon Gb",5));
        pv->move(3,50);

        m_progressbar->setValue(100);
        m_progressbar->setTextVisible(false);
        m_progressbar->setFixedSize(120,5);
        m_progressbar->move(25,50);

        temp =intString(m_pdv)+"/"+intString(m_pdvmax);
        m_vie->setText(stringQstring(temp));
        m_vie->setFont(QFont("Pokemon Gb",10));
        m_vie->move(55,58);


        m_bouton->move(100,100);
        m_bouton->setFont(QFont("Pokemon Gb"));



        temp="C:\\Users\\Eddy\\Desktop\\Projet_pkm_Fenetre\\Pkm\\Image\\"+num;
        QImage image(stringQstring(temp));
        image=image.scaled(100,100);
        m_labelImage = new QLabel(m_frame);
        pixmap=QPixmap::fromImage(image);
        m_labelImage->setPixmap(pixmap);//on donne l'image au label*/
        m_labelImage->move(5,5);

    }
    else
    {
        m_frame->setFrameShape(QFrame::StyledPanel);
        m_frame->setFixedSize(310,110);

        infoframe->setFrameShape(QFrame::StyledPanel);
        infoframe->setFixedSize(220,80);
        infoframe->move(0,0);

        m_labelNom->setText(stringQstring(m_nom));
        m_labelNom->setFont(QFont("Pokemon Gb",15));
        m_labelNom->move(10,5);


        pv->setText("PV:");
        pv->setFont(QFont("Pokemon Gb",5));
        pv->move(22,39);

        m_progressbar->setValue(100);
        m_progressbar->setTextVisible(false);
        m_progressbar->setFixedSize(120,5);
        m_progressbar->move(45,40);

        temp =intString(m_pdv)+"/"+intString(m_pdvmax);
        m_vie->setText(stringQstring(temp));
        m_vie->setFont(QFont("Pokemon Gb",5));
        m_vie->setHidden(true);
        m_vie->move(55,58);

        m_bouton->move(10,80);
        m_bouton->setFont(QFont("Pokemon Gb"));



        temp="C:\\Users\\Eddy\\Desktop\\Projet_pkm_Fenetre\\Pkm\\Image\\"+num;
        QImage image(stringQstring(temp));
        image=image.scaled(70,70);
        m_labelImage = new QLabel(m_frame);
        pixmap=QPixmap::fromImage(image);
        m_labelImage->setPixmap(pixmap);//on donne l'image au label
        m_labelImage->move(210,25);

    }



}
string Pkm::recupLigne(string fichier,int numLigne)
{
    int i=1;
    string ligne, ligneRecup;
    fichier="C:\\Users\\Eddy\\Desktop\\Projet_pkm_Fenetre\\Pkm\\Stat\\"+fichier;
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

void Pkm::recevoirdegat(int degats)
{
    srand(time(NULL));
    int pourcentagedegat = rand()%(30-10)+10;
    degats=degats-(pourcentagedegat*m_pdef/100);

    int pdvtemp=m_pdv;
    m_pdv=m_pdv-degats;

    if(m_pdv<=0)
    {
        m_pdv=0;
        for(pdvtemp;pdvtemp>=m_pdv;pdvtemp--)
        {
            delay(50);
            m_progressbar->setValue(pdvtemp*100/m_pdvmax);
            string temp =intString(pdvtemp)+"/"+intString(m_pdvmax);
            m_vie->setText(stringQstring(temp));

            if(pdvtemp< (m_pdvmax*0.15))
            {
                m_progressbar->setStyleSheet("QProgressBar::chunk{background-color:red}");
            }

            else if(pdvtemp < (m_pdvmax/2))
            {
                m_progressbar->setStyleSheet("QProgressBar::chunk{background-color:orange}");
            }
        }
        m_vivant=false;

    }
    else{
        for(pdvtemp;pdvtemp>=m_pdv;pdvtemp--)
        {
            delay(50);
            m_progressbar->setValue(pdvtemp*100/m_pdvmax);
            string temp =intString(pdvtemp)+"/"+intString(m_pdvmax);
            m_vie->setText(stringQstring(temp));
            if(pdvtemp< (m_pdvmax*0.15))
            {
                m_progressbar->setStyleSheet("QProgressBar::chunk{background-color:red}");
            }
            else if(pdvtemp < (m_pdvmax/2))
            {
                m_progressbar->setStyleSheet("QProgressBar::chunk{background-color:orange}");
            }

        }
    }
}
void Pkm::attaquer()
{
    srand(time(NULL));
    int degatmin =m_patt/2;
    int degats = rand()%(m_patt-degatmin)+degatmin;
    cible->recevoirdegat(degats);
}
string Pkm ::intString(int nb)
{
    stringstream ss;
    ss << nb;
    string str = ss.str();
    return str;
}
QString Pkm::stringQstring(string str)
{
    QString qstr = QString::fromStdString(str);
    return qstr;
}
void Pkm::setEnnemie(Pkm *pkmcible)
{
    cible=pkmcible;
}
void Pkm::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
