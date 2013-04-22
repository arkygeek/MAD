#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T11:30:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacsurAdapter
TEMPLATE = app


SOURCES += main.cpp\
        gui/mamainform.cpp \

HEADERS  += gui/mamainform.h \

FORMS    += ui/mamainformbase.ui \

OTHER_FILES += \
    settings.pro \
    docs/codingStandards.pdf

RESOURCES += \
    resources/macsuradapter.qrc
