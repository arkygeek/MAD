#-------------------------------------------------
#
# Project created by QtCreator 2013-05-01T17:55:32
#
#-------------------------------------------------

QT       +=  xml
CONFIG   += release
macx {
     QMAKE_INFO_PLIST = Info.plist
     ICON = mad.icns
}
lessThan(QT_MAJOR_VERSION, 5): QT += webkit core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = MacsurAdapter
TEMPLATE = app


SOURCES += main.cpp\
        madmainwindow.cpp \
    lib/madmodel.cpp \
    lib/madutils.cpp \
    gui/maddataclassification.cpp \
    lib/maddata.cpp \
    lib/madserialisable.cpp \
    lib/madguid.cpp \
    gui/madtextdisplayform.cpp \
    lib/dataclassification/madsubcategory.cpp \
    lib/dataclassification/statevars/madstatevars.cpp \
    lib/dataclassification/statevars/madsvsoil.cpp \
    lib/dataclassification/statevars/madsvcrop.cpp \
    lib/dataclassification/statevars/madsvsurfacefluxes.cpp \
    lib/dataclassification/statevars/madsvobservations.cpp \
    lib/dataclassification/maddataclassificationmanagement.cpp \
    lib/dataclassification/maddataclassificationphenology.cpp \
    lib/dataclassification/maddataclassificationprevcrop.cpp \
    lib/dataclassification/maddataclassificationinitialvalues.cpp \
    lib/dataclassification/maddataclassificationsoil.cpp \
    lib/dataclassification/maddataclassificationsitedata.cpp \
    lib/dataclassification/maddataclassificationweather.cpp \
    lib/maddataset.cpp \
    gui/madlogindialog.cpp \
    gui/madvariablemanager.cpp \
    gui/madcsvreader.cpp \
    gui/madmodelmanager.cpp \
    lib/madscenario.cpp



HEADERS  += madmainwindow.h \
    lib/madmodel.h \
    lib/mad.h \
    lib/madutils.h \
    gui/maddataclassification.h \
    lib/madversion.h \
    lib/maddata.h \
    lib/madserialisable.h \
    lib/madguid.h \
    gui/madtextdisplayform.h \
    lib/dataclassification/madsubcategory.h \
    lib/dataclassification/statevars/madstatevars.h \
    lib/dataclassification/statevars/madsvcrop.h \
    lib/dataclassification/statevars/madsvsoil.h \
    lib/dataclassification/statevars/madsvsurfacefluxes.h \
    lib/dataclassification/statevars/madsvobservations.h \
    lib/dataclassification/maddataclassificationmanagement.h \
    lib/dataclassification/maddataclassificationphenology.h \
    lib/dataclassification/maddataclassificationprevcrop.h \
    lib/dataclassification/maddataclassificationinitialvalues.h \
    lib/dataclassification/maddataclassificationsoil.h \
    lib/dataclassification/maddataclassificationsitedata.h \
    lib/dataclassification/maddataclassificationweather.h \
    lib/maddataset.h \
    gui/madlogindialog.h \
    gui/madvariablemanager.h \
    gui/madcsvreader.h \
    gui/madmodelmanager.h \
    lib/overloads.h \
    lib/madscenario.h


FORMS    += madmainwindowbase.ui \
    gui/maddataclassificationbase.ui \
    gui/madtextdisplayformbase.ui \
    gui/madvariablemanagerbase.ui \
    gui/madcsvreaderbase.ui \
    gui/madmodelmanagerbase.ui

RESOURCES += \
    resources/resources.qrc

OTHER_FILES += \
    resources/about.txt \
    resources/cropm.txt \
    resources/livem.txt \
    resources/tradem.txt \
    README.txt \
    CMakeLists.txt \
    notes.txt \
    CMake/Modules/FindQxt.cmake
