#ifndef PIN_H
#define PIN_H

#include <QWidget>
#include <QThread>
#include "enumi.h"

namespace Ui {
class pin;
}

class pin : public QWidget
{
    Q_OBJECT

public:
    explicit pin(QWidget *parent = nullptr, QString* erri = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr);
    ~pin();
    void doPin();

private:
    Ui::pin *ui;
    QString* lerri;
    int* lstate;
    QApplication* lohjelma;
};

#endif // PIN_H
