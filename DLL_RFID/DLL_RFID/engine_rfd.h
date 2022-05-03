#ifndef ENGINE_RFD_H
#define ENGINE_RFD_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QObject>

#include <iostream>
using namespace std;


class Engine_rfd : public QObject
{
    Q_OBJECT
public:
    Engine_rfd(QObject * parent = nullptr);
    ~Engine_rfd();
signals:
    void toInterface(QString);
public slots:
    void getCardReader();
private:
    QString cardID;
    QSerialPort *port;
};

#endif // ENGINE_RFD_H
