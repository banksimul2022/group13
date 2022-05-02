#ifndef SCAN_H
#define SCAN_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include "enumi.h"
#include "interface.h"

namespace Ui {
class scan;
}

class scan : public QWidget
{
    Q_OBJECT

public:
    explicit scan(QWidget *parent = nullptr, QString* erri = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr, QString* cardId = nullptr);
    ~scan();
    void doScan();
    void errorLabelFiller(QString);

public slots:
    void recvNumberFunction(QString);

private:
    Ui::scan *ui;
    QString* lerri;
    int* lstate;
    QApplication* lohjelma;
    QString* lcardId;
    Interface* pInterface;
};

#endif // SCAN_H
