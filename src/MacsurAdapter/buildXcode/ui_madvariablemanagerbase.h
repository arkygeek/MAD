/********************************************************************************
** Form generated from reading UI file 'madvariablemanagerbase.ui'
**
** Created: Mon Jul 29 13:52:28 2013
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBox>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MadVariableManager
{
public:
    QGridLayout *gridLayout;
    QLabel *lblListUpdated;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tabExplore;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacerExplore;
    QComboBox *cbExploreFilterColumn;
    QSplitter *splitter;
    QTableView *tblvwFullDataSetExplore;
    QTreeView *trvwFilteredDataSetExplore;
    QPushButton *pbDisplayData;
    QLabel *lblExploreFilterSyntax;
    QComboBox *cbExploreSelectHeader;
    QPushButton *pbDisplayHeaders;
    QLabel *lblExploreFilterPattern;
    QComboBox *cbExploreFilterSyntax;
    QCheckBox *chbxExploreCaseSensFilter;
    QCheckBox *chbxExploreCaseSensSorting;
    QComboBox *cbExploreSelectFile;
    QHBoxLayout *horizontalLayoutExplore;
    QLineEdit *ledExploreHeaderChar;
    QPushButton *pbExploreSetHeaderChar;
    QSpacerItem *horizontalSpacerExplore;
    QLineEdit *ledFilterPattern;
    QLabel *lblExploreFilterColumn;
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

    void setupUi(QDialog *MadVariableManager)
    {
        if (MadVariableManager->objectName().isEmpty())
            MadVariableManager->setObjectName(QString::fromUtf8("MadVariableManager"));
        MadVariableManager->resize(844, 631);
        gridLayout = new QGridLayout(MadVariableManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblListUpdated = new QLabel(MadVariableManager);
        lblListUpdated->setObjectName(QString::fromUtf8("lblListUpdated"));
        QFont font;
        font.setPointSize(11);
        font.setItalic(true);
        lblListUpdated->setFont(font);

        gridLayout->addWidget(lblListUpdated, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MadVariableManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        tabWidget = new QTabWidget(MadVariableManager);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabExplore = new QWidget();
        tabExplore->setObjectName(QString::fromUtf8("tabExplore"));
        gridLayout_3 = new QGridLayout(tabExplore);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacerExplore = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacerExplore, 3, 3, 1, 1);

        cbExploreFilterColumn = new QComboBox(tabExplore);
        cbExploreFilterColumn->setObjectName(QString::fromUtf8("cbExploreFilterColumn"));

        gridLayout_3->addWidget(cbExploreFilterColumn, 11, 3, 1, 1);

        splitter = new QSplitter(tabExplore);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tblvwFullDataSetExplore = new QTableView(splitter);
        tblvwFullDataSetExplore->setObjectName(QString::fromUtf8("tblvwFullDataSetExplore"));
        splitter->addWidget(tblvwFullDataSetExplore);
        trvwFilteredDataSetExplore = new QTreeView(splitter);
        trvwFilteredDataSetExplore->setObjectName(QString::fromUtf8("trvwFilteredDataSetExplore"));
        splitter->addWidget(trvwFilteredDataSetExplore);

        gridLayout_3->addWidget(splitter, 1, 0, 14, 3);

        pbDisplayData = new QPushButton(tabExplore);
        pbDisplayData->setObjectName(QString::fromUtf8("pbDisplayData"));

        gridLayout_3->addWidget(pbDisplayData, 2, 3, 1, 1);

        lblExploreFilterSyntax = new QLabel(tabExplore);
        lblExploreFilterSyntax->setObjectName(QString::fromUtf8("lblExploreFilterSyntax"));

        gridLayout_3->addWidget(lblExploreFilterSyntax, 7, 3, 1, 1);

        cbExploreSelectHeader = new QComboBox(tabExplore);
        cbExploreSelectHeader->setObjectName(QString::fromUtf8("cbExploreSelectHeader"));

        gridLayout_3->addWidget(cbExploreSelectHeader, 0, 3, 1, 1);

        pbDisplayHeaders = new QPushButton(tabExplore);
        pbDisplayHeaders->setObjectName(QString::fromUtf8("pbDisplayHeaders"));

        gridLayout_3->addWidget(pbDisplayHeaders, 1, 3, 1, 1);

        lblExploreFilterPattern = new QLabel(tabExplore);
        lblExploreFilterPattern->setObjectName(QString::fromUtf8("lblExploreFilterPattern"));

        gridLayout_3->addWidget(lblExploreFilterPattern, 5, 3, 1, 1);

        cbExploreFilterSyntax = new QComboBox(tabExplore);
        cbExploreFilterSyntax->setObjectName(QString::fromUtf8("cbExploreFilterSyntax"));

        gridLayout_3->addWidget(cbExploreFilterSyntax, 8, 3, 1, 1);

        chbxExploreCaseSensFilter = new QCheckBox(tabExplore);
        chbxExploreCaseSensFilter->setObjectName(QString::fromUtf8("chbxExploreCaseSensFilter"));
        chbxExploreCaseSensFilter->setChecked(true);

        gridLayout_3->addWidget(chbxExploreCaseSensFilter, 12, 3, 1, 1);

        chbxExploreCaseSensSorting = new QCheckBox(tabExplore);
        chbxExploreCaseSensSorting->setObjectName(QString::fromUtf8("chbxExploreCaseSensSorting"));
        chbxExploreCaseSensSorting->setChecked(true);

        gridLayout_3->addWidget(chbxExploreCaseSensSorting, 13, 3, 1, 1);

        cbExploreSelectFile = new QComboBox(tabExplore);
        cbExploreSelectFile->setObjectName(QString::fromUtf8("cbExploreSelectFile"));

        gridLayout_3->addWidget(cbExploreSelectFile, 0, 0, 1, 1);

        horizontalLayoutExplore = new QHBoxLayout();
        horizontalLayoutExplore->setObjectName(QString::fromUtf8("horizontalLayoutExplore"));
        ledExploreHeaderChar = new QLineEdit(tabExplore);
        ledExploreHeaderChar->setObjectName(QString::fromUtf8("ledExploreHeaderChar"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ledExploreHeaderChar->sizePolicy().hasHeightForWidth());
        ledExploreHeaderChar->setSizePolicy(sizePolicy);
        ledExploreHeaderChar->setMaximumSize(QSize(40, 16777215));

        horizontalLayoutExplore->addWidget(ledExploreHeaderChar);

        pbExploreSetHeaderChar = new QPushButton(tabExplore);
        pbExploreSetHeaderChar->setObjectName(QString::fromUtf8("pbExploreSetHeaderChar"));

        horizontalLayoutExplore->addWidget(pbExploreSetHeaderChar);

        horizontalSpacerExplore = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutExplore->addItem(horizontalSpacerExplore);


        gridLayout_3->addLayout(horizontalLayoutExplore, 0, 1, 1, 1);

        ledFilterPattern = new QLineEdit(tabExplore);
        ledFilterPattern->setObjectName(QString::fromUtf8("ledFilterPattern"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ledFilterPattern->sizePolicy().hasHeightForWidth());
        ledFilterPattern->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(ledFilterPattern, 6, 3, 1, 1);

        lblExploreFilterColumn = new QLabel(tabExplore);
        lblExploreFilterColumn->setObjectName(QString::fromUtf8("lblExploreFilterColumn"));

        gridLayout_3->addWidget(lblExploreFilterColumn, 10, 3, 1, 1);

        tabWidget->addTab(tabExplore, QString());
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
        tbpgCropCodes->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(tbpgCropCodes, QString::fromUtf8("Crops"));
        tbpgMgmtCodes = new QWidget();
        tbpgMgmtCodes->setObjectName(QString::fromUtf8("tbpgMgmtCodes"));
        tbpgMgmtCodes->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(tbpgMgmtCodes, QString::fromUtf8("Management"));
        tbpgClimateCodes = new QWidget();
        tbpgClimateCodes->setObjectName(QString::fromUtf8("tbpgClimateCodes"));
        tbpgClimateCodes->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(tbpgClimateCodes, QString::fromUtf8("Climate"));
        tbpgOtherCodes = new QWidget();
        tbpgOtherCodes->setObjectName(QString::fromUtf8("tbpgOtherCodes"));
        tbpgOtherCodes->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(tbpgOtherCodes, QString::fromUtf8("Others"));
        tbpgPestCodes = new QWidget();
        tbpgPestCodes->setObjectName(QString::fromUtf8("tbpgPestCodes"));
        tbpgPestCodes->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(tbpgPestCodes, QString::fromUtf8("Pests"));
        tabWidget->addTab(tabCodes, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        lblExploreFilterSyntax->setBuddy(cbExploreFilterSyntax);
        lblExploreFilterPattern->setBuddy(ledFilterPattern);
        lblExploreFilterColumn->setBuddy(cbExploreFilterColumn);
#endif // QT_NO_SHORTCUT

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
        lblListUpdated->setText(QApplication::translate("MadVariableManager", "ICASA Variable list last updated 19-June-2013", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tblvwFullDataSetExplore->setToolTip(QApplication::translate("MadVariableManager", "<html><head/><body><p>Complete data set</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        trvwFilteredDataSetExplore->setToolTip(QApplication::translate("MadVariableManager", "<html><head/><body><p>Sorted/Filtered data set</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbDisplayData->setText(QApplication::translate("MadVariableManager", "Display Data", 0, QApplication::UnicodeUTF8));
        lblExploreFilterSyntax->setText(QApplication::translate("MadVariableManager", "Filter Syntax:", 0, QApplication::UnicodeUTF8));
        cbExploreSelectHeader->clear();
        cbExploreSelectHeader->insertItems(0, QStringList()
         << QApplication::translate("MadVariableManager", "Select Header", 0, QApplication::UnicodeUTF8)
        );
        pbDisplayHeaders->setText(QApplication::translate("MadVariableManager", "Display Headers", 0, QApplication::UnicodeUTF8));
        lblExploreFilterPattern->setText(QApplication::translate("MadVariableManager", "Filter Pattern:", 0, QApplication::UnicodeUTF8));
        cbExploreFilterSyntax->clear();
        cbExploreFilterSyntax->insertItems(0, QStringList()
         << QApplication::translate("MadVariableManager", "Regular Expression", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "Wildcard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "Fixed String", 0, QApplication::UnicodeUTF8)
        );
        chbxExploreCaseSensFilter->setText(QApplication::translate("MadVariableManager", "Case Sensitive Filter", 0, QApplication::UnicodeUTF8));
        chbxExploreCaseSensSorting->setText(QApplication::translate("MadVariableManager", "Case Sensitive Sorting", 0, QApplication::UnicodeUTF8));
        cbExploreSelectFile->clear();
        cbExploreSelectFile->insertItems(0, QStringList()
         << QApplication::translate("MadVariableManager", "Select File", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "management_info.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "measured_data.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "explanatory_notes.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "climate_codes.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "crop_codes.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "management_codes.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "metadata_codes.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "other_codes.csv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadVariableManager", "pest_codes.csv", 0, QApplication::UnicodeUTF8)
        );
        pbExploreSetHeaderChar->setText(QApplication::translate("MadVariableManager", "Set Header Char", 0, QApplication::UnicodeUTF8));
        ledFilterPattern->setText(QString());
        lblExploreFilterColumn->setText(QApplication::translate("MadVariableManager", "Filter Column:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabExplore), QApplication::translate("MadVariableManager", "Explore", 0, QApplication::UnicodeUTF8));
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
    } // retranslateUi

};

namespace Ui {
    class MadVariableManager: public Ui_MadVariableManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADVARIABLEMANAGERBASE_H
