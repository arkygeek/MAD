/***************************************************************************
 *   File:  madutils.cpp created: 06/05/2013                               *
 *   Class info: MadUtils                                                  *
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

//Local includes
#include "madutils.h"
#include "madmodel.h"

//Qt includes
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QPluginLoader>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QtXml>
#include <QString>
#include <QStandardItemModel>

#include <QFileDialog>
//#ifdef Q_OS_MACX
  //for getting app bundle path
//#include <ApplicationServices/ApplicationServices.h>
//#endif

MadUtils::MadUtils()
{
}

/**
 * Returns the path to the settings directory in user's home dir
 */
const QString MadUtils::userSettingsDirPath()
{
  QSettings mySettings;
  QString myPath=
      mySettings.value("dataDirs/dataDir", QDir::homePath() + QString("/.macsurAdapter/") ).toString();
  //  Make sure the users settings dir actually exists
  QDir().mkpath(myPath);
  return myPath;
}
const QString MadUtils::getModelOutputDir()
{
  QString myPath = userSettingsDirPath()+QDir::separator()+"modelOutputs"+QDir::separator();
  QDir().mkpath(myPath);
  return myPath;
}

const QString MadUtils::userDatasetClassificationDirPath()
{
    //alg profiles are always saved in the users home dir under .macsurAdapter
    QString myPath = QDir::homePath() + QString("/.macsurAdapter/") +
      QDir::separator()+"datasetClassifications"+QDir::separator();
    QDir().mkpath(myPath);
    return myPath;
}

const QString MadUtils::userDatasetParametersDirPath()
{
    //alg profiles are always saved in the users home dir under .macsurAdapter/
  QString myPath = QDir::homePath() + QString("/.macsurAdapter/") +
    QDir::separator() + "datasetParameters" + QDir::separator();
  QDir().mkpath(myPath);
  return myPath;
}

const QString MadUtils::userImagesDirPath()
{
  QString myPath = QDir::homePath() + QString("/.macsurAdapter") +
    QDir::separator()+"images"+QDir::separator();
  QDir().mkpath(myPath);
  return myPath;
}

MadUtils::ModelMap MadUtils::getAvailableModels()
{
  MadUtils::ModelMap myMap;
  QDir myDirectory(userDatasetClassificationDirPath());
  myDirectory.setFilter(QDir::Dirs | QDir::Files | QDir::NoSymLinks );
  QFileInfoList myList = myDirectory.entryInfoList();
  for (unsigned int i = 0; i < static_cast<unsigned int>(myList.size()); ++i)
  {
    QFileInfo myFileInfo = myList.at(i);
      //Ignore directories
    if(myFileInfo.fileName() == "." ||myFileInfo.fileName() == ".." )
    {
      continue;
    }
      //if the filename ends in .xml try to load it into our layerSets listing
    if(myFileInfo.completeSuffix()=="xml")
    {
        //qDebug("Loading model: " + myList.at(i).absoluteFilePath().toLocal8Bit());
      MadModel myModel;
      myModel.fromXml(myFileInfo.absoluteFilePath());
      if (myModel.name().isEmpty())
      {
          //qDebug("Model name was empty!");
        continue;
      }
        //qDebug("Adding " + myModel.name());
      myMap[myModel.guid()]=myModel;
        //qDebug(myModel.toText().toLocal8Bit());
    }
  }
  return myMap;
}




bool MadUtils::createTextFile(QString theFileName, QString theData)
{
    //create the txt file
  QFile myFile( theFileName );
  if ( myFile.open( QIODevice::WriteOnly ) )
  {
    QTextStream myQTextStream( &myFile );
    myQTextStream << theData;
  }
  else
  {
    return false;
  }
  myFile.close();
  return true ;
}

QString MadUtils::xmlEncode(QString theString)
{
  theString = theString.replace("<","&lt;");
  theString = theString.replace(">","&gt;");
  theString = theString.replace("&","&amp;");
  return theString;
}

QString MadUtils::xmlDecode(QString theString)
{
  theString = theString.replace("&lt;","<");
  theString = theString.replace("&gt;",">");
  theString = theString.replace("&amp;","&");
  return theString;
}

