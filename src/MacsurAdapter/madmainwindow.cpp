/***************************************************************************
 *   File:  madmainwindow.cpp created: 01/05/2013                                    *
 *   Class info: MadMainWindow                                               *
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
#include <QModelIndex>
#include <QDebug>
#include <QTreeView>

//Local includes
#include "madmainwindow.h"
#include "lib/version.h"

MadMainWindow::MadMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    lblVersion->setText(QString("Version: %1").arg(VERSION) + " " + QString("$Revision: 34 $").replace("$",""));

}


void MadMainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void MadMainWindow::on_trvwCurrentInventory_clicked(const QModelIndex &index)
{
    qDebug() << index; //the tree viewer was clicked
}

//void MadMainWindow::loadModels(MadModelMap *theModelMap);
//{
  //
//}
