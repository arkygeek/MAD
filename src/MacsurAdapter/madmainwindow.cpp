/***************************************************************************
 *   File:  madmainwindow.cpp created: 01/05/2013                          *
 *   Class info: MadMainWindow                                             *
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
#include "gui/madtextdisplayform.h"

MadMainWindow::MadMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    // the key to making the revision autoupdate is to use a feature in svn
    // that will update keywords on commits.  to make this work, you need to:
    //   svn propset svn:keywords "Revision" madmainwindow.cpp
    // and then it works!  note that you need to 'touch' madmainform.cpp every
    // commit for this to work.  This could be simply adding/removing a LF in
    // this file (madmainform.cpp)
    lblVersion->setText(QString("Version: %1").arg(VERSION)+ " "
                        + QString("$Revision$").replace("$",""));

}

QString MadMainWindow::modelText() const
{
  return mModelText;
}

void MadMainWindow::setModelText(QString theModelText)
{
  mModelText=theModelText;
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
    mpMadDataClassification = new MadDataClassification(this);
    mpMadDataClassification->show();
}

void MadMainWindow::on_cbAboutMain_currentIndexChanged(const QString &theSelection)
{
  // update the text to correspond with the combo box selection
  QString mySelection = theSelection.toLower(); // converts to all lowercase
  if (theSelection == "About") loadTextFile(mySelection);
  if (theSelection == "CropM") loadTextFile(mySelection);
  if (theSelection == "LiveM") loadTextFile(mySelection);
  if (theSelection == "TradeM") loadTextFile(mySelection);
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
  mpMadTextDisplayForm = new MadTextDisplayForm(this);
  mpMadTextDisplayForm->show();

  // in order to get at the QTextEdit I need to use MadMainWindow::
  // this is because MadMainWindow is using multiple inheritance
  // and not aggregation as pointer member
  // ->toPlainText() gets contents and converts it to plain text
  QString myExample = MadMainWindow::tedModelSpecsModel->toPlainText();
  mpMadTextDisplayForm->setText(myExample);
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
