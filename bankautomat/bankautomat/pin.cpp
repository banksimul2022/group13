#include "pin.h"
#include "ui_pin.h"

pin::pin(QWidget *parent, QString* error, int* state, QApplication* ohjelma) :
    QWidget(parent),
    ui(new Ui::pin)
{
    ui->setupUi(this);
    lerri = error;
    lstate = state;
    lohjelma = ohjelma;
}

pin::~pin()
{
    delete ui;
}

void pin::doPin(){
    this->show();
    *lstate = tiliS;
    QThread::sleep(4);
    this->close();
}
