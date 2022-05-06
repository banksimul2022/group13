QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 qtc_runnable

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    pin.cpp \
    scan.cpp \
    tilakone.cpp \
    tili.cpp

HEADERS += \
    enumi.h \
    pin.h \
    scan.h \
    tilakone.h \
    tili.h

FORMS += \
    pin.ui \
    scan.ui \
    tili.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-DLL_rest-Desktop-Debug/release/ -lDLL_rest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-DLL_rest-Desktop-Debug/debug/ -lDLL_rest
else:unix:!macx: LIBS += -L$$PWD/../../build-DLL_rest-Desktop-Debug/ -lDLL_rest

INCLUDEPATH += $$PWD/../../DLL_rest
DEPENDPATH += $$PWD/../../DLL_rest

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../DLL_RFID/build-DLL_RFID-Desktop-Debug/release/ -lDLL_RFID
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../DLL_RFID/build-DLL_RFID-Desktop-Debug/debug/ -lDLL_RFID
else:unix:!macx: LIBS += -L$$PWD/../../DLL_RFID/build-DLL_RFID-Desktop-Debug/ -lDLL_RFID

INCLUDEPATH += $$PWD/../../DLL_RFID/DLL_RFID
DEPENDPATH += $$PWD/../../DLL_RFID/DLL_RFID

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-interface-Desktop-Debug/release/ -linterface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-interface-Desktop-Debug/debug/ -linterface
else:unix:!macx: LIBS += -L$$PWD/../../build-interface-Desktop-Debug/ -linterface

INCLUDEPATH += $$PWD/../../DLL_pin
DEPENDPATH += $$PWD/../../DLL_pin