void MadUtils::checkString(QString &theTemporary, QChar theCharacter)
{
  if(theTemporary.count("\"")%2 == 0)
  {
    //if (theTemporary.size() == 0 && theCharacter != ',') //problem with line endings
       //theTemporary.remove(QChar(','));
       //return;
    if (theTemporary.startsWith( QChar('\"'))
       &&
       theTemporary.endsWith( QChar('\"') ) )
    {
       theTemporary.remove( QRegExp("^\"") );
       theTemporary.remove( QRegExp("\"$") );
    }

    //TODO this might fail if there are 4 or more reapeating double quotes
    theTemporary.replace("\"\"", "\"");

    QStandardItem *mypItem = new QStandardItem(theTemporary);

    mpStandardItemList.append(mypItem);

    if (theCharacter != QChar(','))
    {
      mpModelFromCsv->appendRow(mpStandardItemList);
      mpStandardItemList.clear();
    }

    theTemporary.clear();
  }
  else
  {
    theTemporary.append(theCharacter);
  }
}

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

QStandardItemModel& MadUtils::csvDecodeToQSIModel
                              (const QString theFileToLoad)
{
  QStandardItemModel *mypModel;// = new QStandardItemModel(this);
  //tblvVariables->setModel(mpModel);
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
        checkString(myTemp, myCharacter);
      }

      else
      {
        myTemp.append(myCharacter);
      } // end else
    } // end while
  } // end if

  //
  // now we subIterate
  //

  QStringList myLine;

  int myChildTotal = 0;
  const int myColumnCount = mypModel->columnCount();
  const int myRowCount = mypModel->rowCount();
  qDebug() << "-- iter ---------------------------------------------------------";
  for (int myIterator = 0; myIterator < myColumnCount; ++myIterator)
  {
    const QString myHeaderText1 = mypModel->headerData( myIterator,
                                              Qt::Horizontal,
                                              Qt::DisplayRole ).toString();
    const QString myHeaderText2 = mypModel->headerData( myIterator,
                                               Qt::Vertical,
                                               Qt::DisplayRole).toString();
    myLine << qMax(myHeaderText1,myHeaderText2);
  }

  QList<QStandardItem*> MyList;



  for (int myForIterator = 0; myForIterator < myRowCount; ++myForIterator)
  {
    QStandardItem *mypIndex_1 = mypModel->item(myForIterator,2);
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


  return *mypModel;

}


QString MadUtils::getStandardCss()
{
  QString myStyle = ".glossy{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); color: white; padding-left: 4px; border: 1px solid #6c6c6c; }";
  myStyle += "body {background: white;}";
  myStyle += "h1 {font-size : 22pt; color: #0063F7; }";
  myStyle += "h2 {font-size : 18pt; color: #0063F7; }";
  myStyle += "h3 {font-size : 14pt; color: #0063F7; }";
  myStyle += ".cellHeader {color:#466aa5; font-size : 12pt;}";
  myStyle += ".parameterHeader {font-weight: bold;}";
  myStyle += ".largeCell {color:#000000; font-size : 12pt;}";
  myStyle += ".table {"
                    "  border-width: 1px 1px 1px 1px;"
                    "  border-spacing: 2px;"
                    "  border-style: solid solid solid solid;"
                    "  border-color: black black black black;"
                    "  border-collapse: separate;"
                    "  background-color: white;"
                    "}";
  return myStyle;
}

QString MadUtils::openGraphicFile()
{
  QString myHomePath = QDir::homePath();
  QString myFileName = QFileDialog::getOpenFileName(0, "Choose an image", myHomePath, "Images (*.png *.xpm *.jpg)");
  QFileInfo fi(myFileName);
  QString myName = fi.fileName();
  QString myDestinationFilePathName = userImagesDirPath() + myName;
  QFile::copy(myFileName, myDestinationFilePathName);
  return myDestinationFilePathName;
}

QString MadUtils::saveFile()
{
  QString myHomePath = QDir::homePath();
  QString myFileName = QFileDialog::getSaveFileName(0, "Choose a file name", userConversionTablesDirPath(), "*.csv");
  QFileInfo fi(myFileName);
  QString myName = fi.fileName();
  QString myDestinationFilePathName = userConversionTablesDirPath() + myName;
  return myDestinationFilePathName;
}

const QString MadUtils::userConversionTablesDirPath()
{
    // always saved in the users home dir under .macsurAdapter/
  QString myPath = QDir::homePath() + QString("/.macsurAdapter/") +
    QDir::separator()+"conversionTables"+QDir::separator();
  QDir().mkpath(myPath);
  return myPath;
}
