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



/*
 * Some notes about code documentation and how to
 * effectively use regular comments and doxygen
 *
 * only document the interface in the header files:
 * don't talk about how the function does something,
 * tell only what it does.
 *
 * If you want to explain the actual implementation,
 * put some relevant (normal) comments in the source file.
 *
 * A starting place for Doxygen is here:
 * www.stack.nl/~dimitri/doxygen/manual/docblocks.html#cppblock
 *
 ***********************
 *  One thing to note  *
 *****************************************************************************
 * To document a member of a C++ class, you must also document the class     *
 * itself. The same holds for namespaces.                                    *
 *                                                                           *
 * To document a global C function, typedef, enum or preprocessor definition *
 * you must first document the file that contains it (usually this will be a *
 * header file, because that file contains the information that is exported  *
 * to other source files).                                                   *
 *                                                                           *
 * Let's repeat that, because it is often overlooked:                        *
 * to document global objects (functions, typedefs, enum, macros, etc),      *
 * you must document the file in which they are defined.                     *
 *                                                                           *
 * In other words, there must at least be a                                  *
 *  / * !   \ file  * /   or a  / **  @file  * /    line in this file.       *
 *                                                                           *
 *****************************************************************************
 *
 */
