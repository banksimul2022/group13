#include "tilakone.h"
#include "engine.h"
#include "interface_rst.h"


tilakone::tilakone(QApplication* ohjel){
    ohjelma = ohjel;
    //ohjelma->setQuitOnLastWindowClosed(false);
    errorMessage = "Just käynnistetty eli ei virheitä :D.";
}
tilakone::~tilakone(){
}

//tiloja
void tilakone::exitti(QString msg, bool kill){
    qDebug() << kill << ' ' << state << '\t' << msg;
    stop = kill;
    if (stop==true){
        ohjelma->exit(0);
        this->quit();
    }
    errorMessage = msg;
    state = korttiS;
}
void tilakone::sfKortti(){
    scan s(nullptr, &errorMessage, &state, ohjelma, &cardId);
    s.doScan();
}
void tilakone::sfPin(){
    //pin p(nullptr, &errorMessage, &state, ohjelma, pinNums, cardId.toInt(nullptr, 16));
    //p.do;
    Interface p(nullptr, &errorMessage, &state, ohjelma, pinNums, cardId.toInt(nullptr, 16));
    while(state == pinS){
        p.doPin();
        if(testPin(QString::fromUtf8(p.pinn, 4).toInt())){
            state = tiliS;
        }
    }
}
void tilakone::sfTili(){
    tili t(nullptr, &errorMessage, &state, ohjelma, cardId.toInt(nullptr, 16));
    t.doTili();
}

//se kone
void tilakone::run(){
    QThread::msleep(50);
    ohjelma->setQuitOnLastWindowClosed(false);
    while(!stop){
        qDebug() << state;
        switch(state){
            case korttiS :
                sfKortti();
                std::cout << cardId.toStdString() << ":" << cardId.toInt(nullptr, 16) << std::endl;
                break;
            case pinS :
                sfPin();
                break;
            case tiliS :
                sfTili();
                break;
            case noticeE:
                exitti(errorMessage, false);
                break;
            case warningE:
                exitti(errorMessage, false);
                break;
            case fatalE:
                exitti(errorMessage, true);
                break;
            default :
                exitti("state non existent", false);
        }
    }
}

bool tilakone::testPin(int tp){
    bool ret = false;
    interface_rst nwa;// = new QNetworkAccessManager;
    QString krt = "/kortti/"+QString::number(cardId.toInt(nullptr, 16));
    nwa.setUrlEnd(krt);
    nwa.doGet();
//    connect(nwa, SIGNAL(gotData), this, SLOT(gotKortti));
//    nwb = true;
//    while(nwb){//wait for network to reply
//        QThread::msleep(15);
//        lohjelma->processEvents();
//    }
//    disconnect(nwa, SIGNAL(gotData), this, SLOT(gotKortti));
    //process json
    int rpin = 0;
    QJsonArray json_array = nwa.getJson().array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        //rkrtid=QString::number(json_obj["idkortti"].toInt()).toInt();
        rpin=QString::number(json_obj["pin"].toInt()).toInt();
    }
    std::cout << krt.toStdString() << ":" << rpin << ":" << tp << std::endl;
    if(tp == rpin){
        ret = true;
    }
    std::cout << ret << nwa.getJson().toJson().toStdString() << std::endl;
    return ret;
}
