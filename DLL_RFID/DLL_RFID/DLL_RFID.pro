QT -= gui
QT += serialport


TEMPLATE = lib
DEFINES += DLL_RFID_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    engine_rfd.cpp \
    interface_rfd.cpp

HEADERS += \
    DLL_RFID_global.h \
    engine_rfd.h \
    interface_rfd.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS +=
