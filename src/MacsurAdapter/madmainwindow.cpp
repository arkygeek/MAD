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
#include "gui/madvariablemanager.h"
#include "gui/madmodelmanager.h"
#include "lib/madutils.h"


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
// basded on this example:
// http://www.qtcentre.org/threads/15572-How-can-I-traverse-all-of-the-items-in-a-QStandardItemModel


static QList<QStandardItem*> childList( QStandardItem *thepQStdItem )
{
  QStandardItemModel *mypModel = thepQStdItem->model();
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
    QModelIndex si = mypModel->index(e,thepQStdItem->column(),myIndex);
    QStandardItem *iz = mypModel->itemFromIndex(si);
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
  //QStandardItemModel *pm = qobject_cast<QStandardItemModel *>(mpModel);
  //mpModel = new QStandardItemModel(this);

  if (!mpModel)
  {
    return;
  }

  QStringList myLine;

  int myChildTotal = 0;
  const int myColumnCount = mpModel->columnCount();
  const int myRowCount = mpModel->rowCount();
  qDebug() << "-- iter ---------------------------------------------------------";
  for (int myIterator = 0; myIterator < myColumnCount; ++myIterator)
  {
    const QString myHeaderText1 = mpModel->headerData( myIterator,
                                              Qt::Horizontal,
                                              Qt::DisplayRole ).toString();
    const QString myHeaderText2 = mpModel->headerData( myIterator,
                                               Qt::Vertical,
                                               Qt::DisplayRole).toString();
    myLine << qMax(myHeaderText1,myHeaderText2);
  }

  QList<QStandardItem*> MyList;

  for (int myForIterator = 0; myForIterator < myRowCount; ++myForIterator)
  {
    QStandardItem *mypIndex_1 = mpModel->item(myForIterator,2);
    //QStandardItem *mypIndex_2 = mpModel->item(myForIterator,12);
    MyList.clear();
    MyList = childList(mypIndex_1);
    myChildTotal = MyList.size();
    int myTreeLevel = 0;

    qDebug() << "# lev. " << myTreeLevel <<" line "
             << myForIterator << " txt " << mypIndex_1->text()
             << " child " << myChildTotal;

    if (myChildTotal !=0)
    {
      myTreeLevel++;
      foreach (QStandardItem *mypForEachIndex,MyList)
      {
        MyList.clear();
        myChildTotal = 0;
        MyList = childList(mypForEachIndex);
        myChildTotal = MyList.size();

        qDebug() << "# lev." << myTreeLevel <<" line "
                 << myForIterator << " txt "
                 << mypForEachIndex->text() << " child " << myChildTotal;
      } // end foreach
    } // end if
  } // end for (int e = 0; e < rows; ++e)

  qDebug() << "-- iter ---------------------------------------------------------";
}

