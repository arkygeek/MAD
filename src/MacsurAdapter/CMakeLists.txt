project( MacsurAdapter )
cmake_minimum_required( VERSION 2.6 )
# The following line will add additional finders to CMake without the need to be placed in the CMake install path
LIST (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

set ( CMAKE_BUILD_TYPE Release )
set ( QT_USE_QTWEBKIT TRUE )

add_definitions ( -Wall )
find_package ( Qt4 REQUIRED )

include ( ${QT_USE_FILE} )

include_directories (
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${QT_QTCORE_INCLUDE_DIR}
        ${QT_QTGUI_INCLUDE_DIR}
        ${QT_QTCORE_INCLUDE_DIR}
        ${QT_QTGUI_INCLUDE_DIR}
        ${QT_QTXML_INCLUDE_DIR}
        ${QT_QTWEBKIT_INCLUDE_DIR}
        )

set ( MacsurAdapter_HDRS
        lib/madmodel.h
        lib/mad.h
        lib/madutils.h
        lib/madversion.h
        lib/maddata.h
        lib/madserialisable.h
        lib/madguid.h
        lib/maddataset.h
        lib/dataclassification/madsubcategory.h
        lib/dataclassification/maddataclassificationmanagement.h
        lib/dataclassification/maddataclassificationinitialvalues.h
        lib/dataclassification/maddataclassificationphenology.h
        lib/dataclassification/maddataclassificationprevcrop.h
        lib/dataclassification/maddataclassificationsitedata.h
        lib/dataclassification/maddataclassificationsoil.h
        lib/dataclassification/maddataclassificationweather.h
        lib/dataclassification/statevars/madstatevars.h
        lib/dataclassification/statevars/madsvcrop.h
        lib/dataclassification/statevars/madsvobservations.h
        lib/dataclassification/statevars/madsvsoil.h
        lib/dataclassification/statevars/madsvsurfacefluxes.h
        gui/madtextdisplayform.h
        gui/maddataclassification.h
        gui/madlogindialog.h
        gui/madvariablemanager.h
        )

set ( MacsurAdapter_SRCS
        main.cpp
        madmainwindow.cpp
        lib/madmodel.cpp
        lib/madutils.cpp
        lib/maddata.cpp
        lib/madserialisable.cpp
        lib/madguid.cpp
        lib/maddataset.cpp
        lib/dataclassification/madsubcategory.cpp
        lib/dataclassification/maddataclassificationmanagement.cpp
        lib/dataclassification/maddataclassificationinitialvalues.cpp
        lib/dataclassification/maddataclassificationphenology.cpp
        lib/dataclassification/maddataclassificationprevcrop.cpp
        lib/dataclassification/maddataclassificationsitedata.cpp
        lib/dataclassification/maddataclassificationsoil.cpp
        lib/dataclassification/maddataclassificationweather.cpp
        lib/dataclassification/statevars/madstatevars.cpp
        lib/dataclassification/statevars/madsvcrop.cpp
        lib/dataclassification/statevars/madsvobservations.cpp
        lib/dataclassification/statevars/madsvsoil.cpp
        lib/dataclassification/statevars/madsvsurfacefluxes.cpp
        gui/maddataclassification.cpp
        gui/madtextdisplayform.cpp
        gui/maddataclassification.cpp
        gui/madlogindialog.cpp
        gui/madvariablemanager.cpp
        )

set ( MacsurAdapter_UIS
        madmainwindowbase.ui
        gui/maddataclassificationbase.ui
        gui/madtextdisplayformbase.ui
        gui/madvariablemanagerbase.ui
        )
QT4_WRAP_UI(UIS ${MacsurAdapter_UIS})

set ( MacsurAdapter_RSCS
        resources/resources.qrc
        )
QT4_ADD_RESOURCES(RSCS ${MacsurAdapter_RSCS})

set ( MacsurAdapter_MOCS
        madmainwindow.h
        gui/maddataclassification.h
        gui/madtextdisplayform.h
        gui/madvariablemanager.h
        gui/madlogindialog.h
        )
QT4_WRAP_CPP(MOCS ${MacsurAdapter_MOCS})

add_executable (
                 MacsurAdapter
                ${MacsurAdapter_SRCS}
                ${UIS}
                ${RSCS}
                ${TRS}
                ${MOCS}
               )
target_link_libraries (
                        MacsurAdapter
                        ${QT_QTCORE_LIBRARY}
                        ${QT_QTGUI_LIBRARY}
                        ${QT_QTCORE_LIBRARY}
                        ${QT_QTGUI_LIBRARY}
                        ${QT_QTXML_LIBRARY}
                        ${QT_QTWEBKIT_LIBRARY}
                      )

