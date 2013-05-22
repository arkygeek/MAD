project( MacsurAdapter )
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt4 REQUIRED )
include ( ${QT_USE_FILE} )
include_directories (
        ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
        ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR}
        )
set ( MacsurAdapter_HDRS
        lib/madmodel.h
        lib/mad.h
        lib/madutils.h
        lib/madversion.h
        lib/maddata.h
        lib/madserialisable.h
        lib/madguid.h
        lib/dataclassification/madsubcategory.h
        lib/dataclassification/statevars/madstatevars.h
        lib/dataclassification/statevars/madsvcrop.h
        lib/dataclassification/statevars/madsvobservations.h
        lib/dataclassification/statevars/madsvsoil.h
        lib/dataclassification/statevars/madsvsurfacefluxes.h
        gui/madtextdisplayform.h
        gui/maddataclassification.h
        )

set ( MacsurAdapter_SRCS
        main.cpp
        madmainwindow.cpp
        lib/madmodel.cpp
        lib/madutils.cpp
        lib/maddata.cpp
        lib/madserialisable.cpp
        lib/madguid.cpp
        lib/dataclassification/madsubcategory.cpp
        lib/dataclassification/statevars/madstatevars.cpp
        lib/dataclassification/statevars/madsvcrop.cpp
        lib/dataclassification/statevars/madsvobservations.cpp
        lib/dataclassification/statevars/madsvsoil.cpp
        lib/dataclassification/statevars/madsvsurfacefluxes.cpp
        gui/maddataclassification.cpp
        gui/madtextdisplayform.cpp
        gui/maddataclassification.cpp
        )

set ( MacsurAdapter_UIS
        madmainwindowbase.ui
        gui/maddataclassificationbase.ui
        gui/madtextdisplayformbase.ui
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
        )
QT4_WRAP_CPP(MOCS ${MacsurAdapter_MOCS})

add_executable ( MacsurAdapter ${MacsurAdapter_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( MacsurAdapter  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} )

