#include "tilakone.h"

tilakone::tilakone(QApplication* ohjel){
    ohjelma = ohjel;
    ohjelma->setQuitOnLastWindowClosed(false);
    errorMessage = "no error yay";
}
tilakone::~tilakone(){
}

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
    scan s(nullptr, &errorMessage, &state, ohjelma);
    s.doScan();
}
void tilakone::sfPin(){
    pin p(nullptr, &errorMessage, &state, ohjelma);
    p.doPin();
}
void tilakone::sfTili(){
    tili t(nullptr, &errorMessage, &state, ohjelma);
    t.doTili();
}
void tilakone::run(){
    while(!stop){
        qDebug() << state;
        switch(state){
            case korttiS :
                sfKortti();
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
