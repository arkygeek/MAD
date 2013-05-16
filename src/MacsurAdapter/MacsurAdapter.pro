#-------------------------------------------------
#
# Project created by QtCreator 2013-05-01T17:55:32
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacsurAdapter
TEMPLATE = app


SOURCES += main.cpp\
        madmainwindow.cpp \
    lib/madmodel.cpp \
    lib/madutils.cpp \
    gui/maddataclassification.cpp \
    lib/maddata.cpp \
    lib/madserialisable.cpp \
    lib/madguid.cpp

HEADERS  += madmainwindow.h \
    lib/madmodel.h \
    lib/mad.h \
    lib/madutils.h \
    gui/maddataclassification.h \
    lib/madversion.h \
    lib/maddata.h \
    lib/madserialisable.h \
    lib/madguid.h

FORMS    += madmainwindowbase.ui \
    gui/maddataclassificationbase.ui \

RESOURCES += \
    resources/resources.qrc

OTHER_FILES += \
    resources/about.txt \
    resources/cropm.txt \
    resources/livem.txt \
    resources/tradem.txt
