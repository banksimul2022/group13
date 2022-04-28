#ifndef Interface_H
#define Interface_H

#include "engine.h"
#include <QDebug>
#include <QObject>
#include "DLL_RFID_global.h"




class DLL_RFID_EXPORT Interface : public QObject
{
    Q_OBJECT
public:
    Interface(QObject *parent = nullptr);
    ~Interface();
signals:
    void sendNumberToExe(QString);
public slots:
    void recvNumberFromEngine(QString);
private:
    Engine *pEngine;


};
#endif // Interface_H
