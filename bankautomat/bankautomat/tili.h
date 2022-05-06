#ifndef TILI_H
#define TILI_H

#include <QWidget>
#include <QThread>
#include "enumi.h"
#include "interface_rst.h"

namespace Ui {
class tili;
}

class tili : public QWidget
{
    Q_OBJECT

public:
    explicit tili(QWidget *parent = nullptr, QString* erri = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr, int cardId = 0);
    ~tili();
    void doTili();

private slots:
    void on_logoutPushButton_clicked();
    void on_nosta1PushButton_clicked();
    void on_laita1PushButton_clicked();
    void requestReady();

private:
    Ui::tili *ui;
    QString* lerri;
    int* lstate;
    QApplication* lohjelma;
    int kortti;
    int tiliId;
    int saldo;
    void initializeTiliData();
    void updateTiliData();
    bool nwb = false;
    void newTapahtuma(QString, int);
    void updateTapahtuma();
};

#endif // TILI_H
