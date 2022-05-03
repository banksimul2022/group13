#ifndef Interface_H
#define Interface_H

#include "engine_rfd.h"
#include <QDebug>
#include <QObject>
#include "DLL_RFID_global.h"

class DLL_RFID_EXPORT Interface_rfd : public QObject
{
    Q_OBJECT
public:
    Interface_rfd(QObject *parent = nullptr);
    ~Interface_rfd();
signals:
    void sendNumberToExe(QString);
public slots:
    void recvNumberFromEngine(QString);
private:
    Engine_rfd *pEngine;
};
#endif // Interface_H
