/********************************************************************************
** Form generated from reading UI file 'madmainwindowbase.ui'
**
** Created: Mon Jul 29 13:52:28 2013
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
#include <QtGui/QLineEdit>
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
#include <QtWebKit/QWebView>

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
    QVBoxLayout *verticalLayout;
    QPushButton *pbLogin;
    QLabel *lblLoginStatus;
    QGridLayout *gridLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *cbAboutMain;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *horizontalSpacer_4;
    QWebView *webView;
    QLabel *lblGraphicMain;
    QLabel *lblVersion;
    QLabel *label;
    QWidget *tabData;
    QGridLayout *gridLayout_5;
    QTextBrowser *txtbrwsData;
    QPushButton *pbClassification;
    QComboBox *modelNameComboBox;
    QWidget *tabModels;
    QGridLayout *gridLayout_11;
    QSplitter *splitterModelTab;
    QTreeWidget *treeWidgetModelTab;
    QTextEdit *tedModelSpecsModel;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *grpbxWhatToShow;
    QGridLayout *gridLayout;
    QCheckBox *chbxInputData;
    QCheckBox *chbxRunCommand;
    QCheckBox *chbxParameters;
    QPushButton *pbViewAsHtml;
    QPushButton *pbExportCsv;
    QPushButton *pbViewAsText;
    QPushButton *pbTableView;
    QCheckBox *chbxOutputFiles;
    QWidget *tab;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_25;
    QComboBox *comboBox_22;
    QComboBox *comboBox_18;
    QComboBox *comboBox_19;
    QComboBox *comboBox_20;
    QComboBox *comboBox_23;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_18;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_22;
    QLabel *label_14;
    QComboBox *comboBox_7;
    QComboBox *comboBox_17;
    QLabel *label_5;
    QComboBox *comboBox_21;
    QComboBox *comboBox_24;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_12;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QWidget *tabGlossary;
    QGridLayout *gridLayout_6;
    QLineEdit *leGlossarySearch;
    QPushButton *pbGlossarySearch;
    QTextBrowser *tbrGlossary;
    QLabel *lblTermTabGlossary;
    QLineEdit *ledAddTermTerm;
    QLabel *lblGlossaryDefn;
    QLineEdit *leGlossaryDefinition;
    QPushButton *pbGlossaryAddTerm;
    QWidget *tabVariables;
    QGridLayout *gridLayout_8;
    QGroupBox *gbxVariablesTab;
    QGridLayout *gridLayout_10;
    QSplitter *splitter_3;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_9;
    QPushButton *pbAddVariable;
    QComboBox *comboBox;
    QLabel *lblVariableTree;
    QTableView *tblvVariables;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_3;
    QLabel *lblVariableMapping;
    QSplitter *splitter;
    QTreeView *treeViewVariables;
    QTextEdit *tedVariableMapping;
    QComboBox *comboBox_2;
    QPushButton *pbRemoveMapping;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbManageVariablesList;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MadMainWindow)
    {
        if (MadMainWindow->objectName().isEmpty())
            MadMainWindow->setObjectName(QString::fromUtf8("MadMainWindow"));
        MadMainWindow->resize(791, 750);
        MadMainWindow->setAutoFillBackground(false);
        actionOpen = new QAction(MadMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionAbout = new QAction(MadMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MadMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabwidMainWin = new QTabWidget(centralWidget);
        tabwidMainWin->setObjectName(QString::fromUtf8("tabwidMainWin"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tabwidMainWin->sizePolicy().hasHeightForWidth());
        tabwidMainWin->setSizePolicy(sizePolicy1);
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        gridLayout_2 = new QGridLayout(tabMain);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pbLogin = new QPushButton(tabMain);
        pbLogin->setObjectName(QString::fromUtf8("pbLogin"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbLogin->sizePolicy().hasHeightForWidth());
        pbLogin->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pbLogin);

        lblLoginStatus = new QLabel(tabMain);
        lblLoginStatus->setObjectName(QString::fromUtf8("lblLoginStatus"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblLoginStatus->sizePolicy().hasHeightForWidth());
        lblLoginStatus->setSizePolicy(sizePolicy3);
        lblLoginStatus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblLoginStatus);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        horizontalSpacer_5 = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_5, 0, 0, 1, 2);

        cbAboutMain = new QComboBox(tabMain);
        cbAboutMain->setObjectName(QString::fromUtf8("cbAboutMain"));

        gridLayout_13->addWidget(cbAboutMain, 0, 2, 1, 1);

        plainTextEdit = new QPlainTextEdit(tabMain);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setPointSize(10);
        plainTextEdit->setFont(font);

        gridLayout_13->addWidget(plainTextEdit, 1, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout_13, 0, 2, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(197, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        webView = new QWebView(tabMain);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("http://www.macsur.eu/")));
        webView->setZoomFactor(0.75);

        gridLayout_2->addWidget(webView, 2, 0, 1, 3);

        lblGraphicMain = new QLabel(tabMain);
        lblGraphicMain->setObjectName(QString::fromUtf8("lblGraphicMain"));
        lblGraphicMain->setMaximumSize(QSize(200, 140));
        lblGraphicMain->setPixmap(QPixmap(QString::fromUtf8(":/newMACSURLogoTransparentFull.png")));
        lblGraphicMain->setScaledContents(true);
        lblGraphicMain->setAlignment(Qt::AlignCenter);
        lblGraphicMain->setOpenExternalLinks(false);

        gridLayout_2->addWidget(lblGraphicMain, 0, 0, 1, 1);

        lblVersion = new QLabel(tabMain);
        lblVersion->setObjectName(QString::fromUtf8("lblVersion"));
        lblVersion->setFont(font);
        lblVersion->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblVersion, 1, 0, 1, 1);

        label = new QLabel(tabMain);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(8);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 3, 0, 1, 3);

        tabwidMainWin->addTab(tabMain, QString());
        tabData = new QWidget();
        tabData->setObjectName(QString::fromUtf8("tabData"));
        gridLayout_5 = new QGridLayout(tabData);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        txtbrwsData = new QTextBrowser(tabData);
        txtbrwsData->setObjectName(QString::fromUtf8("txtbrwsData"));

        gridLayout_5->addWidget(txtbrwsData, 0, 0, 1, 3);

        pbClassification = new QPushButton(tabData);
        pbClassification->setObjectName(QString::fromUtf8("pbClassification"));
        sizePolicy2.setHeightForWidth(pbClassification->sizePolicy().hasHeightForWidth());
        pbClassification->setSizePolicy(sizePolicy2);
        pbClassification->setMaximumSize(QSize(140, 16777215));

        gridLayout_5->addWidget(pbClassification, 1, 2, 1, 1);

        modelNameComboBox = new QComboBox(tabData);
        modelNameComboBox->setObjectName(QString::fromUtf8("modelNameComboBox"));
        modelNameComboBox->setEnabled(true);
        modelNameComboBox->setModelColumn(0);

        gridLayout_5->addWidget(modelNameComboBox, 1, 0, 1, 2);

        tabwidMainWin->addTab(tabData, QString());
        tabModels = new QWidget();
        tabModels->setObjectName(QString::fromUtf8("tabModels"));
        gridLayout_11 = new QGridLayout(tabModels);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        splitterModelTab = new QSplitter(tabModels);
        splitterModelTab->setObjectName(QString::fromUtf8("splitterModelTab"));
        splitterModelTab->setOrientation(Qt::Horizontal);
        treeWidgetModelTab = new QTreeWidget(splitterModelTab);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font2);
        treeWidgetModelTab->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidgetModelTab);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidgetModelTab);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidgetModelTab);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        treeWidgetModelTab->setObjectName(QString::fromUtf8("treeWidgetModelTab"));
        treeWidgetModelTab->setMaximumSize(QSize(256, 16777215));
        splitterModelTab->addWidget(treeWidgetModelTab);
        tedModelSpecsModel = new QTextEdit(splitterModelTab);
        tedModelSpecsModel->setObjectName(QString::fromUtf8("tedModelSpecsModel"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tedModelSpecsModel->sizePolicy().hasHeightForWidth());
        tedModelSpecsModel->setSizePolicy(sizePolicy4);
        splitterModelTab->addWidget(tedModelSpecsModel);

        gridLayout_11->addWidget(splitterModelTab, 0, 0, 1, 2);

        pushButton = new QPushButton(tabModels);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy5);

        gridLayout_11->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        grpbxWhatToShow = new QGroupBox(tabModels);
        grpbxWhatToShow->setObjectName(QString::fromUtf8("grpbxWhatToShow"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(grpbxWhatToShow->sizePolicy().hasHeightForWidth());
        grpbxWhatToShow->setSizePolicy(sizePolicy6);
        grpbxWhatToShow->setFont(font);
        gridLayout = new QGridLayout(grpbxWhatToShow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chbxInputData = new QCheckBox(grpbxWhatToShow);
        chbxInputData->setObjectName(QString::fromUtf8("chbxInputData"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(chbxInputData->sizePolicy().hasHeightForWidth());
        chbxInputData->setSizePolicy(sizePolicy7);
        chbxInputData->setFont(font);
        chbxInputData->setChecked(true);

        gridLayout->addWidget(chbxInputData, 1, 0, 2, 1);

        chbxRunCommand = new QCheckBox(grpbxWhatToShow);
        chbxRunCommand->setObjectName(QString::fromUtf8("chbxRunCommand"));
        sizePolicy7.setHeightForWidth(chbxRunCommand->sizePolicy().hasHeightForWidth());
        chbxRunCommand->setSizePolicy(sizePolicy7);
        chbxRunCommand->setFont(font);
        chbxRunCommand->setChecked(true);

        gridLayout->addWidget(chbxRunCommand, 0, 0, 1, 1);

        chbxParameters = new QCheckBox(grpbxWhatToShow);
        chbxParameters->setObjectName(QString::fromUtf8("chbxParameters"));
        sizePolicy7.setHeightForWidth(chbxParameters->sizePolicy().hasHeightForWidth());
        chbxParameters->setSizePolicy(sizePolicy7);
        chbxParameters->setFont(font);
        chbxParameters->setChecked(true);

        gridLayout->addWidget(chbxParameters, 0, 1, 1, 1);

        pbViewAsHtml = new QPushButton(grpbxWhatToShow);
        pbViewAsHtml->setObjectName(QString::fromUtf8("pbViewAsHtml"));
        sizePolicy7.setHeightForWidth(pbViewAsHtml->sizePolicy().hasHeightForWidth());
        pbViewAsHtml->setSizePolicy(sizePolicy7);
        pbViewAsHtml->setFont(font);

        gridLayout->addWidget(pbViewAsHtml, 0, 2, 2, 1);

        pbExportCsv = new QPushButton(grpbxWhatToShow);
        pbExportCsv->setObjectName(QString::fromUtf8("pbExportCsv"));
        sizePolicy7.setHeightForWidth(pbExportCsv->sizePolicy().hasHeightForWidth());
        pbExportCsv->setSizePolicy(sizePolicy7);
        pbExportCsv->setFont(font);

        gridLayout->addWidget(pbExportCsv, 2, 2, 1, 1);

        pbViewAsText = new QPushButton(grpbxWhatToShow);
        pbViewAsText->setObjectName(QString::fromUtf8("pbViewAsText"));
        sizePolicy7.setHeightForWidth(pbViewAsText->sizePolicy().hasHeightForWidth());
        pbViewAsText->setSizePolicy(sizePolicy7);
        pbViewAsText->setFont(font);

        gridLayout->addWidget(pbViewAsText, 0, 3, 2, 1);

        pbTableView = new QPushButton(grpbxWhatToShow);
        pbTableView->setObjectName(QString::fromUtf8("pbTableView"));
        sizePolicy7.setHeightForWidth(pbTableView->sizePolicy().hasHeightForWidth());
        pbTableView->setSizePolicy(sizePolicy7);
        pbTableView->setFont(font);

        gridLayout->addWidget(pbTableView, 2, 3, 1, 1);

        chbxOutputFiles = new QCheckBox(grpbxWhatToShow);
        chbxOutputFiles->setObjectName(QString::fromUtf8("chbxOutputFiles"));
        sizePolicy7.setHeightForWidth(chbxOutputFiles->sizePolicy().hasHeightForWidth());
        chbxOutputFiles->setSizePolicy(sizePolicy7);
        chbxOutputFiles->setFont(font);
        chbxOutputFiles->setChecked(true);

        gridLayout->addWidget(chbxOutputFiles, 1, 1, 2, 1);


        gridLayout_11->addWidget(grpbxWhatToShow, 2, 0, 1, 2);

        tabwidMainWin->addTab(tabModels, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(43, 101, 73, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(15, 131, 101, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(15, 161, 101, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(15, 191, 101, 16));
        comboBox_3 = new QComboBox(tab);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(121, 99, 111, 26));
        comboBox_4 = new QComboBox(tab);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(121, 129, 111, 26));
        comboBox_5 = new QComboBox(tab);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(121, 159, 111, 26));
        comboBox_6 = new QComboBox(tab);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(121, 189, 111, 26));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 50, 349, 348));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        comboBox_25 = new QComboBox(layoutWidget);
        comboBox_25->setObjectName(QString::fromUtf8("comboBox_25"));
        QFont font3;
        font3.setPointSize(11);
        comboBox_25->setFont(font3);

        gridLayout_7->addWidget(comboBox_25, 9, 2, 1, 1);

        comboBox_22 = new QComboBox(layoutWidget);
        comboBox_22->setObjectName(QString::fromUtf8("comboBox_22"));
        comboBox_22->setFont(font3);

        gridLayout_7->addWidget(comboBox_22, 6, 2, 1, 1);

        comboBox_18 = new QComboBox(layoutWidget);
        comboBox_18->setObjectName(QString::fromUtf8("comboBox_18"));
        comboBox_18->setFont(font3);

        gridLayout_7->addWidget(comboBox_18, 4, 2, 1, 1);

        comboBox_19 = new QComboBox(layoutWidget);
        comboBox_19->setObjectName(QString::fromUtf8("comboBox_19"));
        comboBox_19->setFont(font3);

        gridLayout_7->addWidget(comboBox_19, 2, 2, 1, 1);

        comboBox_20 = new QComboBox(layoutWidget);
        comboBox_20->setObjectName(QString::fromUtf8("comboBox_20"));
        comboBox_20->setFont(font3);

        gridLayout_7->addWidget(comboBox_20, 1, 2, 1, 1);

        comboBox_23 = new QComboBox(layoutWidget);
        comboBox_23->setObjectName(QString::fromUtf8("comboBox_23"));
        comboBox_23->setFont(font3);

        gridLayout_7->addWidget(comboBox_23, 11, 2, 1, 1);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font3);
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_21, 9, 0, 1, 2);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        label_19->setFont(font4);

        gridLayout_7->addWidget(label_19, 4, 0, 1, 1);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font3);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_16, 4, 1, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font3);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_17, 5, 1, 1, 1);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font3);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_23, 8, 0, 1, 2);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font3);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_24, 11, 0, 1, 2);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_18, 6, 1, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font4);

        gridLayout_7->addWidget(label_15, 0, 0, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font3);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_11, 0, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font3);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_12, 1, 1, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_22, 10, 0, 1, 2);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_14, 2, 1, 1, 1);

        comboBox_7 = new QComboBox(layoutWidget);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setFont(font3);

        gridLayout_7->addWidget(comboBox_7, 0, 2, 1, 1);

        comboBox_17 = new QComboBox(layoutWidget);
        comboBox_17->setObjectName(QString::fromUtf8("comboBox_17"));
        comboBox_17->setFont(font3);

        gridLayout_7->addWidget(comboBox_17, 5, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_7->addWidget(label_5, 3, 0, 1, 1);

        comboBox_21 = new QComboBox(layoutWidget);
        comboBox_21->setObjectName(QString::fromUtf8("comboBox_21"));
        comboBox_21->setFont(font3);

        gridLayout_7->addWidget(comboBox_21, 8, 2, 1, 1);

        comboBox_24 = new QComboBox(layoutWidget);
        comboBox_24->setObjectName(QString::fromUtf8("comboBox_24"));
        comboBox_24->setFont(font3);

        gridLayout_7->addWidget(comboBox_24, 10, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 7, 0, 1, 1);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 250, 398, 189));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font3);

        verticalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(layoutWidget1);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font3);

        verticalLayout_2->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(layoutWidget1);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font3);

        verticalLayout_2->addWidget(checkBox_3);

        checkBox_5 = new QCheckBox(layoutWidget1);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setFont(font3);

        verticalLayout_2->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(layoutWidget1);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font3);

        verticalLayout_2->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(layoutWidget1);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setFont(font3);

        verticalLayout_2->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(layoutWidget1);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setFont(font3);

        verticalLayout_2->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(layoutWidget1);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setFont(font3);

        verticalLayout_2->addWidget(checkBox_9);

        checkBox_10 = new QCheckBox(layoutWidget1);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setFont(font3);

        verticalLayout_2->addWidget(checkBox_10);

        checkBox_11 = new QCheckBox(layoutWidget1);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setFont(font3);

        verticalLayout_2->addWidget(checkBox_11);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(27, 10, 381, 54));
        gridLayout_12 = new QGridLayout(layoutWidget2);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_12->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy8);

        gridLayout_12->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_12->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_12->addWidget(lineEdit, 1, 1, 1, 1);

        tabwidMainWin->addTab(tab, QString());
        tabGlossary = new QWidget();
        tabGlossary->setObjectName(QString::fromUtf8("tabGlossary"));
        gridLayout_6 = new QGridLayout(tabGlossary);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        leGlossarySearch = new QLineEdit(tabGlossary);
        leGlossarySearch->setObjectName(QString::fromUtf8("leGlossarySearch"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(leGlossarySearch->sizePolicy().hasHeightForWidth());
        leGlossarySearch->setSizePolicy(sizePolicy9);

        gridLayout_6->addWidget(leGlossarySearch, 0, 0, 1, 2);

        pbGlossarySearch = new QPushButton(tabGlossary);
        pbGlossarySearch->setObjectName(QString::fromUtf8("pbGlossarySearch"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(pbGlossarySearch->sizePolicy().hasHeightForWidth());
        pbGlossarySearch->setSizePolicy(sizePolicy10);

        gridLayout_6->addWidget(pbGlossarySearch, 0, 3, 1, 1);

        tbrGlossary = new QTextBrowser(tabGlossary);
        tbrGlossary->setObjectName(QString::fromUtf8("tbrGlossary"));

        gridLayout_6->addWidget(tbrGlossary, 1, 0, 1, 4);

        lblTermTabGlossary = new QLabel(tabGlossary);
        lblTermTabGlossary->setObjectName(QString::fromUtf8("lblTermTabGlossary"));

        gridLayout_6->addWidget(lblTermTabGlossary, 2, 0, 1, 1);

        ledAddTermTerm = new QLineEdit(tabGlossary);
        ledAddTermTerm->setObjectName(QString::fromUtf8("ledAddTermTerm"));
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(16);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(ledAddTermTerm->sizePolicy().hasHeightForWidth());
        ledAddTermTerm->setSizePolicy(sizePolicy11);

        gridLayout_6->addWidget(ledAddTermTerm, 2, 1, 1, 1);

        lblGlossaryDefn = new QLabel(tabGlossary);
        lblGlossaryDefn->setObjectName(QString::fromUtf8("lblGlossaryDefn"));
        sizePolicy3.setHeightForWidth(lblGlossaryDefn->sizePolicy().hasHeightForWidth());
        lblGlossaryDefn->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(lblGlossaryDefn, 3, 0, 1, 1);

        leGlossaryDefinition = new QLineEdit(tabGlossary);
        leGlossaryDefinition->setObjectName(QString::fromUtf8("leGlossaryDefinition"));
        sizePolicy11.setHeightForWidth(leGlossaryDefinition->sizePolicy().hasHeightForWidth());
        leGlossaryDefinition->setSizePolicy(sizePolicy11);

        gridLayout_6->addWidget(leGlossaryDefinition, 3, 1, 1, 1);

        pbGlossaryAddTerm = new QPushButton(tabGlossary);
        pbGlossaryAddTerm->setObjectName(QString::fromUtf8("pbGlossaryAddTerm"));
        sizePolicy3.setHeightForWidth(pbGlossaryAddTerm->sizePolicy().hasHeightForWidth());
        pbGlossaryAddTerm->setSizePolicy(sizePolicy3);
        pbGlossaryAddTerm->setCheckable(false);

        gridLayout_6->addWidget(pbGlossaryAddTerm, 2, 3, 2, 1);

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
        layoutWidget3 = new QWidget(splitter_3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        gridLayout_9 = new QGridLayout(layoutWidget3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        pbAddVariable = new QPushButton(layoutWidget3);
        pbAddVariable->setObjectName(QString::fromUtf8("pbAddVariable"));

        gridLayout_9->addWidget(pbAddVariable, 3, 1, 1, 1);

        comboBox = new QComboBox(layoutWidget3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_9->addWidget(comboBox, 3, 0, 1, 1);

        lblVariableTree = new QLabel(layoutWidget3);
        lblVariableTree->setObjectName(QString::fromUtf8("lblVariableTree"));

        gridLayout_9->addWidget(lblVariableTree, 0, 0, 1, 1);

        tblvVariables = new QTableView(layoutWidget3);
        tblvVariables->setObjectName(QString::fromUtf8("tblvVariables"));

        gridLayout_9->addWidget(tblvVariables, 1, 0, 1, 2);

        treeWidget = new QTreeWidget(layoutWidget3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem();
        __qtreewidgetitem4->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem4);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout_9->addWidget(treeWidget, 2, 0, 1, 2);

        splitter_3->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(splitter_3);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        gridLayout_3 = new QGridLayout(layoutWidget4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lblVariableMapping = new QLabel(layoutWidget4);
        lblVariableMapping->setObjectName(QString::fromUtf8("lblVariableMapping"));

        gridLayout_3->addWidget(lblVariableMapping, 0, 0, 1, 1);

        splitter = new QSplitter(layoutWidget4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeViewVariables = new QTreeView(splitter);
        treeViewVariables->setObjectName(QString::fromUtf8("treeViewVariables"));
        splitter->addWidget(treeViewVariables);
        tedVariableMapping = new QTextEdit(splitter);
        tedVariableMapping->setObjectName(QString::fromUtf8("tedVariableMapping"));
        splitter->addWidget(tedVariableMapping);

        gridLayout_3->addWidget(splitter, 1, 0, 1, 2);

        comboBox_2 = new QComboBox(layoutWidget4);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_3->addWidget(comboBox_2, 2, 0, 1, 1);

        pbRemoveMapping = new QPushButton(layoutWidget4);
        pbRemoveMapping->setObjectName(QString::fromUtf8("pbRemoveMapping"));

        gridLayout_3->addWidget(pbRemoveMapping, 2, 1, 1, 1);

        splitter_3->addWidget(layoutWidget4);

        gridLayout_10->addWidget(splitter_3, 0, 0, 1, 1);


        gridLayout_8->addWidget(gbxVariablesTab, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 1, 0, 1, 1);

        pbManageVariablesList = new QPushButton(tabVariables);
        pbManageVariablesList->setObjectName(QString::fromUtf8("pbManageVariablesList"));

        gridLayout_8->addWidget(pbManageVariablesList, 1, 1, 1, 1);

        tabwidMainWin->addTab(tabVariables, QString());

        gridLayout_4->addWidget(tabwidMainWin, 0, 0, 1, 1);

        MadMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MadMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 22));
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
        label_4->setBuddy(comboBox_3);
        label_7->setBuddy(comboBox_4);
        label_8->setBuddy(comboBox_5);
        label_9->setBuddy(comboBox_6);
        label_3->setBuddy(lineEdit_2);
        label_2->setBuddy(lineEdit);
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
        pbLogin->setText(QApplication::translate("MadMainWindow", "Login", 0, QApplication::UnicodeUTF8));
        lblLoginStatus->setText(QApplication::translate("MadMainWindow", "Please Login", 0, QApplication::UnicodeUTF8));
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
        label->setText(QApplication::translate("MadMainWindow", "\302\251 Jason Jorgenson 2013", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabMain), QApplication::translate("MadMainWindow", "Main", 0, QApplication::UnicodeUTF8));
        pbClassification->setText(QApplication::translate("MadMainWindow", "Classification", 0, QApplication::UnicodeUTF8));
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
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabData), QApplication::translate("MadMainWindow", "Data", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetModelTab->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MadMainWindow", "Models", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidgetModelTab->isSortingEnabled();
        treeWidgetModelTab->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetModelTab->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MadMainWindow", "Crop Models", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MadMainWindow", "SUCROS", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MadMainWindow", "WOFOST", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MadMainWindow", "GLAM", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidgetModelTab->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MadMainWindow", "Livestock Models", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MadMainWindow", "AnnuGro", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MadMainWindow", "Wadiscape", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidgetModelTab->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MadMainWindow", "Trade Models", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MadMainWindow", "CAPRI", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MadMainWindow", "MAGNET", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem8->child(2);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MadMainWindow", "AGMEMOD", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem8->child(3);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MadMainWindow", "SIAT", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem8->child(4);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MadMainWindow", "A4SMOD", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem8->child(5);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MadMainWindow", "EPIC", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem8->child(6);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MadMainWindow", "FARMDSS", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem8->child(7);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MadMainWindow", "PASMA", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem8->child(8);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MadMainWindow", "FAMOS", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem8->child(9);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MadMainWindow", "IGEM", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem8->child(10);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MadMainWindow", "MODAM", 0, QApplication::UnicodeUTF8));
        treeWidgetModelTab->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("MadMainWindow", "Manage Models", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        grpbxWhatToShow->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Select desired info to display</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        grpbxWhatToShow->setTitle(QApplication::translate("MadMainWindow", "Select what to show", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chbxInputData->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all input files required for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chbxInputData->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all input files required for the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        chbxInputData->setText(QApplication::translate("MadMainWindow", "Input Files", 0, QApplication::UnicodeUTF8));
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
        pbViewAsHtml->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbViewAsHtml->setText(QApplication::translate("MadMainWindow", "View as HTML", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbExportCsv->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbExportCsv->setText(QApplication::translate("MadMainWindow", "Export CSV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbViewAsText->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbViewAsText->setText(QApplication::translate("MadMainWindow", "View as Text", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbTableView->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Details of selection opens in a new text window</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbTableView->setText(QApplication::translate("MadMainWindow", "Table View", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chbxOutputFiles->setToolTip(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all output files created by the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chbxOutputFiles->setWhatsThis(QApplication::translate("MadMainWindow", "<html><head/><body><p>Provides maximum detail of all output files created by the model selected above.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        chbxOutputFiles->setText(QApplication::translate("MadMainWindow", "Output Files", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabModels), QApplication::translate("MadMainWindow", "Models", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MadMainWindow", "Main Model", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MadMainWindow", "Linking Model 1", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MadMainWindow", "Linking Model 2", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MadMainWindow", "Linking Model 3", 0, QApplication::UnicodeUTF8));
        comboBox_25->clear();
        comboBox_25->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_22->clear();
        comboBox_22->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_18->clear();
        comboBox_18->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_19->clear();
        comboBox_19->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_20->clear();
        comboBox_20->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_23->clear();
        comboBox_23->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        label_21->setText(QApplication::translate("MadMainWindow", "Farm-level income effect", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MadMainWindow", "Climate Change", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MadMainWindow", "Mitigation", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MadMainWindow", "Adaptation", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MadMainWindow", "Non-farm income effect", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MadMainWindow", "Social Development effect", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MadMainWindow", "Volatility", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MadMainWindow", "Food Production", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MadMainWindow", "Nutrition", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MadMainWindow", "Production", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MadMainWindow", "Changes to biodiversity", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MadMainWindow", "Consumption", 0, QApplication::UnicodeUTF8));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_17->clear();
        comboBox_17->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QString());
        comboBox_21->clear();
        comboBox_21->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        comboBox_24->clear();
        comboBox_24->insertItems(0, QStringList()
         << QApplication::translate("MadMainWindow", "Not Applicable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Important", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MadMainWindow", "Very Important", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QString());
        checkBox->setText(QApplication::translate("MadMainWindow", "Is Food Security Addressed?", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MadMainWindow", "Are Greenhouse Gas Emissions considered?", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MadMainWindow", "Is Climate Change addressed?", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MadMainWindow", "Is Climate Variability addressed?", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("MadMainWindow", "Is Landuse considered?", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("MadMainWindow", "Are Dynamics of Food Prices addressed?", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("MadMainWindow", "Is Water Use considered?", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("MadMainWindow", "Are other environmental impacts considered?", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("MadMainWindow", "Are Food Markets (supply and/or demand) addressed?", 0, QApplication::UnicodeUTF8));
        checkBox_11->setText(QApplication::translate("MadMainWindow", "Is Competition for resources (land, water, biodiversity) accounted for?", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MadMainWindow", "Scenario", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MadMainWindow", "Organisation", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tab), QApplication::translate("MadMainWindow", "Scenarios", 0, QApplication::UnicodeUTF8));
        pbGlossarySearch->setText(QApplication::translate("MadMainWindow", "Search", 0, QApplication::UnicodeUTF8));
        lblTermTabGlossary->setText(QApplication::translate("MadMainWindow", "Term", 0, QApplication::UnicodeUTF8));
        lblGlossaryDefn->setText(QApplication::translate("MadMainWindow", "Def'n", 0, QApplication::UnicodeUTF8));
        pbGlossaryAddTerm->setText(QApplication::translate("MadMainWindow", "Add\n"
"Term", 0, QApplication::UnicodeUTF8));
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
        pbManageVariablesList->setText(QApplication::translate("MadMainWindow", "Manage Variables List", 0, QApplication::UnicodeUTF8));
        tabwidMainWin->setTabText(tabwidMainWin->indexOf(tabVariables), QApplication::translate("MadMainWindow", "Variables", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MadMainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MadMainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MadMainWindow: public Ui_MadMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADMAINWINDOWBASE_H
