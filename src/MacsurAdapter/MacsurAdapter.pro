#-------------------------------------------------
#
# Project created by QtCreator 2013-05-01T17:55:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacsurAdapter
TEMPLATE = app


SOURCES += main.cpp\
        madmainwindow.cpp \
    lib/madmodel.cpp

HEADERS  += madmainwindow.h \
    lib/madmodel.h \
    lib/mad.h \
    lib/version.h

FORMS    += madmainwindowbase.ui
