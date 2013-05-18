I am attempting to keep this project fully compatible across all major platforms, and to build with both qmake and cmake.
I hope to also get it working with XCode, but we will have to see about that.
Qt Creator is ok, but there are some features I miss in XCode.  Also lots I miss in KDevelop.


In order to do this, everytime a new file is added, CMakeLists.txt needs to be updated.

Specifically, these:

set ( MacsurAdapter_HDRS
set ( MacsurAdapter_SRCS
set ( MacsurAdapter_UIS

set ( MacsurAdapter_MOCS

the last one is not as straight forward.  put the header file for the
files that have forms (.ui)

Example:

set ( MacsurAdapter_MOCS
        madmainwindow.h
        gui/maddataclassification.h
        gui/madtextdisplayform.h
        )
