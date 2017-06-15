#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T08:31:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET =  ACOAlgorithmus
TEMPLATE = app


SOURCES += Main.cpp\
    Gui/AntGraphic.cpp \
    Gui/BerryGraphic.cpp \
    Gui/StickGraphic.cpp \
    Gui/TreeGraphic.cpp \
    Data/Ant.cpp \
    Gui/MainWindow.cpp \
    Logic/MainApplication.cpp

HEADERS  += \
    Gui/AntGraphic.h \
    Gui/BerryGraphic.h \
    Gui/StickGraphic.h \
    Gui/TreeGraphic.h \
    Data/Ant.h \
    Gui/MainWindow.h \
    Logic/MainApplication.h

FORMS    +=

RESOURCES += \
    externpicutures.qrc

