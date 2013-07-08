/***************************************************************************
 *   File:  main.cpp created: 01/05/2013                                   *
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
//Qt includes
#include <QApplication>
#include <QBitmap>
#include <QFile>
#include <QPixmap>
#include <QProxyStyle>
#include <QSettings>
#include <QSplashScreen>
#include <QString>
#include <QStyle>
  //std includes
#ifdef Q_OS_MACX
#include <ApplicationServices/ApplicationServices.h>
#endif

#include "madmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef Q_WS_WIN   // lets windows use plastique syle
  QApplication::setStyle(new QPlastiqueStyle);
#endif

#ifdef Q_OS_MACX
  QString bundledQtCore(QCoreApplication::applicationDirPath().append
                        ("/lib/QtCore.framework"));

  /* Test to determine if this program was started on Mac OS X by double-clicking
  * the application bundle rather then from a command line. If clicked, argv[1]
  * contains a process serial number in the form -psn_0_1234567. Don't process
  * the command line arguments in this case because argv[1] confuses the processing.
  */
  if (QFile::exists(bundledQtCore))
  {
    QCoreApplication::setLibraryPaths(QStringList
                                      (QCoreApplication::applicationDirPath())
                                     );
  }
#endif

    MadMainWindow w;
    w.show();
    return a.exec();
}


bool bundleclicked(int argc, char *argv[])
{
  return ( argc > 1 && memcmp(argv[1], "-psn_", 5) == 0 );
}
