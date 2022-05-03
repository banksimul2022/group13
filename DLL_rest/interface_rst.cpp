#include "interface_rst.h"
#include "iostream"


interface_rst::interface_rst(QObject *parent) : QObject(parent){
    pEngine = new engine_rst(this);
    connect(pEngine, SIGNAL(ReadyToRead), this, SLOT(reciveData));
}

interface_rst::~interface_rst(){
    disconnect(pEngine, &engine_rst::ReadyToRead, this, &interface_rst::reciveData);
    delete pEngine;
}

QJsonDocument interface_rst::getJson(){
    return pEngine->reciveData;
}

void interface_rst::setUrlEnd(QString ue){
    pEngine->urlEnd = ue;
}

void interface_rst::doGet(){
    std::cout << "doget" << std::endl;
    pEngine->on_btntili2_clicked();
    std::cout << "doneget" << std::endl;
}

void interface_rst::doPost(){
    pEngine->on_btntili3_clicked();
}

void interface_rst::doPut(){
    pEngine->on_btntili_clicked();
}

void interface_rst::reciveData(){
    std::cout << "r2r" << std::endl;
    emit gotData();
}
