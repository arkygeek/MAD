/********************************************************************************
** Form generated from reading UI file 'madmainwindowbase.ui'
**
** Created: Sun May 19 18:37:06 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MADMAINWINDOWBASE_H
#define UI_MADMAINWINDOWBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MadMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabwidMainWin;
    QWidget *tabMain;
    QGridLayout *gridLayout_4;
    QComboBox *cbAboutMain;
    QLabel *lblVersion;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *lblGraphicMain;
    QWidget *tabModels;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *vLayout;
    QLabel *lblCurrentInventory;
    QListView *lvwCurrentInventoryModels;
    QGroupBox *grpbxWhatToShow;
    QGridLayout *gridLayout;
    QCheckBox *chbxRunCommand;
    QCheckBox *chbxParameters;
    QCheckBox *chbxInputData;
    QCheckBox *checkBox;
    QWidget *layoutWidget1;
    QVBoxLayout *vlayoutModelSpecs;
    QLabel *lblModelSpecs;
    QTextEdit *tedModelSpecsModel;
    QPushButton *pbViewAsText;
    QWidget *tabData;
    QComboBox *modelNameComboBox;
    QPushButton *pbClassification;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MadMainWindow)
    {
        if (MadMainWindow->objectName().isEmpty())
            MadMainWindow->setObjectName(QString::fromUtf8("MadMainWindow"));
        MadMainWindow->resize(589, 431);
        actionOpen = new QAction(MadMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionAbout = new QAction(MadMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MadMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabwidMainWin = new QTabWidget(centralWidget);
        tabwidMainWin->setObjectName(QString::fromUtf8("tabwidMainWin"));
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        gridLayout_4 = new QGridLayout(tabMain);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        cbAboutMain = new QComboBox(tabMain);
        cbAboutMain->setObjectName(QString::fromUtf8("cbAboutMain"));

        gridLayout_4->addWidget(cbAboutMain, 1, 2, 1, 1);

        lblVersion = new QLabel(tabMain);
        lblVersion->setObjectName(QString::fromUtf8("lblVersion"));
        lblVersion->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lblVersion, 4, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(tabMain);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setPointSize(10);
        plainTextEdit->setFont(font);

        gridLayout_4->addWidget(plainTextEdit, 2, 2, 1, 1);

        label = new QLabel(tabMain);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(8);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label, 4, 2, 1, 1);

        label_2 = new QLabel(tabMain);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/MACSURLogo122x50Transp.png")));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        lblGraphicMain = new QLabel(tabMain);
        lblGraphicMain->setObjectName(QString::fromUtf8("lblGraphicMain"));
        lblGraphicMain->setPixmap(QPixmap(QString::fromUtf8(":/MADCircle.png")));
        lblGraphicMain->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lblGraphicMain, 0, 0, 4, 2);

        tabwidMainWin->addTab(tabMain, QString());
        tabModels = new QWidget();
        tabModels->setObjectName(QString::fromUtf8("tabModels"));
        gridLayout_3 = new QGridLayout(tabModels);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(tabModels);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        vLayout = new QVBoxLayout(layoutWidget);
        vLayout->setSpacing(6);
        vLayout->setContentsMargins(11, 11, 11, 11);
        vLayout->setObjectName(QString::fromUtf8("vLayout"));
        vLayout->setContentsMargins(0, 0, 0, 0);
        lblCurrentInventory = new QLabel(layoutWidget);
        lblCurrentInventory->setObjectName(QString::fromUtf8("lblCurrentInventory"));
        lblCurrentInventory->setAlignment(Qt::AlignCenter);

        vLayout->addWidget(lblCurrentInventory);

        lvwCurrentInventoryModels = new QListView(layoutWidget);
        lvwCurrentInventoryModels->setObjectName(QString::fromUtf8("lvwCurrentInventoryModels"));

        vLayout->addWidget(lvwCurrentInventoryModels);

        grpbxWhatToShow = new QGroupBox(layoutWidget);
        grpbxWhatToShow->setObjectName(QString::fromUtf8("grpbxWhatToShow"));
        gridLayout = new QGridLayout(grpbxWhatToShow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chbxRunCommand = new QCheckBox(grpbxWhatToShow);
        chbxRunCommand->setObjectName(QString::fromUtf8("chbxRunCommand"));
        chbxRunCommand->setChecked(true);

        gridLayout->addWidget(chbxRunCommand, 0, 0, 1, 1);

        chbxParameters = new QCheckBox(grpbxWhatToShow);
        chbxParameters->setObjectName(QString::fromUtf8("chbxParameters"));
        chbxParameters->setChecked(true);

        gridLayout->addWidget(chbxParameters, 1, 0, 1, 1);

        chbxInputData = new QCheckBox(grpbxWhatToShow);
        chbxInputData->setObjectName(QString::fromUtf8("chbxInputData"));
        chbxInputData->setChecked(true);

        gridLayout->addWidget(chbxInputData, 2, 0, 1, 1);

        checkBox = new QCheckBox(grpbxWhatToShow);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 3, 0, 1, 1);


        vLayout->addWidget(grpbxWhatToShow);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        vlayoutModelSpecs = new QVBoxLayout(layoutWidget1);
        vlayoutModelSpecs->setSpacing(6);
        vlayoutModelSpecs->setContentsMargins(11, 11, 11, 11);
        vlayoutModelSpecs->setObjectName(QString::fromUtf8("vlayoutModelSpecs"));
        vlayoutModelSpecs->setContentsMargins(0, 0, 0, 0);
        lblModelSpecs = new QLabel(layoutWidget1);
        lblModelSpecs->setObjectName(QString::fromUtf8("lblModelSpecs"));
        lblModelSpecs->setAlignment(Qt::AlignCenter);

        vlayoutModelSpecs->addWidget(lblModelSpecs);

        tedModelSpecsModel = new QTextEdit(layoutWidget1);
        tedModelSpecsModel->setObjectName(QString::fromUtf8("tedModelSpecsModel"));

        vlayoutModelSpecs->addWidget(tedModelSpecsModel);

        pbViewAsText = new QPushButton(layoutWidget1);
        pbViewAsText->setObjectName(QString::fromUtf8("pbViewAsText"));

        vlayoutModelSpecs->addWidget(pbViewAsText);

        splitter->addWidget(layoutWidget1);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        tabwidMainWin->addTab(tabModels, QString());
        tabData = new QWidget();
        tabData->setObjectName(QString::fromUtf8("tabData"));
        modelNameComboBox = new QComboBox(tabData);
        modelNameComboBox->setObjectName(QString::fromUtf8("modelNameComboBox"));
        modelNameComboBox->setEnabled(true);
        modelNameComboBox->setGeometry(QRect(40, 220, 331, 26));
        modelNameComboBox->setModelColumn(0);
        pbClassification = new QPushButton(tabData);
        pbClassification->setObjectName(QString::fromUtf8("pbClassification"));
        pbClassification->setGeometry(QRect(90, 120, 114, 32));
        tabwidMainWin->addTab(tabData, QString());

        gridLayout_2->addWidget(tabwidMainWin, 0, 0, 1, 2);

        MadMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MadMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 589, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MadMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MadMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MadMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MadMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MadMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuHelp->addAction(actionAbout);

        retranslateUi(MadMainWindow);

        tabwidMainWin->setCurrentIndex(0);
        modelNameComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MadMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MadMainWindow)
    {
        MadMainWindow->setWindowTitle(QApplication::translate("MadMainWindow", "MadMainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MadMainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MadMainWindow", "About", 0, QApplication::UnicodeUTF8));
        cbAboutMain->clear();
        cbAboutMain->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "About", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "CropM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "LiveM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "TradeM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Credits", 0, QApplication::UnicodeUTF8)
        );
        lblVersion->setText(QApplication::translate("MadMainWindow", "Version Label", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("MadMainWindow", "This software is intended to simplify model integration between the CropM, LiveM, and TradeM themes.\n"
"\n"
"It provides a common platform to describe, evaluate and integrate models and datasets.\n"
"\n"
"It is open source (GPL V.3) and written in C++/Qt (v4.8)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MadMainWindow", "\302\251 Jason Jorgenson 2013", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        lblGraphicMain->setText(QString());
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabMain), QApplication::translate("MadMainWindow", "Main", 0, QApplication::UnicodeUTF8));
        lblCurrentInventory->setText(QApplication::translate("MadMainWindow", "Current Inventory", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        grpbxWhatToShow->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Select desired info to display</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        grpbxWhatToShow->setTitle(QApplication::translate("MadMainWindow", "Select what to show", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chbxRunCommand->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of the run command for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chbxRunCommand->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of the run command for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        chbxRunCommand->setText(QApplication::translate("MadMainWindow", "Run Command", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chbxParameters->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all parameters for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chbxParameters->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all parameters for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        chbxParameters->setText(QApplication::translate("MadMainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chbxInputData->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all input files required for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chbxInputData->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all input files required for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        chbxInputData->setText(QApplication::translate("MadMainWindow", "Input Files", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all output files created by the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all output files created by the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("MadMainWindow", "Output Files", 0, QApplication::UnicodeUTF8));
        lblModelSpecs->setText(QApplication::translate("MadMainWindow", "Model Specifications", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbViewAsText->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbViewAsText->setText(QApplication::translate("MadMainWindow", "View Selection as Text", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabModels), QApplication::translate("MadMainWindow", "Models", 0, QApplication::UnicodeUTF8));
        modelNameComboBox->clear();
        modelNameComboBox->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "CMAP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "I-COADS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "CRU TS 2.0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Dai", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "HadISST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Hulme (CRU)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Jones (CRU) Air Temperature", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Jones (CRU) SLP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Kaplan (SLP)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Kaplan (SST)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Lucas and Waliser Satellite ECT-Corrected OLR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "NCAR Sea Level Pressure", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "NCEP/NCAR Reanalysis", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Reynold Reconstructed SST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Reynolds Optimum Interpolation (OI) SST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Reynolds Optimum Interpolation Ver. 2 (OI.v2) SST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Smith and Reynolds Extended Reconstructed SST (ERSST)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Other", 0, QApplication::UnicodeUTF8)
        );
        pbClassification->setText(QApplication::translate("MadMainWindow", "Classification", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabData), QApplication::translate("MadMainWindow", "Data", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MadMainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MadMainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MadMainWindow: public Ui_MadMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADMAINWINDOWBASE_H
