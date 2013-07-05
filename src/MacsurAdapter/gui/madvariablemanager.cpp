/***************************************************************************
 *   File:  madvariablemanager.cpp created: 19/06/2013                     *
 *   Class info: MadVariableManager                                        *
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

// Qt includes
#include <QTextStream>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QFile>


// Local includes
#include "madvariablemanager.h"
#include "ui_madvariablemanagerbase.h"

MadVariableManager::MadVariableManager(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MadVariableManager)
{
  ui->setupUi(this);
}

MadVariableManager::~MadVariableManager()
{
  delete ui;
}

void MadVariableManager::checkString(QString &theTemporary, QChar theCharacter)
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

void MadVariableManager::loadCsvFile(const QString &theFileToLoad)
{
  mpModelFromCsv = new QStandardItemModel(this);
  ui->tbvwExplore->setModel(mpModelFromCsv);
  QString myFileName = "://agmip/agmip/" + theFileToLoad;// + ".csv";

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

  //subIterate();

  int myIndexRow = 0;
  int myIndexColumn = 12;
  //QModelIndex mpModel->(myIndexRow, myIndexColumn);

  //need to sort the data using columns 12,13,14,15 to put into tree

  //QModelIndex  Dataset,Subset,Group,Sub-group

  QList<QString> myDataSetList;
  QList<QString> mySubSetList;
  QList<QString> myGroupList;
  QList<QString> mySubGroupList;

  //QTreeWidget myTree;
  //myTree.setColumnCount(5);

  int myRowCount = mpModelFromCsv->rowCount();

  QString myDataSetHolder = mpModelFromCsv->item(0, 11)->text();
  QString mySubSetHolder = mpModelFromCsv->item(0, 12)->text();
  QString myGroupHolder = mpModelFromCsv->item(0, 13)->text();
  QString mySubGroupHolder = mpModelFromCsv->item(0, 14)->text();

  //QTreeWidgetItem myTreeItem;
  //treeWidget->setHeader(QHeaderView(mpModel->text( 0, 11)));
  //myTreeItem mySubSetHolder;
  //myTreeItem myGroupHolder;
  //myTreeItem mySubGroupHolder;


  // below verifies proper row count is happening - just for testing

  for (int myLoopCounter = 0; myLoopCounter < myRowCount; myLoopCounter++)
  {
    QString myConvertedValue = QString::number(myLoopCounter);
    //tedVariableMapping->append(myConvertedValue);
/*
    if (myDataSetHolder == mpModel->item(myLoopCounter, 11)->text())
    {
      // the value is the same, do not make new parent entry
      tedVariableMapping->append("DataSet is the same, do not make new parent");
    }
    else
    {
      // the value is new, so DO make a new parent entry
      tedVariableMapping->append("DataSet is different, make new child");
      myDataSetHolder = mpModel->item(myLoopCounter, 11)->text();
    }
    if (mySubSetHolder == mpModel->item(myLoopCounter, 12)->text())
    {
      // the value is the same, do not make new child entry
      tedVariableMapping->append("  SubSet is the same, do not make new child");

    }
    else
    {
      // the value is new, so DO make a new child entry
      tedVariableMapping->append("  SubSet is different, make new child");
      mySubSetHolder = mpModel->item(myLoopCounter, 12)->text();
    }
    if (myGroupHolder == mpModel->item(myLoopCounter, 13)->text())
    {
      // the value is the same, do not make new grand child entry
      tedVariableMapping->append("    Group is the same, do not make new grand child");

    }
    else
    {
      // the value is new, so DO make a new grand child entry
      tedVariableMapping->append("    Group is different, make new grand child");
      myGroupHolder = mpModel->item(myLoopCounter, 13)->text();
    }
    if (mySubGroupHolder == mpModel->item(myLoopCounter, 14)->text())
    {
      // the value is the same, do not make new grand grand child entry
      tedVariableMapping->append("      SubGroup is the same, do not make new grand grand child");

    }
    else
    {
      // the value is new, so DO make a new grand grand child entry
      tedVariableMapping->append("      SubGroup is different, make new grand grand child");
      mySubGroupHolder = mpModel->item(myLoopCounter, 14)->text();
      //treeWidget->childAt()
    }
*/

    myDataSetList.append(mpModelFromCsv->item(myLoopCounter, 11)->text());
    mySubSetList.append(mpModelFromCsv->item(myLoopCounter, 12)->text());
    myGroupList.append(mpModelFromCsv->item(myLoopCounter, 13)->text());
    mySubGroupList.append(mpModelFromCsv->item(myLoopCounter, 14)->text());



    //tedVariableMapping->append(mpModel->item(myLoopCounter, 11)->text());
    //tedVariableMapping->append(mpModel->item(myLoopCounter, 12)->text());
    //tedVariableMapping->append(mpModel->item(myLoopCounter, 13)->text());
    //tedVariableMapping->append(mpModel->item(myLoopCounter, 14)->text());

  }
  //treeViewVariables->setModel(mpModel);


  QSortFilterProxyModel *pFilterModel = new QSortFilterProxyModel(this);


  pFilterModel->setSourceModel(mpModelFromCsv);

  //QTreeView *pFilteredView = new QTreeView;
  pFilterModel->setFilterKeyColumn(11);
  pFilterModel->sort(11);
  //pFilterModel->removeColumns(1, 10);

  //treeViewVariables->setModel(pFilterModel);
}

void MadVariableManager::on_cbSelectFile_currentIndexChanged(const QString &theSelection)
{
    loadCsvFile(theSelection);
}
