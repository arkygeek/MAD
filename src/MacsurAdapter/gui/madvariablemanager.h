/***************************************************************************
 *   File:  madvariablemanager.h created: 19/06/2013                                    *
 *   Class info: MadVariableManager                                               *
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

#ifndef MADVARIABLEMANAGER_H
#define MADVARIABLEMANAGER_H

#include <QtGlobal>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
  class MadVariableManager;
}

class MadVariableManager : public QDialog
{
  Q_OBJECT
  
public:
  explicit MadVariableManager(QWidget *parent = 0);
  ~MadVariableManager();
  
  void loadCsvFile(const QString &theFileToLoad);
  void checkString(QString &theTemporary, QChar theCharacter);
private slots:
  void on_cbSelectFile_currentIndexChanged(const QString &theSelection);

private:
  Ui::MadVariableManager *ui;

  QString mModelText;
  QSortFilterProxyModel *pFilterModel;

  //
  // the CSV stuff
  //
  QList<QStringList> mCsv;
  QStandardItemModel *mpModelFromCsv;
  //QStandardItemModel *mpModel2;
  QList<QStandardItem*> mpStandardItemList;

};

#endif // MADVARIABLEMANAGER_H
