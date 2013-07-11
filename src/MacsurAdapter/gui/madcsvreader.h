/***************************************************************************
 *   File:  madcsvreader.h created: 11/07/2013                             *
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

#ifndef MADCSVREADER_H
#define MADCSVREADER_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStandardItemModel>

namespace Ui {
  class MadCsvReader;
}

class MadCsvReader : public QDialog
{
  Q_OBJECT
  
public:
  explicit MadCsvReader(QWidget *parent = 0);
  ~MadCsvReader();
  
private slots:
  void on_pbSelectFile_clicked();
  void checkTheString(QString &theQString, QChar theQChar = 0);

private:
  Ui::MadCsvReader *ui;
  QList<QStringList> mCsvQList;
  QStandardItemModel *mpQSIModel;
  QList<QStandardItem*> mQListOfQStandardItems;
};

#endif // MADCSVREADER_H
