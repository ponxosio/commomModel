#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T15:34:07
#
#-------------------------------------------------

QT       -= gui

TARGET = commomModel
TEMPLATE = lib

DEFINES += COMMOMMODEL_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    commonmodel/commommodel.h \
    commonmodel/commommodel_global.h

SOURCES += \
    commonmodel/commommodel.cpp

