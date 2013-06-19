/***************************************************************************
 *   File:  madlogindialog.cpp created: 12/06/2013                         *
 *   Class info: MADLoginDialog                                            *
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

#include "madlogindialog.h"

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>

MadLoginDialog::MadLoginDialog(QWidget *parent) :
    QDialog(parent)
{
  setUpGUI();
  setWindowTitle( tr("User Login") );
  setModal( true );
}

void MadLoginDialog::setUpGUI()
{
  // set up the layout
  QGridLayout* formGridLayout = new QGridLayout( this );

  // initialize the username combo box so that it is editable
  cbUsername = new QComboBox( this );
  cbUsername->setEditable( true );
  // initialize the password field so that it does not echo
  // characters
  editPassword = new QLineEdit( this );
  editPassword->setEchoMode( QLineEdit::Password );

  // initialize the labels
  lblUsername = new QLabel( this );
  lblPassword = new QLabel( this );
  lblUsername->setText( tr( "Username" ) );
  lblUsername->setBuddy( cbUsername );
  lblPassword->setText( tr( "Password" ) );
  lblPassword->setBuddy( editPassword );

  // initialize buttons
  buttons = new QDialogButtonBox( this );
  buttons->addButton( QDialogButtonBox::Ok );
  buttons->addButton( QDialogButtonBox::Cancel );
  buttons->button( QDialogButtonBox::Ok )->setText( tr("Login") );
  buttons->button( QDialogButtonBox::Cancel )->setText( tr("Abort") );

  // connects slots
  connect( buttons->button( QDialogButtonBox::Cancel ),
           SIGNAL(clicked()),
           this,
           SLOT(close())
         );

  connect( buttons->button( QDialogButtonBox::Ok ),
           SIGNAL(clicked()),
           this,
           SLOT(slotAcceptUserLogin())
         );

  // place components into the dialog
  formGridLayout->addWidget( lblUsername, 0, 0 );
  formGridLayout->addWidget( cbUsername, 0, 1 );
  formGridLayout->addWidget( lblPassword, 1, 0 );
  formGridLayout->addWidget( editPassword, 1, 1 );
  formGridLayout->addWidget( buttons, 2, 0, 1, 2 );

  setLayout( formGridLayout );
}


void MadLoginDialog::setUsername(const QString &username)
{
  bool found = false;
  for ( int i = 0; i < cbUsername->count() && ! found ; i++ )
      if( cbUsername->itemText( i ) == username  )
      {
        cbUsername->setCurrentIndex( i );
        found = true;
      }

    if( ! found )
    {
      int index = cbUsername->count();
      qDebug() << "Select username " << index;
      cbUsername->addItem( username );

      cbUsername->setCurrentIndex( index );
    }

  // place the focus on the password field
  editPassword->setFocus();
}


void MadLoginDialog::setPassword(QString &thePassword)
{
    editPassword->setText( thePassword );
}

void MadLoginDialog::slotAcceptUserLogin()
{
    QString username = cbUsername->currentText();
    QString password = editPassword->text();
    int     index    = cbUsername->currentIndex();

    emit acceptLogin( username,  // current username
                      password,  // current password
                      index      // index in the username list
                      );

    // close this dialog
    close();
}

void MadLoginDialog::setUsernamesList(const QStringList &usernames)
{
    cbUsername->addItems( usernames );
}
