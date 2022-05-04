#include "interface.h"


Interface::Interface(QObject *parent):QObject(parent)
{
    qDebug() <<"pin ui dll luotu!";
    pengine = new engine;
}

Interface::~Interface()
{
    qDebug() <<"pin ui dll tuhottu!";
}

void Interface::open()
{
    short huuhaa = 5;
    emit sendtoexe(huuhaa);
}
