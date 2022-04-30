#ifndef ENGINE_H
#define ENGINE_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QObject>

#include <iostream>
using namespace std;


class Engine : public QObject
{
    Q_OBJECT
public:
    Engine(QObject * parent = nullptr);
    ~Engine();
signals:
    void toInterface(QString);
public slots:
    void getCardReader();
private:
     QString cardID;
    QSerialPort *port;

};

#endif // ENGINE_H
