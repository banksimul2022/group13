#include "tili.h"
#include "ui_tili.h"

tili::tili(QWidget *parent, QString* error, int* state, QApplication* ohjelma) : QWidget(parent), ui(new Ui::tili){
    ui->setupUi(this);

    lerri = error;
    lstate = state;
    lohjelma = ohjelma;
}

tili::~tili()
{
    delete ui;
}

void tili::doTili(){
    this->show();
    lohjelma->processEvents();
    *lstate = fatalE;
    *lerri = "fatal exit from tili";
    lohjelma->processEvents();
    QThread::sleep(4);
    lohjelma->processEvents();
    this->close();
}

void tili::on_logoutPushButton_clicked()
{
    *lstate = noticeE;
    *lerri = "basic logout exit";
}

