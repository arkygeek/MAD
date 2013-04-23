#################################################################
#
#         QMAKE Project File for MACSUR Adapter Gui
#
#                      Tim Sutton 2005
#                 Jason Jorgenson 2007, 2013
#
#################################################################
# include global settings from the top level dir
include(../../settings.pro)
TEMPLATE = app
TARGET = macsuradapter
CONFIG(debug, debug|release){
    TARGET = $$member(TARGET, 0)-debug
}else{
    #needed for mac maybe make this macx: only?
    TARGET = $$member(TARGET,0)-release
}
#LIBS += $${OMGLIBADD}
#LIBS += $${OMGWIDGETSLIBADD}
#this gets nullified by settings.pro if we arent building with ws support
#win32:LIBS += $${EXPATLIBADD}
#macx:LIBS += $${GDALLIBADD}
#LIBS +=$${QGISLIBADD}

# We dont specify the bin dir for the mac since
# the application bundle is made for us
linux-g: DESTDIR = $${BINDIR}
# for icon file under windows
# see http://www.qiliang.net/qt/appicon.html
#1
#win32: RC_FILE = ../../win/macsuradapter.rc
#macx: ICON = ../../mac/Resources/macsuradapter.icns
message("Building $${TARGET} (exe) into $${DESTDIR}")

RESOURCES = ../resources/macsuradapter.qrc

#QT += network
QT += gui core

#INCLUDEPATH += ../lib
#################################################################

FORMS += mamainformbase.ui \

HEADERS += mamainform.h \

SOURCES += main.cpp \
           mamainform.cpp \

CONFIG += warn_on



