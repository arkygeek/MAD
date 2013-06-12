/***************************************************************************
 *   File:  madlogindialog.h created: 12/06/2013                                    *
 *   Class info: MADLoginDialog                                               *
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

#ifndef MADLOGINDIALOG_H
#define MADLOGINDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>



/*!
 *Makes class MadLoginDialog a child to its parent, QDialog
 */
class MadLoginDialog : public QDialog
{
/*!
 *Turns Login Dialog into a QObject
 */
    Q_OBJECT

private:
    /*!
      * A label for the username component.
      */
    QLabel* labelUsername;

    /*!
      * A label for the password.
      */
    QLabel* labelPassword;

    /*!
      * An editable combo box for allowing the user
      * to enter his username or select it from a list.
      */
    QComboBox* comboUsername;

    /*!
      * A field to let the user enters his password.
      */
    QLineEdit* editPassword;

    /*!
      * The standard dialog button box.
      */
    QDialogButtonBox* buttons;

    /*!
      * A method to set up all dialog components and
      * initialize them.
      */
    void setUpGUI();

public:
    explicit MadLoginDialog(QWidget *parent = 0);

    /*!
      * Sets the proposed username, that can come for instance
      * from a shared setting.
      *\param username the string that represents the current username
      * to display
      */
    void setUsername( QString& username );

    /*!
      * Sets the current password to propose to the user for the login.
      * \param password the password to fill into the dialog form
      */
    void setPassword( QString& password );

    /*!
      * Sets a list of allowed usernames from which the user
      * can pick one if he does not want to directly edit it.
      *\param usernames a list of usernames
      */
    void setUsernamesList( const QStringList& usernames );



signals:

    /*!
      * A signal emitted when the login is performed.
      * \param username the username entered in the dialog
      * \param password the password entered in the dialog
      * \param index the number of the username selected in the combobox
      */
    void acceptLogin( QString& username, QString& password, int& indexNumber );

public slots:
    /*!
      * A slot to adjust the emitting of the signal.
      */
    void slotAcceptUserLogin();

};

#endif // MADLOGINDIALOG_H
