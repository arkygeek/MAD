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
        mamainform.cpp \
    maaddmodel.cpp \
    mafileparser.cpp

HEADERS  += mamainform.h \
    maaddmodel.h \
    mafileparser.h

FORMS    += mamainform.ui \
    maaddmodel.ui \
    mafileparser.ui

OTHER_FILES += \
    settings.pro \
    codingStandards.pdf

RESOURCES += \
    macsuradapter.qrc
