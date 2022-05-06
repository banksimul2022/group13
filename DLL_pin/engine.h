#ifndef ENGINE_H
#define ENGINE_H

#include <QDialog>
#include <QThread>

namespace Ui {
class engine;
}

class engine : public QDialog
{
    Q_OBJECT

public:
    explicit engine(QWidget *parent = nullptr, QString* error = nullptr, int* state = nullptr, QApplication* ohjelma = nullptr, char* pn = nullptr, int krtid = 0);

    char* pinn;
    ~engine();
    void doPin();

private slots:
    void on_Enter_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::engine *ui;
//    char* pinn;
    int pinno=0;
    QString stars = "";
    void addToPin(int);

    QString* lerror;
    int* lstate;
    QApplication* lohjelma;
    int lkrtid;

};

#endif // ENGINE_H
