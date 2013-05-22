/***************************************************************************
 *   File:  madtextdisplayform.h created: 16/05/2013                       *
 *   Class info: MadTextDisplayForm                                        *
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

#ifndef MADTEXTDISPLAYFORM_H
#define MADTEXTDISPLAYFORM_H

#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
 #ifdef Q_WS_WIN
  #include <QtGui>
  #include <QDialog>
 #else
 #include <QtGui/QDialog>
 #endif
#endif

namespace Ui {class MadTextDisplayForm;}

class MadTextDisplayForm : public QDialog
{
  Q_OBJECT
  
public:
  explicit MadTextDisplayForm(QWidget *parent = 0);
  ~MadTextDisplayForm();
  void setText(const QString &theText);
private:
  Ui::MadTextDisplayForm *ui;
  QString mTheText;
};

#endif // MADTEXTDISPLAYFORM_H
