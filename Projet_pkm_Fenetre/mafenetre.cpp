#include "mafenetre.h"

MaFenetre::MaFenetre(string pkm1, string pkm2) : QWidget()
{

    this->setFixedSize(330,270);

    m_boxlayout=new QGridLayout(this);

    QFrame *interface=new QFrame(this);
    interface->setFrameShape(QFrame::StyledPanel);
    interface->setFixedSize(400,400);

    m_pkme= new Pkm(interface,pkm2,false);

    m_pkm = new Pkm(interface,pkm1,true);

    m_pkm->setEnnemie(m_pkme);
    m_pkme->setEnnemie(m_pkm);

    m_pkme->move(10,10);
    m_pkm->move(10,130);


}
