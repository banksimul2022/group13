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

unix:!macx|win32: LIBS += -L$$PWD/../../DLL_RFID/build-DLL_RFID-Desktop-Debug/ -lDLL_RFID
INCLUDEPATH += $$PWD/../../DLL_RFID/DLL_RFID
DEPENDPATH += $$PWD/../../DLL_RFID/build-DLL_RFID-Desktop-Debug

unix:!macx|win32: LIBS += -L$$PWD/../../../poista/group13/build-DLL_rest-Desktop-Debug/ -lDLL_rest
INCLUDEPATH += $$PWD/../../../poista/group13/DLL_rest
DEPENDPATH += $$PWD/../../../poista/group13/build-DLL_rest-Desktop-Debug
