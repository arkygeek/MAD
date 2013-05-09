/***************************************************************************
 *   File:  main.cpp created: 01/05/2013                                    *
 *   Class info:                                                *
 *   Copyright (C) 2013 by: Jason S. Jorgenson                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
//Qt includes
#include <QApplication>

/*  Local includes
 *
 ***********
 *  NOTE!  *
 **************************************************************
 *  you must specify the relative path if not located in src  *
 *  example:  #include "gui/theHeader.h"                    *
 **************************************************************/
#include "madmainwindow.h"
//#include "lib/madmodel.h"
//#include "lib/mad.h"
#include "lib/madversion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MadMainWindow w;
    w.show();
    
    return a.exec();
}


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
