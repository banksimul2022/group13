//#include "mainwindow.h"
#include <QApplication>
#include "tilakone.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    tilakone tk(&a);
    tk.start();
    return a.exec();
}
