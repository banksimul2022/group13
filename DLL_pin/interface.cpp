#include "interface.h"


Interface::Interface(QObject *parent, QString* error, int* state, QApplication* ohjelma, char* pn, int krtid):QObject(parent)
{
    qDebug() <<"pin ui dll luotu!";
    pengine = new engine(nullptr, error, state, ohjelma, pn, krtid);

}

Interface::~Interface()
{
    qDebug() <<"pin ui dll tuhottu!";
    delete pengine;
}

void Interface::doPin()
{
    pengine->doPin();
    pinn = pengine->pinn;
}
