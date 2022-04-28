#include "interface.h"


Interface::Interface(QObject *parent) : QObject(parent)
{
    pEngine = new Engine(this);
    QObject::connect(pEngine, SIGNAL(toInterface(QString)),
                     this, SLOT(recvNumberFromEngine(QString)));
}

Interface::~Interface()
{
    delete pEngine;
    pEngine = nullptr;
    disconnect(pEngine,SIGNAL(toInterface(QString)),
               this,SLOT(recvNumberFromEngine(QString)));
}


void Interface::recvNumberFromEngine(QString num)
{
    emit sendNumberToExe(num);
}



