/********************************************************************************
** Form generated from reading UI file 'madcsvreaderbase.ui'
**
** Created: Mon Jul 29 13:52:28 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MADCSVREADERBASE_H
#define UI_MADCSVREADERBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MadCsvReader
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QPushButton *pbSelectFile;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MadCsvReader)
    {
        if (MadCsvReader->objectName().isEmpty())
            MadCsvReader->setObjectName(QString::fromUtf8("MadCsvReader"));
        MadCsvReader->resize(400, 300);
        gridLayout = new QGridLayout(MadCsvReader);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(MadCsvReader);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font;
        font.setPointSize(9);
        tableView->setFont(font);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        pbSelectFile = new QPushButton(MadCsvReader);
        pbSelectFile->setObjectName(QString::fromUtf8("pbSelectFile"));

        gridLayout->addWidget(pbSelectFile, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MadCsvReader);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(MadCsvReader);
        QObject::connect(buttonBox, SIGNAL(accepted()), MadCsvReader, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MadCsvReader, SLOT(reject()));

        QMetaObject::connectSlotsByName(MadCsvReader);
    } // setupUi

    void retranslateUi(QDialog *MadCsvReader)
    {
        MadCsvReader->setWindowTitle(QApplication::translate("MadCsvReader", "Dialog", 0, QApplication::UnicodeUTF8));
        pbSelectFile->setText(QApplication::translate("MadCsvReader", "Select File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MadCsvReader: public Ui_MadCsvReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADCSVREADERBASE_H