void MadMainWindow::loadCsvFile(const QString &theFileToLoad)
{
  MadCsvReader* myMadCsvReaderDialog = new MadCsvReader( this );
  //QStringList myUsernameList;
  //myUsernameList << "Jason" << "Martin" << "Katharina";
  //myMadLoginDialog->setUsernamesList(myUsernameList);
  //connect (myMadLoginDialog,
  //          SIGNAL (acceptLogin (QString&, QString&,int&) ),
  //          this,
  //          SLOT (slotAcceptUserLogin (QString&, QString&) )
  //        );

  myMadCsvReaderDialog->exec();
  //myMadCsvReaderDialog->

//  mpModel = new QStandardItemModel();
//  tblvVariables->setModel(mpModel);
//  QString myFileName = "://agmip/agmip/" + theFileToLoad + ".csv";

//  //MadUtils::csvDecodeToQSIModel(myFileName, mpModel);

//  QList<QString> myDataSetList;
//  QList<QString> mySubSetList;
//  QList<QString> myGroupList;
//  QList<QString> mySubGroupList;

//  QTreeWidget myTree;
//  myTree.setColumnCount(5);

//  int myRowCount = mpModel->rowCount();

//  QString myDataSetHolder = mpModel->item(0, 11)->text();
//  QString mySubSetHolder = mpModel->item(0, 12)->text();
//  QString myGroupHolder = mpModel->item(0, 13)->text();
//  QString mySubGroupHolder = mpModel->item(0, 14)->text();


//  // below verifies proper row count is happening - just for testing

//  for (int myLoopCounter = 0; myLoopCounter < myRowCount; myLoopCounter++)
//  {
//    QString myConvertedValue = QString::number(myLoopCounter);
//    tedVariableMapping->append(myConvertedValue);

//    if (myDataSetHolder == mpModel->item(myLoopCounter, 11)->text())
//    {
//      // the value is the same, do not make new parent entry
//      tedVariableMapping->append("DataSet is the same, do not make new parent");
//    }
//    else
//    {
//      // the value is new, so DO make a new parent entry
//      tedVariableMapping->append("DataSet is different, make new child");
//      myDataSetHolder = mpModel->item(myLoopCounter, 11)->text();
//    }
//    if (mySubSetHolder == mpModel->item(myLoopCounter, 12)->text())
//    {
//      // the value is the same, do not make new child entry
//      tedVariableMapping->append("  SubSet is the same, do not make new child");

//    }
//    else
//    {
//      // the value is new, so DO make a new child entry
//      tedVariableMapping->append("  SubSet is different, make new child");
//      mySubSetHolder = mpModel->item(myLoopCounter, 12)->text();
//    }
//    if (myGroupHolder == mpModel->item(myLoopCounter, 13)->text())
//    {
//      // the value is the same, do not make new grand child entry
//      tedVariableMapping->append("    Group is the same, do not make new grand child");

//    }
//    else
//    {
//      // the value is new, so DO make a new grand child entry
//      tedVariableMapping->append("    Group is different, make new grand child");
//      myGroupHolder = mpModel->item(myLoopCounter, 13)->text();
//    }
//    if (mySubGroupHolder == mpModel->item(myLoopCounter, 14)->text())
//    {
//      // the value is the same, do not make new grand grand child entry
//      tedVariableMapping->append("      SubGroup is the same, do not make new grand grand child");

//    }
//    else
//    {
//      // the value is new, so DO make a new grand grand child entry
//      tedVariableMapping->append("      SubGroup is different, make new grand grand child");
//      mySubGroupHolder = mpModel->item(myLoopCounter, 14)->text();
//      //treeWidget->childAt()
//    }


//    myDataSetList.append(mpModel->item(myLoopCounter, 11)->text());
//    mySubSetList.append(mpModel->item(myLoopCounter, 12)->text());
//    myGroupList.append(mpModel->item(myLoopCounter, 13)->text());
//    mySubGroupList.append(mpModel->item(myLoopCounter, 14)->text());



    //tedVariableMapping->append(mpModel->item(myLoopCounter, 11)->text());
    //tedVariableMapping->append(mpModel->item(myLoopCounter, 12)->text());
    //tedVariableMapping->append(mpModel->item(myLoopCounter, 13)->text());
    //tedVariableMapping->append(mpModel->item(myLoopCounter, 14)->text());

  }
//  treeViewVariables->setModel(mpModel);


//  QSortFilterProxyModel *pFilterModel = new QSortFilterProxyModel(this);


//  pFilterModel->setSourceModel(mpModel);

//  QTreeView *pFilteredView = new QTreeView;
//  pFilterModel->setFilterKeyColumn(11);
//  pFilterModel->sort(11);
//  //pFilterModel->removeColumns(1, 10);

//  treeViewVariables->setModel(pFilterModel);
//}

void MadMainWindow::checkString(QString &theTemporary, QChar theCharacter)
{
  if(theTemporary.count("\"")%2 == 0)
  {
    //if (theTemp.size() == 0 && theCharacter != ',') //problem with line endings
    //    return;
    if (theTemporary.startsWith( QChar('\"'))
       &&
       theTemporary.endsWith( QChar('\"') ) )
    {
       theTemporary.remove( QRegExp("^\"") );
       theTemporary.remove( QRegExp("\"$") );
    }

    //TODO this might fail if there are 4 or more repeating double quotes
    theTemporary.replace("\"\"", "\"");

    QStandardItem *mypItem = new QStandardItem(theTemporary);

    mpStandardItemList.append(mypItem);

    if (theCharacter != QChar(','))
    {
      mpModel->appendRow(mpStandardItemList);
      mpStandardItemList.clear();
    }

    theTemporary.clear();
  }
  else
  {
    theTemporary.append(theCharacter);
  }
}

void MadMainWindow::on_pbManageVariablesList_clicked()
{
  //  MadLoginDialog* myMadLoginDialog = new MadLoginDialog( this );
  MadVariableManager* mypMadVariableManager = new MadVariableManager( this );
  mypMadVariableManager->exec();

}

void MadMainWindow::on_pushButton_clicked()
{
  // open model manager
  MadModelManager* mypMadModelManager = new MadModelManager( this );
  mypMadModelManager->exec();
}
