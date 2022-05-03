#include "pin.h"
#include "ui_pin.h"

pin::pin(QWidget *parent, QString* error, int* state, QApplication* ohjelma, char* pn, int krtid) :
    QWidget(parent),
    ui(new Ui::pin)
{
    ui->setupUi(this);
    lerri = error;
    lstate = state;
    lohjelma = ohjelma;
    lpinNums = pn;
    pn[0]=0; pn[1]=0; pn[2]=0; pn[3]=0;
    lkrtid = krtid;
    nwa = new interface_rst(this);
}

pin::~pin()
{
    delete ui;
    delete nwa;
}

void pin::doPin(){
    *lstate=99;  //invalid state that we will change in the next loop
    this->show();//make window with the ui
    while(*lstate==99){
        lohjelma->processEvents();
        QThread::msleep(15);//waiting a bit prevents the application form using all of our cpu. this is the simple way of doing this. better way could be to wait until anything happens and then processing events
        lohjelma->processEvents();//this looks at the slots and processes their events thus it might change our state and cause an exit from this loop
    }
    this->close();//close our window
}

//controll buttons
void pin::on_exitButton_clicked(){
    *lerri = "basic exit from pin ui";
    *lstate = noticeE;
    nwb=false;
}
void pin::on_backButton_clicked(){
    pinNumRem();
}
void pin::on_okButton_clicked(){
    if(testPin()){
        *lstate = tiliS;
    }
}

//number buttons
void pin::on_zeroButton_clicked(){  pinNumAdd(48+0);}
void pin::on_oneButton_clicked(){   pinNumAdd(48+1);}
void pin::on_twoButton_clicked(){   pinNumAdd(48+2);}
void pin::on_threeButton_clicked(){ pinNumAdd(48+3);}
void pin::on_fourButton_clicked(){  pinNumAdd(48+4);}
void pin::on_fiveButton_clicked(){  pinNumAdd(48+5);}
void pin::on_sixButton_clicked(){   pinNumAdd(48+6);}
void pin::on_sevenButton_clicked(){ pinNumAdd(48+7);}
void pin::on_eightButton_clicked(){ pinNumAdd(48+8);}
void pin::on_nineButton_clicked(){  pinNumAdd(48+9);}

void pin::gotKortti(){
    nwb=false;
    std::cout << "gks" << std::endl;
}

//pin helper functions
bool pin::testPin(){
    bool ret = false;
    //QString krt = "/kortti/";
    //krt.append(*lkrtid);
    QString krt =QString ("/kortti/%1").arg(lkrtid);
    nwa->setUrlEnd(krt);
    nwa->doGet();
    connect(nwa, SIGNAL(gotData), this, SLOT(gotKortti));
    nwb = true;
    while(nwb){//wait for network to reply
        QThread::msleep(15);
        lohjelma->processEvents();
    }
    disconnect(nwa, SIGNAL(gotData), this, SLOT(gotKortti));
    //process json
    int rkrtid = 0;
    QJsonArray json_array = nwa->getJson().array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        //rkrtid=QString::number(json_obj["idkortti"].toInt()).toInt();
        rkrtid=QString::number(json_obj["pin"].toInt()).toInt();
    }
    std::cout << rkrtid << ":" << QString::fromUtf8(lpinNums, 4).toInt() << std::endl;
    if(QString::fromUtf8(lpinNums, 4).toInt() == rkrtid){
        ret = true;
    }
    std::cout << ret << nwa->getJson().toJson().toStdString() << std::endl;
    return ret;
}

void pin::pinNumAdd(int num){
    if(pinOffset < 4){
        lpinNums[pinOffset] = num;
        pinOffset++;
    }
    modPinDisp();
}
void pin::pinNumRem(){
    if(pinOffset > 0){
        pinOffset--;
    }
    lpinNums[pinOffset] = 0;
    modPinDisp();
}

//ui modification functions
void pin::modPinDisp(){
    int tmpint = 0;
    for(int i = 0; i < 4; i++){
        //get the number
        int gn = lpinNums[i] - 48;
        if (gn >= 0 && gn <= 9){
            tmpint = tmpint*10+gn;
        }
    }
    ui->pinLcdNumber->display(tmpint);
}
