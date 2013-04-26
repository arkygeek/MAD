/***************************************************************************
 *   File:  mainwindow.cpp created: 24/04/2013                                    *
 *   Class info: MainWindow                                               *
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::on_pbSelectFile_clicked()
{
    QString filters("Music (*.mp3);;Text (*.txt);;All (*.*)");
        QString defaultFilter("Text (*.txt)");

        /* Static method approach */
        QString myFileName = QFileDialog::getOpenFileName
                (0, "Save file", QDir::currentPath(),
                filters, &defaultFilter);
        ui->ledFileToLoad->setText(myFileName);
}



void MainWindow::on_pbLoadFile_clicked()
{
    QString myFileToLoad = ui->ledFileToLoad->text();
    QFile myInputFile(myFileToLoad);
    myInputFile.open(QIODevice::ReadOnly);
    QTextStream in(&myInputFile);
    QString myLine = in.readAll();
    myInputFile.close();

    ui->tedDisplaysFile->setText(myLine);

}



void MainWindow::on_pbOpenDialog_clicked()
{
    ptr = new NewFormClass;
    ptr->show();
}
