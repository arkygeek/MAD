/***************************************************************************
 *   File:  madcsvreader.cpp created: 11/07/2013                           *
 *   Class info: MadCsvReader                                              *
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

#include "madcsvreader.h"
#include "ui_madcsvreaderbase.h"

MadCsvReader::MadCsvReader(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MadCsvReader)
{
  ui->setupUi(this);
}

MadCsvReader::~MadCsvReader()
{
  delete ui;
}

void MadCsvReader::on_pbSelectFile_clicked()
{
  mpQSIModel = new QStandardItemModel(this);
  ui->tableView->setModel(mpQSIModel);
  QString myFileName = QFileDialog::getOpenFileName (this, "Open CSV file",
                                                     QDir::currentPath(), "CSV (*.csv)");
  QFile file (myFileName);
  if (file.open(QIODevice::ReadOnly))
  {
    QString myData = file.readAll();
    myData.remove( QRegExp("\r") ); // takes out the carriage returns

    QString myTempData;
    QChar myQCharacter;

    QTextStream myTextStream(&myData);
    while (!myTextStream.atEnd())
    {
      myTextStream >> myQCharacter;
      if (myQCharacter == ',')
      {
        checkTheString(myTempData, myQCharacter);
      }
      else if (myQCharacter == '\n')
      {
        checkTheString(myTempData, myQCharacter);
      }
      else if (myTextStream.atEnd())
      {
        myTempData.append(myQCharacter);
        checkTheString(myTempData);
      }
      else
      {
        myTempData.append(myQCharacter);
      }

    }      //end while
  }     //end if
}    //end of function

void MadCsvReader::checkTheString(QString &theQString, QChar theQChar)
{
  if(theQString.count("\"")%2 == 0)
  {
    //if (theTemp.size() == 0 && theCharacter != ',') return;//problem with line endings

    if (theQString.startsWith( QChar('\"')) && theQString.endsWith( QChar('\"') ) )
    {
       theQString.remove( QRegExp("^\"") );
       theQString.remove( QRegExp("\"$") );
    }

    theQString.replace("\"\"", "\""); //TODO may fail with 4 double quotes """"

    QStandardItem *mypQStandardItem = new QStandardItem(theQString);
    mQListOfQStandardItems.append(mypQStandardItem);

    if (theQChar != QChar(','))
    {
      mpQSIModel->appendRow(mQListOfQStandardItems);
      mQListOfQStandardItems.clear();
    }

    theQString.clear();
  }
  else
  {
    theQString.append(theQChar);
  }
}
