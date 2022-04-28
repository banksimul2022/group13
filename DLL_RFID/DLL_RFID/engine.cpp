#include "engine.h"



Engine::Engine(QObject *parent) : QObject(parent)
{
    port = new QSerialPort("COM4");
    port->open(QIODevice::ReadOnly);
    QObject::connect(port, &QSerialPort::readyRead, this, &Engine::getCardReader);

}

Engine::~Engine()
{
    delete port;
    port = nullptr;
    QObject::disconnect(port, &QSerialPort::readyRead, this, &Engine::getCardReader);
}

void Engine::getCardReader()
{
       cardID = port->readAll();
       cardID.chop(3);
       cardID.remove(0, 3);

       emit toInterface(cardID);

}
