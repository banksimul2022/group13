#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QThread>
//global vars for our things
bool stop=false;
//char state=kortti;
//active window
//active ui

//comon window/ui functions
void spawnWindow(){//malloc and spawn window with the related gui
}
void butcherWindow(){//dealloc a window and it's internal things
}

//restapi access
void restHandler(int op, QString path){//op=operation, [0get,1push,2put,3delete]
       qDebug() << op << path;
}

//signal slot thingy??? or my blocking latch/bus setup
void rfidHandler(){
}



//state machine functions
enum states{kortti, pin, tili};
int state=kortti;
void exit(QString msg, char msgType, bool kill){
    qDebug() << kill << ' ' << msgType << ' ' << state << ' ' << '\t' << msg;
    stop = kill;
	state = kortti;
}
void sfKortti(){
    MainWindow w;
    w.show();
    state = pin;
    QThread::sleep(1);
    w.close();
}
void sfPin(){
	//PinWindow w;
	//w.show();
    state = tili;
	//w.close();
}
void sfTili(){
	//TiliWindow w;
	//w.show();
    //state = kortti;
    state = 48;
    //w.close();
}

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
    while(!stop){
        qDebug() << state;
        switch(state){
			case kortti :
				sfKortti();
				break;
			case pin :
				sfPin();
				break;
			case tili :
				sfTili();
				break;
			default :
                exit("state non existent", 'f', true);
		}
	}
	return a.exec();
}
