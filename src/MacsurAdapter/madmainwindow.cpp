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
#include <QPixmap>
#include <QGraphicsObject>

//Local includes
#include "madmainwindow.h"
#include "lib/madversion.h"
#include "gui/maddataclassification.h"

MadMainWindow::MadMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    lblVersion->setText(QString("Version: %1").arg(VERSION)+ " " + QString("$Revision: 60 $").replace("$",""));

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



//void MadMainWindow::loadModels(MadModelMap *theModelMap);
//{
  //
//}

void MadMainWindow::on_pbClassification_clicked()
{
    // launch classification form (modal method)
    //MadDataClassification myMadDataClassification;
    //myMadDataClassification.setModal(true);
    //myMadDataClassification.exec();

    // launch classification form (modal-less method)
    pMadDataClassification = new MadDataClassification(this);
    pMadDataClassification->show();
}

void MadMainWindow::on_cbAboutMain_currentIndexChanged(const QString &theSelection)
{
  // update the text to correspond with the combo box selection
  QString mySelection = theSelection;
  if (theSelection == "About") loadTextFile("about");
  if (theSelection == "CropM") loadTextFile("cropm");
  if (theSelection == "LiveM") loadTextFile("livem");
  if (theSelection == "TradeM") loadTextFile("tradem");
  if (theSelection == "Credits")
  {
    plainTextEdit->clear();
    plainTextEdit->appendPlainText("how vain!");
    plainTextEdit->setUndoRedoEnabled(false);
  }
}

void MadMainWindow::on_pbViewAsText_clicked()
{
  // display model info in new dialog as plain text
}

void MadMainWindow::on_actionOpen_triggered()
{
  //Open file dialog from main menu bar

}

void MadMainWindow::on_lvwCurrentInventoryModels_clicked(const QModelIndex &theIndex)
{
  // triggers loading of model details for display in treevwModelSpecsModels
  QModelIndex myModelIndex = theIndex;
}

void MadMainWindow::loadTextFile(const QString &theFileToLoad)
 {
   QString myFilename = "://" + theFileToLoad + ".txt";
   QFile inputFile(myFilename);
   inputFile.open(QIODevice::ReadOnly);
   QTextStream in(&inputFile);
   QString line = in.readAll();
   inputFile.close();

   plainTextEdit->clear();
   plainTextEdit->appendPlainText(line);
   plainTextEdit->setUndoRedoEnabled(false);
 }
