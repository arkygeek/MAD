/***************************************************************************
 *   File:  mafileinputmanager.h created: 22/04/2013                                    *
 *   Class info: MaFileInputManager                                               *
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

#ifndef MAFILEINPUTMANAGER_H
#define MAFILEINPUTMANAGER_H

#include <QtGui/QDialog>

namespace Ui {
class MaFileInputManager;
}

class MaFileInputManager : public QDialog
{
    Q_OBJECT
    
public:
    explicit MaFileInputManager(QWidget *parent = 0);
    ~MaFileInputManager();
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::MaFileInputManager *ui;
};

#endif // MAFILEINPUTMANAGER_H
