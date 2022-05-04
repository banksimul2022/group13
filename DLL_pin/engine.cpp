#include "engine.h"
#include "ui_engine.h"

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
    *lstate = 1;

}


void engine::on_pushButton_1_clicked()
{
    addToPin(1);
}


void engine::on_pushButton_2_clicked()
{
    addToPin(2);
}


void engine::on_pushButton_3_clicked()
{
    addToPin(3);
}


void engine::on_pushButton_4_clicked()
{
    addToPin(4);
}


void engine::on_pushButton_5_clicked()
{
    addToPin(5);
}


void engine::on_pushButton_6_clicked()
{
    addToPin(6);
}


void engine::on_pushButton_7_clicked()
{
    addToPin(7);
}


void engine::on_pushButton_8_clicked()
{
    addToPin(8);
}


void engine::on_pushButton_9_clicked()
{
    addToPin(9);
}


void engine::on_pushButton_exit_clicked()
{
    *lstate = 3;
}

void engine::addToPin(int num)
{
    if (pinno!=4){
        pinn[pinno]=num;
        pinno++;
    }
    QString tahti;
    for(int i=0; i<pinno; i++){
        tahti.append("*");
    }
    ui->label->setText(tahti);

}

