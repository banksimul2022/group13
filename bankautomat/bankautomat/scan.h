#ifndef SCAN_H
#define SCAN_H

#include <QWidget>
#include <QThread>
#include "enumi.h"

namespace Ui {
class scan;
}

class scan : public QWidget
{
    Q_OBJECT

public:
    explicit scan(QWidget *parent = nullptr, QString* erri = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr);
    ~scan();
    void doScan();
    void errorLabelFiller(QString);

private:
    Ui::scan *ui;
    QString* lerri;
    int* lstate;
    QApplication* lohjelma;
};

#endif // SCAN_H
