#ifndef PIN_H
#define PIN_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include <iostream>
#include "enumi.h"
#include "interface_rst.h"

namespace Ui {
class pin;
}

class pin : public QWidget
{
    Q_OBJECT

public:
    explicit pin(QWidget *parent = nullptr, QString* erri = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr, char* pn = nullptr, int krtid = 0);
    //parental advisory
    ~pin();
    void doPin();

private slots:
    void on_exitButton_clicked();
    void on_backButton_clicked();
    void on_okButton_clicked();

    void on_zeroButton_clicked();
    void on_oneButton_clicked();
    void on_twoButton_clicked();
    void on_threeButton_clicked();
    void on_fourButton_clicked();
    void on_fiveButton_clicked();
    void on_sixButton_clicked();
    void on_sevenButton_clicked();
    void on_eightButton_clicked();
    void on_nineButton_clicked();

    void gotKortti();

private:
    bool testPin();
    void pinNumAdd(int);
    void pinNumRem();
    void modPinDisp();

    char* lpinNums;
    int lkrtid;
    bool nwb = false;//block while doing network access
    int pinOffset = 0;
    Ui::pin *ui;
    QString* lerri;
    int* lstate;
    QApplication* lohjelma;
    interface_rst* nwa;
};

#endif // PIN_H
