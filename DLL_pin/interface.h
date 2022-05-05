#ifndef INTERFACE_H
#define INTERFACE_H

#include "engine.h"
#include <QDebug>
#include <QObject>
#include "interface_global.h"

class engine;//????miksi?????
class INTERFACE_EXPORT Interface : public QObject
{
    Q_OBJECT
public:
    explicit Interface(QObject *parent = nullptr, QString* error = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr, char* pn = nullptr, int krtid = 0);
    ~Interface();
    void doPin();
    char* pinn;
private:
    engine* pengine;

};

#endif // INTERFACE_H

