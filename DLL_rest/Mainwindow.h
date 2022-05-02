#ifndef ENGINE_H
#define ENGINE_H


#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>



class engine : QObject
{
    Q_OBJECT

public:
    engine();
    ~engine();
    QJsonObject requestData;
    QJsonDocument reciveData;
    QString urlEnd="/tilitapahtumat";
    void on_btntili2_clicked();

    void on_btntili3_clicked();
    QJsonDocument getPin(int);
private slots:
    void on_btntili_clicked();
    void gettilislot (QNetworkReply *reply);

    //void getAsiakas;


private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
signals:
    void ReadyToRead();
};

#endif // ENGINE_H
