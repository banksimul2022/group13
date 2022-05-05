#include "engine_rst.h"
#include "iostream"

engine_rst::engine_rst(QObject *parent): QObject(parent) {}
engine_rst::~engine_rst(){}

void engine_rst::on_btntili_clicked(){
    /*QString site_url="http://localhost:3000"+urlEnd;
    std::cout << site_url.toStdString() << std::endl;
    QNetworkRequest request((site_url));

    requestData.insert("idtili","1");
    requestData.insert("saldo","300");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
    reply = manager->put(request, QJsonDocument( requestData).toJson());*/


    QNetworkAccessManager nam;
    QString site_url="http://localhost:3000"+urlEnd;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = nam.put(request, QJsonDocument(requestData).toJson());//QNetworkRequest(QUrl(site_url)));
    while (!reply->isFinished()){
        qApp->processEvents();
    }

    QByteArray response_data=reply->readAll();
    std::cout << requestData.isEmpty() << ": empty?" << std::endl;
    reply->deleteLater();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    reciveData=json_doc;

    std::cout << urlEnd.toStdString() << std::endl;
    std::cout << json_doc.toJson().toStdString() << std::endl;

    emit ReadyToRead();
}

void engine_rst::gettilislot(QNetworkReply *reply){
    disconnect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
    delete manager;
    QByteArray response_data=reply->readAll();
    delete reply;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    reciveData=json_doc;
    std::cout << urlEnd.toStdString() << std::endl;
    std::cout << json_doc.toJson().toStdString() << std::endl;
    emit ReadyToRead();
}


void engine_rst::on_btntili2_clicked(){
    QNetworkAccessManager nam;
    QString site_url="http://localhost:3000"+urlEnd;
    //wait for reply
    QNetworkReply *reply = nam.get(QNetworkRequest(QUrl(site_url)));
    while (!reply->isFinished()){
        qApp->processEvents();
    }
    //process reply
    QByteArray response_data=reply->readAll();
    reply->deleteLater();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    reciveData=json_doc;
    //debug prints "qt creator doesn't display qdebug style prints to I use cout as it works, no I'm not adding the env_var to make qdebug work in MY .profile"
    std::cout << urlEnd.toStdString() << std::endl;
    std::cout << json_doc.toJson().toStdString() << std::endl;
    //inform exe
    emit ReadyToRead();
}

void engine_rst::on_btntili3_clicked(){
    /*QString site_url="http://localhost:3000/tilitapahtumat";

    QNetworkRequest request((site_url));

    requestData.insert("paivklo","20220427");
    requestData.insert("tapahtuma","otto");
    requestData.insert("summa","600");
    requestData.insert("tili","1");

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
    reply = manager->post(request, QJsonDocument( requestData).toJson());*/
    QNetworkAccessManager nam;
    QString site_url="http://localhost:3000"+urlEnd;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    std::cout << QJsonDocument(requestData).toJson().toStdString() << "\nHYYEESSSSSSSS" << std::endl;

    QNetworkReply *reply = nam.post(request, QJsonDocument(requestData).toJson());//QNetworkRequest(QUrl(site_url)));
    while (!reply->isFinished()){
        qApp->processEvents();
    }

    QByteArray response_data=reply->readAll();
    std::cout << requestData.isEmpty() << ": empty?" << std::endl;
    reply->deleteLater();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    reciveData=json_doc;

    std::cout << urlEnd.toStdString() << std::endl;
    std::cout << json_doc.toJson().toStdString() << std::endl;

    emit ReadyToRead();
}
