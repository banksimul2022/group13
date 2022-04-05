#include "scan.h"
#include "ui_scan.h"

scan::scan(QWidget *parent, QString* error, int* state, QApplication* ohjelma) :
    QWidget(parent),
    ui(new Ui::scan)
{
    ui->setupUi(this);
    lerri = error;
    lstate = state;
    lohjelma = ohjelma;
}

scan::~scan()
{
    delete ui;
}

void scan::errorLabelFiller(QString dText){
    ui->errorLabel->setText(dText);
    lohjelma->processEvents();
}

void scan::doScan(){
    this->show();
    errorLabelFiller(*lerri);
    QThread::sleep(2);
    *lstate = pinS;
    errorLabelFiller("Ei virheitä :–D");
    QThread::sleep(2);
    this->close();
}
