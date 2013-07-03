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
#include <QSortFilterProxyModel>

//Local includes
#include "madmainwindow.h"
#include "lib/madversion.h"
#include "gui/maddataclassification.h"
#include "gui/madtextdisplayform.h"
#include "gui/madlogindialog.h"

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

  //QxtCsvModel myQxtCsvModel;




  //connect ( pbLogin, SIGNAL ( valueChanged(int) ), this, SLOT ( slotAcceptUserLogin() ));
}

QString MadMainWindow::modelText() const
{
  return mModelText;
}

QString MadMainWindow::userName() const
{
  return mUserName;
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

void MadMainWindow::loadHtmlFile(const QString &theFileToLoad)
{
  QString myFilename = "://" + theFileToLoad + ".html";
  QFile inputFile(myFilename);
  inputFile.open(QIODevice::ReadOnly);
  QTextStream in(&inputFile);
  QString myHtml = in.readAll();
  inputFile.close();

  txtbrwsData->clear();
  txtbrwsData->append(myHtml);
  txtbrwsData->setUndoRedoEnabled(false);
  //plainTextEdit->clear();
  //plainTextEdit->appendHtml(myHtml);
  //plainTextEdit->setUndoRedoEnabled(false);
 }

void MadMainWindow::on_pbViewAsHtml_clicked()
{
    // view model details in HTML format
}

void MadMainWindow::on_pbExportCsv_clicked()
{
    // Export model details as a CSV file
}

void MadMainWindow::on_pbTableView_clicked()
{
    // Table view of the model details
}

void MadMainWindow::on_modelNameComboBox_currentIndexChanged(
                    const QString &theSelection)
{
    txtbrwsData->setText("This will say something about:");
    txtbrwsData->append(theSelection);

    QString mySelection = theSelection.toLower(); // converts to all lowercase
    if (theSelection == "CMAP")
       loadHtmlFile("cmap");
    if (theSelection == "Dai")
       loadHtmlFile("Dai");
    if (theSelection == "I-COADS")
       loadHtmlFile("I-COADS");
    if (theSelection == "CRU TS 2.0")
       loadHtmlFile("CRU-TS-2.0");
    if (theSelection == "HadISST")
       loadHtmlFile("HadISST");
    if (theSelection == "Hulme (CRU)")
       loadHtmlFile("Hulme-CRU");
    if (theSelection == "Jones (CRU) Air Temperature")
       loadHtmlFile("JonesCRUAirTemp");
    if (theSelection == "Jones (CRU) SLP")
       loadHtmlFile("Jones-CRU-SLP");
    if (theSelection == "Kaplan (SLP)")
       loadHtmlFile("Kaplan-SLP");
    if (theSelection == "Kaplan (SST)")
       loadHtmlFile("Kaplan-SST");
    if (theSelection == "Lucas and Waliser Satellite ECT-Corrected OLR")
       loadHtmlFile("Lucas-Waliser-Satellite-ECT-Corrected-OLR");
    if (theSelection == "NCAR Sea Level Pressure")
       loadHtmlFile("NCAR-Sea-Level-Pressure");
    if (theSelection == "NCEP/NCAR Reanalysis")
       loadHtmlFile("NCEP-NCAR-Reanalysis");
    if (theSelection == "Reynold Reconstructed SST")
       loadHtmlFile("Reynolds-Reconstructed-SST");
    if (theSelection == "Reynolds Optimum Interpolation (OI) SST")
       loadHtmlFile("Reynolds-Optimum-Interpolation-OI-SST");
    if (theSelection == "Reynolds Optimum Interpolation Ver. 2 (OI.v2) SST")
       loadHtmlFile("Reynolds-Optimum-Interpolation-Ver-2-OIv2");
    if (theSelection == "Smith and Reynolds Extended Reconstructed SLP (ERSLP)")
       loadHtmlFile("Smith-Reynolds-Extended-Reconstructed-SLP-ERSLP");
    if (theSelection == "Smith and Reynolds Extended Reconstructed SST (ERSST)")
       loadHtmlFile("Smith-Reynolds-Extended-Reconstructed-SST-ERSST");

    if (theSelection == "Credits")
    {
      plainTextEdit->clear();
      plainTextEdit->appendPlainText("how vain!");
      plainTextEdit->setUndoRedoEnabled(false);
    }

}

void MadMainWindow::on_pbLogin_clicked()
{
  MadLoginDialog* myMadLoginDialog = new MadLoginDialog( this );
  //myMadLoginDialog->setUsername( "Jason" );  // optional
  QStringList myUsernameList;
  myUsernameList << "Jason" << "Martin" << "Katharina";
  myMadLoginDialog->setUsernamesList(myUsernameList);
  connect (myMadLoginDialog,
            SIGNAL (acceptLogin (QString&, QString&,int&) ),
            this,
            SLOT (slotAcceptUserLogin (QString&, QString&) )
          );

  myMadLoginDialog->exec();

}

void MadMainWindow::setUserName(const QString &theUserName)
{
  mUserName=theUserName;
}


void MadMainWindow::slotAcceptUserLogin (QString &theUsername, QString &thePassword)
{
  // accept the user login details and update label
  lblLoginStatus->setText(theUsername);
}

void MadMainWindow::on_pbAddVariable_clicked()
{
    //TODO open a dialog to add and map a new variable
}

void MadMainWindow::on_comboBox_currentIndexChanged(const QString &theSelection)
{
  if (theSelection=="ICASA")
  {
    loadCsvFile("management_info");
  }
}

// a class to build a xml
//   mpModel = new QStandardItemModel(this);

static QList<QStandardItem*> childList( QStandardItem *thepQStdItem )
{
  QStandardItemModel *pm = thepQStdItem->model();
  QList<QStandardItem*> myReturnList;
  QModelIndex myIndex = thepQStdItem->index();\

  if (!myIndex.isValid())
  {
    return myReturnList;
  }

  if (thepQStdItem->rowCount() == 0)
  {
    return myReturnList;
  }

  for (int e = 0; e < thepQStdItem->rowCount(); ++e)
  {
    QModelIndex si = pm->index(e,thepQStdItem->column(),myIndex);
    QStandardItem *iz = pm->itemFromIndex(si);
    if (iz)
    {
      myReturnList << iz;
    }
  }

  return myReturnList;
}


void MadMainWindow::subIterate()
{
  //QStandardItemModel *pm = qobject_cast<QStandardItemModel *>(mpModel2());
  QStandardItemModel *pm = qobject_cast<QStandardItemModel *>(mpModel2);

  pm = new QStandardItemModel(this);
  if (!pm)
  {
    return;
  }

  QStringList myLine;
  int myRw = 0;
  int myCw = 0;
  int myCtot = 0;
  const int cools = pm->columnCount();
  const int rows = pm->rowCount();
  qDebug() << "-- iter ---------------------------------------------------------";
  for (int i = 0; i < cools; ++i)
  {
    const QString htxt = pm->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
    const QString htxt1 = pm->headerData(i,Qt::Vertical,Qt::DisplayRole).toString();
    myLine << qMax(htxt,htxt1);
  }

  QList<QStandardItem*> MyList;

  for (int e = 0; e < rows; ++e)
  {
    QStandardItem *ix_1 = pm->item(e,0);
    QStandardItem *ix_2 = pm->item(e,1);
    MyList.clear();
    MyList = childList(ix_1);
    myCtot = MyList.size();
    int level = 0;

    qDebug() << "# lev." << level <<" line " << e << " txt " << ix_1->text() << " child " << myCtot;

    if (myCtot !=0)
    {

      level++;
      foreach (QStandardItem *ix,MyList)
      {
        MyList.clear();
        myCtot = 0;
        MyList = childList(ix);
        myCtot = MyList.size();

        qDebug() << "# lev." << level <<" line " << e << " txt " << ix->text() << " child " << myCtot;

      } // end foreach
    } // end if
  } // end for (int e = 0; e < rows; ++e)

  qDebug() << "-- iter ---------------------------------------------------------";
}

void MadMainWindow::loadCsvFile(const QString &theFileToLoad)
{
  mpModel = new QStandardItemModel(this);
  tblvVariables->setModel(mpModel);
  QString myFileName = "://agmip/agmip/" + theFileToLoad + ".csv";

  QFile myFile (myFileName);
  if (myFile.open(QIODevice::ReadOnly))
  {
    QString data = myFile.readAll();

    //remove all Carriage Returns
    data.remove( QRegExp("\r") );

    QString myTemp;
    QChar myCharacter;
    QTextStream myTextStream(&data);

    while (!myTextStream.atEnd())
    {
      myTextStream >> myCharacter;
      if (myCharacter == ',')
      {
        checkString(myTemp, myCharacter);
      }

      else if (myCharacter == '\n')
      {
        checkString(myTemp, myCharacter);
      }

      else if (myTextStream.atEnd())
      {
        myTemp.append(myCharacter);
        checkString(myTemp);
      }

      else
      {
        myTemp.append(myCharacter);
      } // end else
    } // end while
  } // end if
}

void MadMainWindow::checkString(QString &theTemporary, QChar theCharacter)
{
    if(theTemporary.count("\"")%2 == 0)
    {
        //if (theTemp.size() == 0 && theCharacter != ',') //problem with line endings
        //    return;
        if (theTemporary.startsWith( QChar('\"')) && theTemporary.endsWith( QChar('\"') ) )
        {
             theTemporary.remove( QRegExp("^\"") );
             theTemporary.remove( QRegExp("\"$") );
        }
        //TODO this might fail if there are 4 or more reapeating double quotes
        theTemporary.replace("\"\"", "\"");
        QStandardItem *mypItem = new QStandardItem(theTemporary);
        mStandardItemList.append(mypItem);
        if (theCharacter != QChar(',')) {
            mpModel->appendRow(mStandardItemList);
            mStandardItemList.clear();
        }
        theTemporary.clear();
    } else {
        theTemporary.append(theCharacter);
    }
}

// http://www.qtcentre.org/threads/15572-How-can-I-traverse-all-of-the-items-in-a-QStandardItemModel

