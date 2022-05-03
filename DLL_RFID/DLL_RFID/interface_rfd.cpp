#include "interface_rfd.h"


Interface_rfd::Interface_rfd(QObject *parent) : QObject(parent)
{
    pEngine = new Engine_rfd(this);
    connect(pEngine, SIGNAL(toInterface(QString)), this, SLOT(recvNumberFromEngine(QString)));
}

Interface_rfd::~Interface_rfd()
{
    delete pEngine;
    pEngine = nullptr;
    disconnect(pEngine,SIGNAL(toInterface(QString)), this, SLOT(recvNumberFromEngine(QString)));
}


void Interface_rfd::recvNumberFromEngine(QString num)
{
    emit sendNumberToExe(num);
}



