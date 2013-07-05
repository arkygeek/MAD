/********************************************************************************
** Form generated from reading UI file 'madvariablemanagerbase.ui'
**
** Created: Wed Jul 3 15:26:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MADVARIABLEMANAGERBASE_H
#define UI_MADVARIABLEMANAGERBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MadVariableManager
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabMgmtInfo;
    QGridLayout *gridLayout_2;
    QPushButton *pbSearchMgmtInfoTab;
    QTextBrowser *tbrMgmtInfoTab;
    QLineEdit *leSearchMgmtInfoTab;
    QLabel *lblEnterText;
    QWidget *tabMeasuredData;
    QWidget *tabExplanatoryNotes;
    QWidget *tabCodes;
    QToolBox *toolBox;
    QWidget *tbpgMetaData;
    QWidget *tbpgCropCodes;
    QWidget *tbpgMgmtCodes;
    QWidget *tbpgClimateCodes;
    QWidget *tbpgOtherCodes;
    QWidget *tbpgPestCodes;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MadVariableManager)
    {
        if (MadVariableManager->objectName().isEmpty())
            MadVariableManager->setObjectName(QString::fromUtf8("MadVariableManager"));
        MadVariableManager->resize(641, 429);
        gridLayout = new QGridLayout(MadVariableManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(MadVariableManager);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabMgmtInfo = new QWidget();
        tabMgmtInfo->setObjectName(QString::fromUtf8("tabMgmtInfo"));
        gridLayout_2 = new QGridLayout(tabMgmtInfo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pbSearchMgmtInfoTab = new QPushButton(tabMgmtInfo);
        pbSearchMgmtInfoTab->setObjectName(QString::fromUtf8("pbSearchMgmtInfoTab"));

        gridLayout_2->addWidget(pbSearchMgmtInfoTab, 0, 2, 1, 1);

        tbrMgmtInfoTab = new QTextBrowser(tabMgmtInfo);
        tbrMgmtInfoTab->setObjectName(QString::fromUtf8("tbrMgmtInfoTab"));

        gridLayout_2->addWidget(tbrMgmtInfoTab, 1, 0, 1, 3);

        leSearchMgmtInfoTab = new QLineEdit(tabMgmtInfo);
        leSearchMgmtInfoTab->setObjectName(QString::fromUtf8("leSearchMgmtInfoTab"));

        gridLayout_2->addWidget(leSearchMgmtInfoTab, 0, 1, 1, 1);

        lblEnterText = new QLabel(tabMgmtInfo);
        lblEnterText->setObjectName(QString::fromUtf8("lblEnterText"));

        gridLayout_2->addWidget(lblEnterText, 0, 0, 1, 1);

        tabWidget->addTab(tabMgmtInfo, QString());
        tabMeasuredData = new QWidget();
        tabMeasuredData->setObjectName(QString::fromUtf8("tabMeasuredData"));
        tabWidget->addTab(tabMeasuredData, QString());
        tabExplanatoryNotes = new QWidget();
        tabExplanatoryNotes->setObjectName(QString::fromUtf8("tabExplanatoryNotes"));
        tabWidget->addTab(tabExplanatoryNotes, QString());
        tabCodes = new QWidget();
        tabCodes->setObjectName(QString::fromUtf8("tabCodes"));
        toolBox = new QToolBox(tabCodes);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 20, 761, 145));
        tbpgMetaData = new QWidget();
        tbpgMetaData->setObjectName(QString::fromUtf8("tbpgMetaData"));
        tbpgMetaData->setGeometry(QRect(0, 0, 761, 21));
        toolBox->addItem(tbpgMetaData, QString::fromUtf8("Meta Data"));
        tbpgCropCodes = new QWidget();
        tbpgCropCodes->setObjectName(QString::fromUtf8("tbpgCropCodes"));
        tbpgCropCodes->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(tbpgCropCodes, QString::fromUtf8("Crops"));
        tbpgMgmtCodes = new QWidget();
        tbpgMgmtCodes->setObjectName(QString::fromUtf8("tbpgMgmtCodes"));
        tbpgMgmtCodes->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(tbpgMgmtCodes, QString::fromUtf8("Management"));
        tbpgClimateCodes = new QWidget();
        tbpgClimateCodes->setObjectName(QString::fromUtf8("tbpgClimateCodes"));
        tbpgClimateCodes->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(tbpgClimateCodes, QString::fromUtf8("Climate"));
        tbpgOtherCodes = new QWidget();
        tbpgOtherCodes->setObjectName(QString::fromUtf8("tbpgOtherCodes"));
        tbpgOtherCodes->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(tbpgOtherCodes, QString::fromUtf8("Others"));
        tbpgPestCodes = new QWidget();
        tbpgPestCodes->setObjectName(QString::fromUtf8("tbpgPestCodes"));
        tbpgPestCodes->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(tbpgPestCodes, QString::fromUtf8("Pests"));
        tabWidget->addTab(tabCodes, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

        label = new QLabel(MadVariableManager);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        font.setItalic(true);
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MadVariableManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);


        retranslateUi(MadVariableManager);
        QObject::connect(buttonBox, SIGNAL(accepted()), MadVariableManager, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MadVariableManager, SLOT(reject()));

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(MadVariableManager);
    } // setupUi

    void retranslateUi(QDialog *MadVariableManager)
    {
        MadVariableManager->setWindowTitle(QApplication::translate("MadVariableManager", "Dialog", 0, QApplication::UnicodeUTF8));
        pbSearchMgmtInfoTab->setText(QApplication::translate("MadVariableManager", "Search", 0, QApplication::UnicodeUTF8));
        lblEnterText->setText(QApplication::translate("MadVariableManager", "Enter Text", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabMgmtInfo), QApplication::translate("MadVariableManager", "Management Info", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabMeasuredData), QApplication::translate("MadVariableManager", "Measured Data", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabExplanatoryNotes), QApplication::translate("MadVariableManager", "Explanatory Notes", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(tbpgMetaData), QApplication::translate("MadVariableManager", "Meta Data", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(tbpgCropCodes), QApplication::translate("MadVariableManager", "Crops", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(tbpgMgmtCodes), QApplication::translate("MadVariableManager", "Management", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(tbpgClimateCodes), QApplication::translate("MadVariableManager", "Climate", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(tbpgOtherCodes), QApplication::translate("MadVariableManager", "Others", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(tbpgPestCodes), QApplication::translate("MadVariableManager", "Pests", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCodes), QApplication::translate("MadVariableManager", "Codes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MadVariableManager", "ICASA Variable list last updated 19-June-2013", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MadVariableManager: public Ui_MadVariableManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADVARIABLEMANAGERBASE_H
