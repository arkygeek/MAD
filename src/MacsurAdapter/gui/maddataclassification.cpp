/***************************************************************************
 *   File:  maddataclassification.cpp created: 08/05/2013                                    *
 *   Class info: MadDataClassification                                               *
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

//Qt includes

//Local includes
#include "maddataclassification.h"
#include "lib/mad.h"

MadDataClassification::MadDataClassification(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    groupBox->setChecked(false);
    cbExamples->setEnabled(true);
    lblExample->setVisible(true);
    lblExample->setText("Select Example");
}

void MadDataClassification::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void MadDataClassification::on_groupBox_clicked()
{
    // if values are editable, should not be able to select for any
    // examples to be shown as it will destroy destroy current settings

    if (groupBox->isChecked())
    {
        lblExample->setVisible(false);
        cbExamples->setDisabled(true);
    }
    else
    {
        cbExamples->setEnabled(true);
        lblExample->setVisible(true);
    }
}

void MadDataClassification::on_cbExamples_currentIndexChanged(const QString &arg1)
{
    // if enabled, set values for corresponding classification
    // options are: Platinum, Gold, Silver, Bronze
    if (cbExamples->currentText()!="Examples")
    {
        lblExample->setText(arg1);
    }
    else
    {
        lblExample->setText("Select Example");
    }

    // I want to make it work somethig like this, but can't remember how
    //
    /*DataClass myDataClass = cbExamples->currentText();
    switch (myDataClass) {
    case Platinum:
        lblExample->setText("Platinum");
        break;
    case Gold:
        lblExample->setText("Gold");
        break;
    case Silver:
        lblExample->setText("Silver");
        break;
    case Bronze:
        lblExample->setText("Bronze");
        break;
    default:
        lblExample->setText("Select Example");
        break;
    }*/
}
