#ifndef TILI_H
#define TILI_H

#include <QWidget>
#include <QThread>
#include "enumi.h"

namespace Ui {
class tili;
}

class tili : public QWidget
{
    Q_OBJECT

public:
    explicit tili(QWidget *parent = nullptr, QString* erri = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr);
    ~tili();
    void doTili();

private slots:
    void on_logoutPushButton_clicked();

private:
    Ui::tili *ui;
    QString* lerri;
    int* lstate;
    QApplication* lohjelma;
};

#endif // TILI_H
