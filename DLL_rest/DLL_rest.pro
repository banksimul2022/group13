QT -= gui
QT += network


TEMPLATE = lib
DEFINES += DLL_REST_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    engine_rst.cpp \
    interface_rst.cpp

HEADERS += \
    DLL_rest_global.h \
    engine_rst.h \
    interface_rst.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS +=
