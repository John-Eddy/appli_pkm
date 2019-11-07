#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include<QObject>
#include<QFrame>
#include<QGridLayout>
#include<QPushButton>

#include "pkm.h"

class MaFenetre : public QWidget
{
     Q_OBJECT
public:

    MaFenetre(string pkm1,string pkm2);

private:

    QFrame *m_frame;
    QGridLayout *m_boxlayout;
    Pkm *m_pkm;
    Pkm *m_pkme;
    QPushButton *m_bouton;


signals:

public slots:

};

#endif // MAFENETRE_H
