/***************************************************************************
 *   File:  mamainform.cpp   created: 27/3/2013                            *
 *   Class info: mamainform                                                *
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

#include "mamainform.h"
#include "ui_mamainform.h"

// Qt includes
#include <QFile>
#include <QTextStream>


mamainform::mamainform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mamainform)
{
    ui->setupUi(this);
    loadTextFile();
}

mamainform::~mamainform()
{
    delete ui;
}

void mamainform::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void mamainform::on_findButton_clicked()
 {
     QString searchString = ui->lineEdit->text();
     ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
 }
void mamainform::loadTextFile()
 {
     QFile inputFile(":/input.txt");
     inputFile.open(QIODevice::ReadOnly);

     QTextStream in(&inputFile);
     QString line = in.readAll();
     inputFile.close();

     ui->textEdit->setPlainText(line);
     QTextCursor cursor = ui->textEdit->textCursor();
     cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
 }




void mamainform::on_checkBox_2_clicked()
{

}
