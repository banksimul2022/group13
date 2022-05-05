#include "engine.h"
#include "ui_engine.h"
#include "enumi.h"

engine::engine(QWidget *parent, QString* error, int* state, QApplication* ohjelma, char* pn, int krtid) :
    QDialog(parent),
    ui(new Ui::engine)
{
    ui->setupUi(this);
    lerror = error;
    lstate = state;
    lohjelma = ohjelma;
    pinn = pn;
    pn[0]=0; pn[1]=0; pn[2]=0; pn[3]=0;
    lkrtid = krtid;
}

engine::~engine()
{
    delete ui;
}

void engine::doPin()
{
    *lstate = 99;
    this->show();
    while(*lstate==99){
        lohjelma->processEvents();
        QThread::msleep(15);
    }
    this->close();
}

void engine::on_Enter_clicked()
{
    *lstate = pinS;
}


void engine::on_pushButton_1_clicked()
{
    addToPin(48+1);
}


void engine::on_pushButton_2_clicked()
{
    addToPin(48+2);
}


void engine::on_pushButton_3_clicked()
{
    addToPin(48+3);
}


void engine::on_pushButton_4_clicked()
{
    addToPin(48+4);
}


void engine::on_pushButton_5_clicked()
{
    addToPin(48+5);
}


void engine::on_pushButton_6_clicked()
{
    addToPin(48+6);
}


void engine::on_pushButton_7_clicked()
{
    addToPin(48+7);
}


void engine::on_pushButton_8_clicked()
{
    addToPin(48+8);
}


void engine::on_pushButton_9_clicked()
{
    addToPin(48+9);
}


void engine::on_pushButton_exit_clicked()
{
    *lstate = noticeE;
    *lerror = "normal exit from pinUI";
}

void engine::addToPin(int num)
{
    if (pinno < 4){
        pinn[pinno]=num;
        pinno++;
    }
    stars = "";
    for(int i=0; i<pinno; i++){
        stars.append("*");
    }
    ui->label->setText(stars);

}

