#ifndef TILAKONE_H
#define TILAKONE_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QApplication>
#include "enumi.h"
#include "scan.h"
#include "pin.h"
#include "tili.h"
//#include "dll_rest.h"
//#include "dll_rfid.h"

//enum states{kortti, pin, tili};

class tilakone: public QThread
{
public:
    tilakone(QApplication*);
    ~tilakone();
protected:
    virtual void run();
private:
    void exitti(QString, bool);
    //nää sfFunktion on varmaan turhia...
    void sfKortti();
    void sfPin();
    void sfTili();
    int state=korttiS;
    QApplication* ohjelma;
    QString errorMessage;
    bool stop = false;
    char pinNums[4];
};

#endif // TILAKONE_H
