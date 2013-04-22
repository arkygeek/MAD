/***************************************************************************
 *   File:  main.cpp created: 27/3/2013                                    *
 *   Class info:                                                           *
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

#include <QApplication>
#include <QFile>
#include "mamainform.h"

int main(int argc, char *argv[])
{
    QApplication myApp(argc, argv);

    //NOTE: make sure these lines stay after myApp init above
    QCoreApplication::setOrganizationName("macsur.eu");
    QCoreApplication::setOrganizationDomain("macsur-adapter.macsur.eu");
    QCoreApplication::setApplicationName("MacsurAdapter");

    //MaMainForm w;
    //w.show();

#ifdef Q_OS_MACX
    // Install OpenDocuments AppleEvent handler after application object is initialized
    // but before any other event handling (including dialogs or splash screens) occurs.
    // If an OpenDocuments event has been created before the application was launched,
    // it must be handled before some other event handler runs and dismisses it as unknown.
    // If run at startup, the handler will set either or both of myProjectFileName and myFileList.
    // AEInstallEventHandler(kCoreEventClass, kAEOpenDocuments, openDocumentsAEHandler, 0, false);

    // If the QtCore framework is bundled with the application, clear the library search path
    // and look for Qt plugins only within the application bundle.
    QString bundledQtCore(QCoreApplication::applicationDirPath().append("/lib/QtCore.framework"));
    if (QFile::exists(bundledQtCore))
    {
        QCoreApplication::setLibraryPaths(QStringList(QCoreApplication::applicationDirPath()));
    }
#endif

    MaMainForm * mypForm = new MaMainForm();
    mypForm->show();
    return myApp.exec();

}

/* Test to determine if this program was started on Mac OS X by double-clicking
 * the application bundle rather then from a command line. If clicked, argv[1]
 * contains a process serial number in the form -psn_0_1234567. Don't process
 * the command line arguments in this case because argv[1] confuses the processing.
 */
bool bundleclicked(int argc, char *argv[])
{
  return ( argc > 1 && memcmp(argv[1], "-psn_", 5) == 0 );
}
