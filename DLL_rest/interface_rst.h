#ifndef INTERFACE_RST_H
#define INTERFACE_RST_H

#include "engine_rst.h"
#include <QObject>
#include "DLL_rest_global.h"

class DLL_REST_EXPORT interface_rst : public QObject
{
    Q_OBJECT
public:
    interface_rst(QObject *parent = nullptr);
    ~interface_rst();
    QJsonDocument getJson();
    void setUrlEnd(QString);
    void doGet();
    void doPost();
    void doPut();
    engine_rst *pEngine;
signals:
    void gotData();
public slots:
    void reciveData();
private:

};
#endif // INTERFACE_RST_H
