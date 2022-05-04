#ifndef INTERFACE_H
#define INTERFACE_H

#include "engine.h"
#include "interface_global.h"
#include <QDebug>
#include <QObject>

class INTERFACE_EXPORT Interface:public QObject
{
    Q_OBJECT
public:
    Interface(QObject * parent = nullptr);
    ~Interface();
    void open();
    engine * pengine;
signals:
    void sendtoexe(short);

private:


};

#endif // INTERFACE_H

