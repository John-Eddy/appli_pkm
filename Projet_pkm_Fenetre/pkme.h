#ifndef PKME_H
#define PKME_H

#include<string.h>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include<pkm.h>

#include <QWidget>
#include <QPushButton>
#include<QGroupBox>
#include <QProgressBar>
#include<QLabel>
#include<QString>
#include<QPixmap>
#include<QGridLayout>
#include<QMessageBox>

using namespace std;

class Pkme : public QWidget
{
    Q_OBJECT
public:

    Pkme(string num);
    string recupLigne(string fichier,int numLigne);
    string intString(int nb);
    QString stringQstring(string str);
    void afficher();




    void setm_nom(string nom);
    void setm_pdv(int pdv);
    void setm_pdvmax(int pdv);
    void setm_patt(int point);
    void setm_pdef(int point);
    void setm_vitesse(int vitesse);
    void setm_vivant(bool vivant);
    void recevoirdegat(int degats);
    void setEnnemie(string *cible);


    string getm_nom();
    int getm_pdv();
    int getm_pdvmax();
    int getm_patt();
    int getm_pdef();
    int getm_vitesse();
    bool getm_vivant();

signals:

public slots:
    void attaquer(Pkme *cible);


private:

    QFrame *m_frame;
    QGridLayout *m_layout;
    QPushButton *m_bouton;
    QProgressBar *m_progressbar;
    QLabel *m_labelImage;
    QLabel *m_labelNom;

    string *m_pkmennemie;


    QLabel *m_vie;

    string m_nom;
    int m_pdv;
    int m_pdvmax;
    int m_patt;
    int m_pdef;
    int m_vitesse;
    bool m_vivant;

};

#endif // PKME_H
