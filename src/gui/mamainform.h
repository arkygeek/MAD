/***************************************************************************
 *   File:  mamainform.h   created: 27/3/2013                              *
 *   Class info: mamainform                                                *
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

#ifndef MAMAINFORM_H
#define MAMAINFORM_H

#include <QMainWindow>

namespace Ui {
class MaMainForm;
}

class MaMainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaMainForm(QWidget *parent = 0);
    ~MaMainForm();

private slots:
    void on_actionQuit_triggered();

    void on_actionInput_File_triggered();

private:
    Ui::MaMainForm *ui;
};

#endif // MAMAINFORM_H
