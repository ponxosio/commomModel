#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T15:34:07
#
#-------------------------------------------------

#ensure one "debug_and_release" in CONFIG, for clarity...
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
    # ensure one "debug" or "release" in CONFIG so they can be used as
    #   conditionals instead of writing "CONFIG(debug, debug|release)"...
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
}


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
    commonmodel/plugininterface/valvepluginproduct.h \
    commonmodel/functions/measuretemperaturefunction.h \
    commonmodel/plugininterface/temperaturesensorproduct.h \
    commonmodel/functions/measureluminiscencefunction.h \
    commonmodel/plugininterface/luminiscencesensorproduct.h \
    commonmodel/plugininterface/fluorescencesensorproduct.h \
    commonmodel/functions/measurefluorescencefunction.h \
    commonmodel/plugininterface/volumesensorproduct.h \
    commonmodel/functions/measurevolumefunction.h \
    commonmodel/plugininterface/shakepluginproduct.h \
    commonmodel/plugininterface/centrifugatepluginproduct.h \
    commonmodel/functions/centrifugatefunction.h \
    commonmodel/functions/shakefunction.h \
    commonmodel/plugininterface/electrophoresispluginproduct.h \
    commonmodel/functions/electrophoresisfunction.h \
    commonmodel/functions/ranges/centrifugationworkingrange.h \
    commonmodel/functions/ranges/comparablerangeinterface.h \
    commonmodel/functions/ranges/electrophoresisworkingrange.h \
    commonmodel/functions/ranges/heaterworkingrange.h \
    commonmodel/functions/ranges/ligthworkingrange.h \
    commonmodel/functions/ranges/emptyworkingrange.h \
    commonmodel/functions/ranges/measurefluorescenceworkingrange.h \
    commonmodel/functions/ranges/measureodworkingrange.h \
    commonmodel/functions/ranges/pumpworkingrange.h \
    commonmodel/functions/ranges/shakeworkingrange.h \
    commonmodel/functions/ranges/stirworkingrange.h

SOURCES += \
    commonmodel/functions/functionset.cpp \
    commonmodel/functions/heatfunction.cpp \
    commonmodel/functions/lightfunction.cpp \
    commonmodel/functions/measureodfunction.cpp \
    commonmodel/functions/pumppluginfunction.cpp \
    commonmodel/functions/stirfunction.cpp \
    commonmodel/functions/valvepluginroutefunction.cpp \
    commonmodel/plugininterface/pluginconfiguration.cpp \
    commonmodel/functions/measuretemperaturefunction.cpp \
    commonmodel/functions/measureluminiscencefunction.cpp \
    commonmodel/functions/measurefluorescencefunction.cpp \
    commonmodel/functions/measurevolumefunction.cpp \
    commonmodel/functions/centrifugatefunction.cpp \
    commonmodel/functions/shakefunction.cpp \
    commonmodel/functions/electrophoresisfunction.cpp \
    commonmodel/functions/ranges/centrifugationworkingrange.cpp \
    commonmodel/functions/ranges/electrophoresisworkingrange.cpp \
    commonmodel/functions/ranges/heaterworkingrange.cpp \
    commonmodel/functions/ranges/ligthworkingrange.cpp \
    commonmodel/functions/ranges/emptyworkingrange.cpp \
    commonmodel/functions/ranges/measurefluorescenceworkingrange.cpp \
    commonmodel/functions/ranges/measureodworkingrange.cpp \
    commonmodel/functions/ranges/pumpworkingrange.cpp \
    commonmodel/functions/ranges/shakeworkingrange.cpp \
    commonmodel/functions/ranges/stirworkingrange.cpp

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
