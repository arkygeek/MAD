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

#include "madmainwindow.h"


MadMainWindow::MadMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    model = new QStringListModel(this);
    QStringList list;
    list << "hoi" << "ik" << "ben";
    model->setStringList(list);
    colvwModelSpecs->setModel(model);
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

void MadMainWindow::on_pbViewAsText_clicked()
{
    dial = new Dialog(this);

    dial->setModel(colvwModelSpecs->model()); // setText oder setModel?
    dial->setModal(true);
    dial->setVisible(true);
}
