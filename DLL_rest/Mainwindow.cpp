#include "Mainwindow.h"



    engine::engine()

    {

    }

    engine::~engine()
    {

    }


    void engine::on_btntili_clicked()
    {

        QString site_url="http://localhost:3000"+urlEnd;

        QNetworkRequest request((site_url));

         requestData.insert("idtili","1");
         requestData.insert("saldo","300");
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
        reply = manager->put(request, QJsonDocument( requestData).toJson());
        disconnect(manager,SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
    }

    void engine::gettilislot(QNetworkReply *reply)
    {
           QByteArray response_data=reply->readAll();
           QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
           reciveData=json_doc;
          QJsonArray json_array = json_doc.array();
          emit ReadyToRead();
        //   QString parsedJSON;
      //  if(urlEnd.contains("tilitapahtumat")){
        //   foreach (const QJsonValue &value, json_array) {
         //       QJsonObject json_obj = value.toObject();
           //     parsedJSON+=QString::number(json_obj["idtilitapahtumat"].toInt())+","+json_obj["paiv/klo"].toString()+","+json_obj["tapahtuma"].toString()+","+json_obj["summa"].toString()+","+json_obj["tili_idtili"].toString();

           }
        //}else if (urlEnd.contains("tili")){
          //  foreach (const QJsonValue &value, json_array) {
            //   QJsonObject json_obj = value.toObject();
              // parsedJSON +=QString::number(json_obj["idtili"].toInt())+","+QString::number(json_obj["saldo"].toInt());
       // }
        //}else if

          // qDebug()<<parsedJSON;

           //ui->txttili->setText(parsedJSON);

           //reply->deleteLater();
           //manager->deleteLater();
    //}

    void engine::on_btntili2_clicked()
    {
        QString site_url="http://localhost:3000"+urlEnd;

        QNetworkRequest request((site_url));

        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
        reply = manager->get(request);
        disconnect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));

    }
    QJsonDocument engine::getPin(int id){
        QString site_url="http://localhost:3000/kortti/";
        site_url.append(id);

        QNetworkRequest request((site_url));

        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
        reply = manager->get(request);
        disconnect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
        return reciveData;
    }


    void engine::on_btntili3_clicked()
    {
        QString site_url="http://localhost:3000/tilitapahtumat";

        QNetworkRequest request((site_url));

        requestData.insert("paivklo","20220427");
        requestData.insert("tapahtuma","otto");
        requestData.insert("summa","600");
        requestData.insert("tili","1");

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
        reply = manager->post(request, QJsonDocument( requestData).toJson());
        disconnect(manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gettilislot(QNetworkReply*)));
    }


