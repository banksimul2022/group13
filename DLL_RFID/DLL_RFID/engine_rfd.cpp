#include "engine_rfd.h"

Engine_rfd::Engine_rfd(QObject *parent) : QObject(parent)
{
    port = new QSerialPort("ttyACM0");
    port->open(QIODevice::ReadOnly);
    QObject::connect(port, &QSerialPort::readyRead, this, &Engine_rfd::getCardReader);
}

Engine_rfd::~Engine_rfd()
{
    delete port;
    port = nullptr;
    QObject::disconnect(port, &QSerialPort::readyRead, this, &Engine_rfd::getCardReader);
}

void Engine_rfd::getCardReader()
{
       cardID = port->readAll();
       cardID.chop(3);
       cardID.remove(0, 8);

       emit toInterface(cardID);

}
