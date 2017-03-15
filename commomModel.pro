#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T15:34:07
#
#-------------------------------------------------

QT       -= gui

TARGET = commonModel
TEMPLATE = lib

DEFINES += COMMOMMODEL_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    commonmodel/commommodel_global.h \
    commonmodel/functions/function.h \
    commonmodel/functions/functionset.h \
    commonmodel/functions/heatfunction.h \
    commonmodel/functions/lightfunction.h \
    commonmodel/functions/measureodfunction.h \
    commonmodel/functions/pumppluginfunction.h \
    commonmodel/functions/stirfunction.h \
    commonmodel/functions/valvepluginroutefunction.h \
    commonmodel/mappinginterface/mappinginterface.h \
    commonmodel/modelinterface/componentinterface.h \
    commonmodel/modelinterface/modelinterface.h \
    commonmodel/plugininterface/heaterpluginproduct.h \
    commonmodel/plugininterface/lightpluginproduct.h \
    commonmodel/plugininterface/odsensorpluginproduct.h \
    commonmodel/plugininterface/pluginabstractfactory.h \
    commonmodel/plugininterface/pluginconfiguration.h \
    commonmodel/plugininterface/pumppluginproduct.h \
    commonmodel/plugininterface/stirerpluginproduct.h \
    commonmodel/plugininterface/valvepluginproduct.h

SOURCES += \
    commonmodel/functions/functionset.cpp \
    commonmodel/functions/heatfunction.cpp \
    commonmodel/functions/lightfunction.cpp \
    commonmodel/functions/measureodfunction.cpp \
    commonmodel/functions/pumppluginfunction.cpp \
    commonmodel/functions/stirfunction.cpp \
    commonmodel/functions/valvepluginroutefunction.cpp \
    commonmodel/plugininterface/pluginconfiguration.cpp

debug {
    QMAKE_POST_LINK=X:\commomModel\commomModel\setDLL.bat $$shell_path($$OUT_PWD/debug) debug

    INCLUDEPATH += X:\utils\dll_debug\include
    LIBS += -L$$quote(X:\utils\dll_debug\bin) -lutils

    INCLUDEPATH += X:\protocolGraph\dll_debug\include
    LIBS += -L$$quote(X:\protocolGraph\dll_debug\bin) -lutils
}

!debug {
    QMAKE_POST_LINK=X:\commomModel\commomModel\setDLL.bat $$shell_path($$OUT_PWD/release) release

    INCLUDEPATH += X:\utils\dll_release\include
    LIBS += -L$$quote(X:\utils\dll_release\bin) -lutils

    INCLUDEPATH += X:\protocolGraph\dll_release\include
    LIBS += -L$$quote(X:\protocolGraph\dll_release\bin) -lutils
}

INCLUDEPATH += X:\libraries\cereal-1.2.2\include
