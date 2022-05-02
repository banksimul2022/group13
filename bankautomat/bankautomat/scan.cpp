#include "scan.h"
#include "ui_scan.h"

scan::scan(QWidget *parent, QString* error, int* state, QApplication* ohjelma, QString* cardId) :
    QWidget(parent),
    ui(new Ui::scan)
{
    ui->setupUi(this);
    lerri = error;
    lstate = state;
    lohjelma = ohjelma;
    lcardId = cardId;
    pInterface = new Interface;
    connect(pInterface, SIGNAL(sendNumberToExe(QString)), this, SLOT(recvNumberFunction(QString)));
}

scan::~scan()
{
    delete ui;
    disconnect(pInterface, SIGNAL(sendNumberToExe(QString)), this, SLOT(recvNumberFunction(QString)));
    delete pInterface;
    pInterface = nullptr;
}

void scan::recvNumberFunction(QString num){
    //if(checkCard(num)){
        *lcardId = num;
        *lstate = pinS;
        qDebug() << num;
    //}
}

void scan::errorLabelFiller(QString dText){
    ui->errorLabel->setText(dText);
    lohjelma->processEvents();  //makes QT do stuff... bad code on my part
}

void scan::doScan(){
    this->show();
    errorLabelFiller(*lerri);
    QThread::sleep(2);
    *lerri="Ei virheitä :-D";
    *lstate = 99;
    while(*lstate == 99){
        errorLabelFiller(*lerri);
        QThread::msleep(14);
    }
    this->close();
}
