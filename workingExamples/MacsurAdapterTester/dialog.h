/***************************************************************************
 *   File:  dialog.h created: 02.05.2013                                     *
 *   Class info: Dialog                                                   *
 *   Copyright (C) 2013 by: Katharina S. Braunmiller                       *
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

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

#include "ui_dialog.h"


class Dialog : public QDialog, private Ui::Dialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    void setText(const QString& t);

};

#endif // DIALOG_H
