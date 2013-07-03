/********************************************************************************
** Form generated from reading UI file 'madmainwindowbase.ui'
**
** Created: Wed Jul 3 15:26:41 2013
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MadMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QTabWidget *tabwidMainWin;
    QWidget *tabMain;
    QGridLayout *gridLayout_2;
    QComboBox *cbAboutMain;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout;
    QLabel *lblGraphicMain;
    QLabel *lblVersion;
    QLabel *lblLoginStatus;
    QSpacerItem *verticalSpacer;
    QPushButton *pbLogin;
    QLabel *label;
    QWidget *tabModels;
    QGridLayout *gridLayout_12;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *vLayout;
    QLabel *lblCurrentInventory;
    QListView *lvwCurrentInventoryModels;
    QGroupBox *grpbxWhatToShow;
    QGridLayout *gridLayout;
    QCheckBox *chbxRunCommand;
    QCheckBox *chbxParameters;
    QCheckBox *chbxInputData;
    QCheckBox *chbxOutputFiles;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_11;
    QLabel *lblModelSpecs;
    QTextEdit *tedModelSpecsModel;
    QPushButton *pbViewAsText;
    QPushButton *pbViewAsHtml;
    QPushButton *pbExportCsv;
    QPushButton *pbTableView;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabGlossary;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QLineEdit *leGlossarySearch;
    QPushButton *pbGlossarySearch;
    QTextBrowser *tbrGlossary;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTermTabGlossary;
    QLineEdit *ledAddTermTerm;
    QPushButton *pbGlossaryAddTerm;
    QLabel *lblGlossaryDefn;
    QLineEdit *leGlossaryDefinition;
    QWidget *tabVariables;
    QGridLayout *gridLayout_8;
    QGroupBox *gbxVariablesTab;
    QGridLayout *gridLayout_10;
    QSplitter *splitter_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_9;
    QPushButton *pbAddVariable;
    QComboBox *comboBox;
    QLabel *lblVariableTree;
    QTableView *tblvVariables;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_3;
    QLabel *lblVariableMapping;
    QSplitter *splitter;
    QTreeView *treeViewVariables;
    QTextEdit *tedVariableMapping;
    QComboBox *comboBox_2;
    QPushButton *pbRemoveMapping;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QWidget *tabData;
    QGridLayout *gridLayout_5;
    QTextBrowser *txtbrwsData;
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
        MadMainWindow->resize(712, 462);
        actionOpen = new QAction(MadMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionAbout = new QAction(MadMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MadMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabwidMainWin = new QTabWidget(centralWidget);
        tabwidMainWin->setObjectName(QString::fromUtf8("tabwidMainWin"));
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        gridLayout_2 = new QGridLayout(tabMain);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbAboutMain = new QComboBox(tabMain);
        cbAboutMain->setObjectName(QString::fromUtf8("cbAboutMain"));

        gridLayout_2->addWidget(cbAboutMain, 0, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(tabMain);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setPointSize(10);
        plainTextEdit->setFont(font);

        gridLayout_2->addWidget(plainTextEdit, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblGraphicMain = new QLabel(tabMain);
        lblGraphicMain->setObjectName(QString::fromUtf8("lblGraphicMain"));
        lblGraphicMain->setMaximumSize(QSize(200, 140));
        lblGraphicMain->setPixmap(QPixmap(QString::fromUtf8(":/newMACSURLogoTransparentFull.png")));
        lblGraphicMain->setScaledContents(true);
        lblGraphicMain->setAlignment(Qt::AlignCenter);
        lblGraphicMain->setOpenExternalLinks(false);

        verticalLayout->addWidget(lblGraphicMain);

        lblVersion = new QLabel(tabMain);
        lblVersion->setObjectName(QString::fromUtf8("lblVersion"));
        lblVersion->setFont(font);
        lblVersion->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblVersion);

        lblLoginStatus = new QLabel(tabMain);
        lblLoginStatus->setObjectName(QString::fromUtf8("lblLoginStatus"));
        lblLoginStatus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblLoginStatus);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbLogin = new QPushButton(tabMain);
        pbLogin->setObjectName(QString::fromUtf8("pbLogin"));

        verticalLayout->addWidget(pbLogin);

        label = new QLabel(tabMain);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(8);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 2, 1);

        tabwidMainWin->addTab(tabMain, QString());
        tabModels = new QWidget();
        tabModels->setObjectName(QString::fromUtf8("tabModels"));
        gridLayout_12 = new QGridLayout(tabModels);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        splitter_2 = new QSplitter(tabModels);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_2);
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

        chbxOutputFiles = new QCheckBox(grpbxWhatToShow);
        chbxOutputFiles->setObjectName(QString::fromUtf8("chbxOutputFiles"));
        chbxOutputFiles->setChecked(true);

        gridLayout->addWidget(chbxOutputFiles, 3, 0, 1, 1);


        vLayout->addWidget(grpbxWhatToShow);

        splitter_2->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        gridLayout_11 = new QGridLayout(layoutWidget1);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        lblModelSpecs = new QLabel(layoutWidget1);
        lblModelSpecs->setObjectName(QString::fromUtf8("lblModelSpecs"));
        lblModelSpecs->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(lblModelSpecs, 0, 0, 1, 1);

        tedModelSpecsModel = new QTextEdit(layoutWidget1);
        tedModelSpecsModel->setObjectName(QString::fromUtf8("tedModelSpecsModel"));

        gridLayout_11->addWidget(tedModelSpecsModel, 1, 0, 1, 2);

        pbViewAsText = new QPushButton(layoutWidget1);
        pbViewAsText->setObjectName(QString::fromUtf8("pbViewAsText"));

        gridLayout_11->addWidget(pbViewAsText, 2, 0, 1, 1);

        pbViewAsHtml = new QPushButton(layoutWidget1);
        pbViewAsHtml->setObjectName(QString::fromUtf8("pbViewAsHtml"));

        gridLayout_11->addWidget(pbViewAsHtml, 2, 1, 1, 1);

        pbExportCsv = new QPushButton(layoutWidget1);
        pbExportCsv->setObjectName(QString::fromUtf8("pbExportCsv"));

        gridLayout_11->addWidget(pbExportCsv, 3, 0, 1, 1);

        pbTableView = new QPushButton(layoutWidget1);
        pbTableView->setObjectName(QString::fromUtf8("pbTableView"));

        gridLayout_11->addWidget(pbTableView, 3, 1, 1, 1);

        splitter_2->addWidget(layoutWidget1);

        gridLayout_12->addWidget(splitter_2, 0, 0, 1, 2);

        pushButton = new QPushButton(tabModels);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_12->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(497, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        tabwidMainWin->addTab(tabModels, QString());
        tabGlossary = new QWidget();
        tabGlossary->setObjectName(QString::fromUtf8("tabGlossary"));
        gridLayout_7 = new QGridLayout(tabGlossary);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        leGlossarySearch = new QLineEdit(tabGlossary);
        leGlossarySearch->setObjectName(QString::fromUtf8("leGlossarySearch"));

        gridLayout_6->addWidget(leGlossarySearch, 0, 0, 1, 1);

        pbGlossarySearch = new QPushButton(tabGlossary);
        pbGlossarySearch->setObjectName(QString::fromUtf8("pbGlossarySearch"));

        gridLayout_6->addWidget(pbGlossarySearch, 0, 1, 1, 1);

        tbrGlossary = new QTextBrowser(tabGlossary);
        tbrGlossary->setObjectName(QString::fromUtf8("tbrGlossary"));

        gridLayout_6->addWidget(tbrGlossary, 1, 0, 1, 2);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblTermTabGlossary = new QLabel(tabGlossary);
        lblTermTabGlossary->setObjectName(QString::fromUtf8("lblTermTabGlossary"));

        horizontalLayout->addWidget(lblTermTabGlossary);

        ledAddTermTerm = new QLineEdit(tabGlossary);
        ledAddTermTerm->setObjectName(QString::fromUtf8("ledAddTermTerm"));

        horizontalLayout->addWidget(ledAddTermTerm);

        pbGlossaryAddTerm = new QPushButton(tabGlossary);
        pbGlossaryAddTerm->setObjectName(QString::fromUtf8("pbGlossaryAddTerm"));

        horizontalLayout->addWidget(pbGlossaryAddTerm);


        gridLayout_7->addLayout(horizontalLayout, 1, 0, 1, 2);

        lblGlossaryDefn = new QLabel(tabGlossary);
        lblGlossaryDefn->setObjectName(QString::fromUtf8("lblGlossaryDefn"));

        gridLayout_7->addWidget(lblGlossaryDefn, 2, 0, 1, 1);

        leGlossaryDefinition = new QLineEdit(tabGlossary);
        leGlossaryDefinition->setObjectName(QString::fromUtf8("leGlossaryDefinition"));

        gridLayout_7->addWidget(leGlossaryDefinition, 2, 1, 1, 1);

        tabwidMainWin->addTab(tabGlossary, QString());
        tabVariables = new QWidget();
        tabVariables->setObjectName(QString::fromUtf8("tabVariables"));
        gridLayout_8 = new QGridLayout(tabVariables);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gbxVariablesTab = new QGroupBox(tabVariables);
        gbxVariablesTab->setObjectName(QString::fromUtf8("gbxVariablesTab"));
        gridLayout_10 = new QGridLayout(gbxVariablesTab);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        splitter_3 = new QSplitter(gbxVariablesTab);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget2 = new QWidget(splitter_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        gridLayout_9 = new QGridLayout(layoutWidget2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        pbAddVariable = new QPushButton(layoutWidget2);
        pbAddVariable->setObjectName(QString::fromUtf8("pbAddVariable"));

        gridLayout_9->addWidget(pbAddVariable, 3, 1, 1, 1);

        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_9->addWidget(comboBox, 3, 0, 1, 1);

        lblVariableTree = new QLabel(layoutWidget2);
        lblVariableTree->setObjectName(QString::fromUtf8("lblVariableTree"));

        gridLayout_9->addWidget(lblVariableTree, 0, 0, 1, 1);

        tblvVariables = new QTableView(layoutWidget2);
        tblvVariables->setObjectName(QString::fromUtf8("tblvVariables"));

        gridLayout_9->addWidget(tblvVariables, 1, 0, 1, 2);

        treeWidget = new QTreeWidget(layoutWidget2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout_9->addWidget(treeWidget, 2, 0, 1, 2);

        splitter_3->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter_3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        gridLayout_3 = new QGridLayout(layoutWidget3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lblVariableMapping = new QLabel(layoutWidget3);
        lblVariableMapping->setObjectName(QString::fromUtf8("lblVariableMapping"));

        gridLayout_3->addWidget(lblVariableMapping, 0, 0, 1, 1);

        splitter = new QSplitter(layoutWidget3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeViewVariables = new QTreeView(splitter);
        treeViewVariables->setObjectName(QString::fromUtf8("treeViewVariables"));
        splitter->addWidget(treeViewVariables);
        tedVariableMapping = new QTextEdit(splitter);
        tedVariableMapping->setObjectName(QString::fromUtf8("tedVariableMapping"));
        splitter->addWidget(tedVariableMapping);

        gridLayout_3->addWidget(splitter, 1, 0, 1, 2);

        comboBox_2 = new QComboBox(layoutWidget3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_3->addWidget(comboBox_2, 2, 0, 1, 1);

        pbRemoveMapping = new QPushButton(layoutWidget3);
        pbRemoveMapping->setObjectName(QString::fromUtf8("pbRemoveMapping"));

        gridLayout_3->addWidget(pbRemoveMapping, 2, 1, 1, 1);

        splitter_3->addWidget(layoutWidget3);

        gridLayout_10->addWidget(splitter_3, 0, 0, 1, 1);


        gridLayout_8->addWidget(gbxVariablesTab, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(tabVariables);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_8->addWidget(pushButton_2, 1, 1, 1, 1);

        tabwidMainWin->addTab(tabVariables, QString());
        tabData = new QWidget();
        tabData->setObjectName(QString::fromUtf8("tabData"));
        gridLayout_5 = new QGridLayout(tabData);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        txtbrwsData = new QTextBrowser(tabData);
        txtbrwsData->setObjectName(QString::fromUtf8("txtbrwsData"));

        gridLayout_5->addWidget(txtbrwsData, 0, 0, 1, 2);

        modelNameComboBox = new QComboBox(tabData);
        modelNameComboBox->setObjectName(QString::fromUtf8("modelNameComboBox"));
        modelNameComboBox->setEnabled(true);
        modelNameComboBox->setModelColumn(0);

        gridLayout_5->addWidget(modelNameComboBox, 1, 0, 1, 1);

        pbClassification = new QPushButton(tabData);
        pbClassification->setObjectName(QString::fromUtf8("pbClassification"));

        gridLayout_5->addWidget(pbClassification, 1, 1, 1, 1);

        tabwidMainWin->addTab(tabData, QString());

        gridLayout_4->addWidget(tabwidMainWin, 1, 0, 1, 1);

        MadMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MadMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 22));
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
#ifndef QT_NO_SHORTCUT
        lblVariableMapping->setBuddy(tedVariableMapping);
#endif // QT_NO_SHORTCUT

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
        MadMainWindow->setWindowTitle(QApplication::translate("MadMainWindow", "MACSUR Model Adapter", 0, QApplication::UnicodeUTF8));
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
        plainTextEdit->setPlainText(QApplication::translate("MadMainWindow", "This software is intended to simplify model integration between the CropM, LiveM, and TradeM themes.\n"
"\n"
"It provides a common platform to describe, evaluate and integrate models and datasets.\n"
"\n"
"It is open source (GPL V.3) and written in C++/Qt (v4.8)", 0, QApplication::UnicodeUTF8));
        lblGraphicMain->setText(QString());
        lblVersion->setText(QApplication::translate("MadMainWindow", "Version Label", 0, QApplication::UnicodeUTF8));
        lblLoginStatus->setText(QApplication::translate("MadMainWindow", "Please Login", 0, QApplication::UnicodeUTF8));
        pbLogin->setText(QApplication::translate("MadMainWindow", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MadMainWindow", "\302\251 Jason Jorgenson 2013", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabMain), QApplication::translate("MadMainWindow", "Main", 0, QApplication::UnicodeUTF8));
        lblCurrentInventory->setText(QApplication::translate("MadMainWindow", "Current AgMIP Translators", 0, QApplication::UnicodeUTF8));
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
        chbxOutputFiles->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all output files created by the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chbxOutputFiles->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all output files created by the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        chbxOutputFiles->setText(QApplication::translate("MadMainWindow", "Output Files", 0, QApplication::UnicodeUTF8));
        lblModelSpecs->setText(QApplication::translate("MadMainWindow", "AgMIP DOMES", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbViewAsText->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbViewAsText->setText(QApplication::translate("MadMainWindow", "View as Text", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbViewAsHtml->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbViewAsHtml->setText(QApplication::translate("MadMainWindow", "View as HTML", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbExportCsv->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbExportCsv->setText(QApplication::translate("MadMainWindow", "Export CSV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbTableView->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbTableView->setText(QApplication::translate("MadMainWindow", "Table View", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MadMainWindow", "Manage Models", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabModels), QApplication::translate("MadMainWindow", "Models", 0, QApplication::UnicodeUTF8));
        pbGlossarySearch->setText(QApplication::translate("MadMainWindow", "Search", 0, QApplication::UnicodeUTF8));
        lblTermTabGlossary->setText(QApplication::translate("MadMainWindow", "Term", 0, QApplication::UnicodeUTF8));
        pbGlossaryAddTerm->setText(QApplication::translate("MadMainWindow", "Add Term", 0, QApplication::UnicodeUTF8));
        lblGlossaryDefn->setText(QApplication::translate("MadMainWindow", "Def'n", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabGlossary), QApplication::translate("MadMainWindow", "Glossary", 0, QApplication::UnicodeUTF8));
        gbxVariablesTab->setTitle(QApplication::translate("MadMainWindow", "Variable Mapping", 0, QApplication::UnicodeUTF8));
        pbAddVariable->setText(QApplication::translate("MadMainWindow", "Add/Map Variable", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "All", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "MACSUR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "ICASA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "DSSAT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "WOFOST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "STICS", 0, QApplication::UnicodeUTF8)
        );
        lblVariableTree->setText(QApplication::translate("MadMainWindow", "Variable Tree", 0, QApplication::UnicodeUTF8));
        lblVariableMapping->setText(QApplication::translate("MadMainWindow", "Variable Mapping", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "All", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "MACSUR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "AgMIP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "ICASA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "DSSAT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "WOFOST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "STICS", 0, QApplication::UnicodeUTF8)
        );
        pbRemoveMapping->setText(QApplication::translate("MadMainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MadMainWindow", "Manage Variables List", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabVariables), QApplication::translate("MadMainWindow", "Variables", 0, QApplication::UnicodeUTF8));
        modelNameComboBox->clear();
        modelNameComboBox->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Select Dataset", 0, QApplication::UnicodeUTF8)
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
         << QApplication::translate("MadMainWindow", "Smith and Reynolds Extended Reconstructed SLP (ERSLP)", 0, QApplication::UnicodeUTF8)
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
