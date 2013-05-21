/********************************************************************************
** Form generated from reading UI file 'madtextdisplayformbase.ui'
**
** Created: Sun May 19 18:37:07 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MADTEXTDISPLAYFORMBASE_H
#define UI_MADTEXTDISPLAYFORMBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MadTextDisplayForm
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MadTextDisplayForm)
    {
        if (MadTextDisplayForm->objectName().isEmpty())
            MadTextDisplayForm->setObjectName(QString::fromUtf8("MadTextDisplayForm"));
        MadTextDisplayForm->resize(400, 300);
        gridLayout = new QGridLayout(MadTextDisplayForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(MadTextDisplayForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MadTextDisplayForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(MadTextDisplayForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), MadTextDisplayForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MadTextDisplayForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(MadTextDisplayForm);
    } // setupUi

    void retranslateUi(QDialog *MadTextDisplayForm)
    {
        MadTextDisplayForm->setWindowTitle(QApplication::translate("MadTextDisplayForm", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MadTextDisplayForm: public Ui_MadTextDisplayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADTEXTDISPLAYFORMBASE_H
