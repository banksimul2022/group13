#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


class engine_rst : public QObject {
    Q_OBJECT

public:
    engine_rst(QObject * parent = nullptr);
    ~engine_rst();
    QJsonObject requestData;
    QJsonDocument reciveData;
    QString urlEnd;
    void on_btntili_clicked();  //put
    void on_btntili2_clicked(); //get
    void on_btntili3_clicked(); //post
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
signals:
    void ReadyToRead();
private slots:
    void gettilislot (QNetworkReply *reply);
private:

};

#endif // ENGINE_H
