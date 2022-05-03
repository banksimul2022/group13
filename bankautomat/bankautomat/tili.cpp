#include "tili.h"
#include "ui_tili.h"
#include "iostream"

tili::tili(QWidget *parent, QString* error, int* state, QApplication* ohjelma, int cardid) : QWidget(parent), ui(new Ui::tili){
    ui->setupUi(this);

    lerri = error;
    lstate = state;
    lohjelma = ohjelma;
    kortti = cardid;
}

tili::~tili()
{
    delete ui;
}

void tili::doTili(){
    /*this->show();
    lohjelma->processEvents();
    *lstate = fatalE;
    *lerri = "fatal exit from tili";
    lohjelma->processEvents();
    QThread::sleep(4);
    lohjelma->processEvents();
    this->close();*/
    *lstate=99;
    this->show();
    initializeTiliData();
    updateTiliData();
    while(*lstate==99){
        //lohjelma->processEvents();
        QThread::msleep(15);
        lohjelma->processEvents();
    }
    this->close();//close our window
}

void tili::on_logoutPushButton_clicked()
{
    *lstate = noticeE;
    *lerri = "basic logout exit";
}


void tili::on_nosta1PushButton_clicked(){
    int num = ui->tili1LineEdit->text().toInt();
    ui->tili1LineEdit->setText("");
    //get current account data
    //do the put
    if(num != 0){
        //set up the request
        interface_rst nwa;
        nwa.pEngine->requestData.insert("tili",QString::number(tiliId));
        nwa.pEngine->requestData.insert("saldo",QString::number(saldo-num));
        nwa.setUrlEnd(QString ("/tili/%1").arg(tiliId));
        nwa.doPut();
        updateTiliData();
    }
    //get new account state
    updateTiliData();
}


void tili::on_laita1PushButton_clicked(){
    int num = ui->tili1LineEdit->text().toInt();
    ui->tili1LineEdit->setText("");
    //get current account data
    //do the put
    if(num != 0){
        //set up the request
        interface_rst nwa;
        nwa.pEngine->requestData.insert("tili",QString::number(tiliId));
        nwa.pEngine->requestData.insert("saldo",QString::number(saldo+num));
        nwa.setUrlEnd(QString ("/tili/%1").arg(tiliId));
        nwa.doPut();
        updateTiliData();
    }
    //get new account state
    updateTiliData();
}


void tili::requestReady(){
    nwb = false;
}

void tili::initializeTiliData(){
    //tilin id
    interface_rst nwa;
    QString krt =QString ("/kortti/%1").arg(kortti);
    nwa.setUrlEnd(krt);
    nwa.doGet();
    /*connect(nwa, SIGNAL(gotData), this, SLOT(requestReady));
    nwb=true;
    while(nwb){//wait for network to reply
        QThread::msleep(15);
        lohjelma->processEvents();
    }
    disconnect(nwa, SIGNAL(gotData), this, SLOT(gotKortti));*/
    //process json
    //int tiliId = 0;
    QJsonArray json_array = nwa.getJson().array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        tiliId=QString::number(json_obj["tili_idtili"].toInt()).toInt();
    }
    //tilin tiedot
    interface_rst nwa2;
    nwa2.setUrlEnd(QString ("/tili/%1").arg(tiliId));
    nwa2.doGet();
    QJsonArray json_array2 = nwa2.getJson().array();
    foreach (const QJsonValue &value, json_array2) {
        QJsonObject json_obj = value.toObject();
        saldo=QString::number(json_obj["saldo"].toInt()).toInt();
    }
    std::cout << tiliId << ":" << saldo << ":" << kortti << std::endl;
}

void tili::updateTiliData(){
    interface_rst nwa2;
    nwa2.setUrlEnd(QString ("/tili/%1").arg(tiliId));
    nwa2.doGet();
    QJsonArray json_array2 = nwa2.getJson().array();
    foreach (const QJsonValue &value, json_array2) {
        QJsonObject json_obj = value.toObject();
        saldo=QString::number(json_obj["saldo"].toInt()).toInt();
    }
    ui->raha1Label->setText(QString::number(saldo));
    lohjelma->processEvents();
}

