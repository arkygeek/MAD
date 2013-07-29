/********************************************************************************
** Form generated from reading UI file 'madmodelmanagerbase.ui'
**
** Created: Mon Jul 29 13:52:28 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MADMODELMANAGERBASE_H
#define UI_MADMODELMANAGERBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QSplitter>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MadModelManager
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitterHorizTriple;
    QSplitter *vSplitterLeftSide;
    QTextEdit *tedTemp;
    QListWidget *listwidVarList;
    QTextBrowser *txbrDetails;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutRightSide;
    QTreeWidget *twidDetails;
    QGroupBox *grbxDetails;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayoutName;
    QLabel *lblName;
    QLineEdit *ledName;
    QHBoxLayout *horizontalLayoutUnit;
    QLabel *lblUnit;
    QLineEdit *ledUnit;
    QLabel *lblStatusIcon;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblInitialValue;
    QLineEdit *ledInitialValue;
    QHBoxLayout *horizontalLayoutDescription;
    QLabel *lblDescription;
    QLineEdit *ledDescription;

    void setupUi(QDialog *MadModelManager)
    {
        if (MadModelManager->objectName().isEmpty())
            MadModelManager->setObjectName(QString::fromUtf8("MadModelManager"));
        MadModelManager->resize(1080, 642);
        gridLayout = new QGridLayout(MadModelManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitterHorizTriple = new QSplitter(MadModelManager);
        splitterHorizTriple->setObjectName(QString::fromUtf8("splitterHorizTriple"));
        splitterHorizTriple->setOrientation(Qt::Horizontal);
        vSplitterLeftSide = new QSplitter(splitterHorizTriple);
        vSplitterLeftSide->setObjectName(QString::fromUtf8("vSplitterLeftSide"));
        vSplitterLeftSide->setOrientation(Qt::Vertical);
        tedTemp = new QTextEdit(vSplitterLeftSide);
        tedTemp->setObjectName(QString::fromUtf8("tedTemp"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tedTemp->sizePolicy().hasHeightForWidth());
        tedTemp->setSizePolicy(sizePolicy);
        vSplitterLeftSide->addWidget(tedTemp);
        listwidVarList = new QListWidget(vSplitterLeftSide);
        new QListWidgetItem(listwidVarList);
        new QListWidgetItem(listwidVarList);
        new QListWidgetItem(listwidVarList);
        listwidVarList->setObjectName(QString::fromUtf8("listwidVarList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(listwidVarList->sizePolicy().hasHeightForWidth());
        listwidVarList->setSizePolicy(sizePolicy1);
        vSplitterLeftSide->addWidget(listwidVarList);
        splitterHorizTriple->addWidget(vSplitterLeftSide);
        txbrDetails = new QTextBrowser(splitterHorizTriple);
        txbrDetails->setObjectName(QString::fromUtf8("txbrDetails"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(5);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txbrDetails->sizePolicy().hasHeightForWidth());
        txbrDetails->setSizePolicy(sizePolicy2);
        splitterHorizTriple->addWidget(txbrDetails);
        layoutWidget = new QWidget(splitterHorizTriple);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayoutRightSide = new QVBoxLayout(layoutWidget);
        verticalLayoutRightSide->setObjectName(QString::fromUtf8("verticalLayoutRightSide"));
        verticalLayoutRightSide->setContentsMargins(0, 0, 0, 0);
        twidDetails = new QTreeWidget(layoutWidget);
        QBrush brush(QColor(234, 52, 192, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphics/graphics/addBlue.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("Pink");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8(":/graphics/graphics/ButtonPinkRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon1.addFile(QString::fromUtf8(":/graphics/graphics/ButtonPinkPressed.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        QBrush brush2(QColor(234, 52, 192, 255));
        brush2.setStyle(Qt::NoBrush);
        QFont font1;
        font1.setPointSize(11);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/graphics/graphics/removeGreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush3(QColor(213, 0, 24, 255));
        brush3.setStyle(Qt::NoBrush);
        QIcon icon3;
        iconThemeName = QString::fromUtf8("Red");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8(":/graphics/graphics/buttonRedRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon3.addFile(QString::fromUtf8(":/graphics/graphics/ButtonRedPressed.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        QBrush brush4(QColor(213, 0, 24, 255));
        brush4.setStyle(Qt::NoBrush);
        QBrush brush5(QColor(208, 103, 1, 255));
        brush5.setStyle(Qt::NoBrush);
        QIcon icon4;
        iconThemeName = QString::fromUtf8("Orange");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8(":/graphics/graphics/ButtonOrangeRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon4.addFile(QString::fromUtf8(":/graphics/graphics/ButtonOrangePressed.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        QBrush brush6(QColor(208, 103, 1, 255));
        brush6.setStyle(Qt::NoBrush);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/graphics/graphics/ButtonOrangeRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/graphics/graphics/ButtonOrangePressed.png"), QSize(), QIcon::Normal, QIcon::On);
        QBrush brush7(QColor(208, 103, 1, 255));
        brush7.setStyle(Qt::NoBrush);
        QBrush brush8(QColor(208, 103, 1, 255));
        brush8.setStyle(Qt::NoBrush);
        QBrush brush9(QColor(208, 103, 1, 255));
        brush9.setStyle(Qt::NoBrush);
        QBrush brush10(QColor(208, 103, 1, 255));
        brush10.setStyle(Qt::NoBrush);
        QBrush brush11(QColor(208, 103, 1, 255));
        brush11.setStyle(Qt::NoBrush);
        QBrush brush12(QColor(208, 103, 1, 255));
        brush12.setStyle(Qt::NoBrush);
        QBrush brush13(QColor(208, 103, 1, 255));
        brush13.setStyle(Qt::NoBrush);
        QBrush brush14(QColor(208, 103, 1, 255));
        brush14.setStyle(Qt::NoBrush);
        QBrush brush15(QColor(208, 103, 1, 255));
        brush15.setStyle(Qt::NoBrush);
        QBrush brush16(QColor(159, 0, 159, 255));
        brush16.setStyle(Qt::NoBrush);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/graphics/graphics/ButtonDarkPurpleRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/graphics/graphics/ButtonDarkPurplePressed.png"), QSize(), QIcon::Normal, QIcon::On);
        QBrush brush17(QColor(159, 0, 159, 255));
        brush17.setStyle(Qt::NoBrush);
        QBrush brush18(QColor(50, 52, 198, 255));
        brush18.setStyle(Qt::NoBrush);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/graphics/graphics/BlueButtonRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/graphics/graphics/BlueButtonPushed.png"), QSize(), QIcon::Normal, QIcon::On);
        QBrush brush19(QColor(50, 52, 198, 255));
        brush19.setStyle(Qt::NoBrush);
        QBrush brush20(QColor(50, 52, 198, 255));
        brush20.setStyle(Qt::NoBrush);
        QBrush brush21(QColor(50, 52, 198, 255));
        brush21.setStyle(Qt::NoBrush);
        QBrush brush22(QColor(50, 52, 198, 255));
        brush22.setStyle(Qt::NoBrush);
        QBrush brush23(QColor(50, 52, 198, 255));
        brush23.setStyle(Qt::NoBrush);
        QBrush brush24(QColor(50, 52, 198, 255));
        brush24.setStyle(Qt::NoBrush);
        QBrush brush25(QColor(50, 52, 198, 255));
        brush25.setStyle(Qt::NoBrush);
        QBrush brush26(QColor(10, 110, 60, 255));
        brush26.setStyle(Qt::NoBrush);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/graphics/graphics/ButtonGreenRaised.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/graphics/graphics/ButtonGreenPressed.png"), QSize(), QIcon::Normal, QIcon::On);
        QBrush brush27(QColor(10, 110, 60, 255));
        brush27.setStyle(Qt::NoBrush);
        QBrush brush28(QColor(10, 110, 60, 255));
        brush28.setStyle(Qt::NoBrush);
        QBrush brush29(QColor(10, 110, 60, 255));
        brush29.setStyle(Qt::NoBrush);
        QBrush brush30(QColor(10, 110, 60, 255));
        brush30.setStyle(Qt::NoBrush);
        QBrush brush31(QColor(10, 110, 60, 255));
        brush31.setStyle(Qt::NoBrush);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(twidDetails);
        __qtreewidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        __qtreewidgetitem->setIcon(1, icon);
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setBackground(0, brush1);
        __qtreewidgetitem->setForeground(0, brush);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        __qtreewidgetitem1->setIcon(1, icon2);
        __qtreewidgetitem1->setFont(0, font1);
        __qtreewidgetitem1->setForeground(0, brush2);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(twidDetails);
        __qtreewidgetitem2->setIcon(1, icon);
        __qtreewidgetitem2->setFont(0, font);
        __qtreewidgetitem2->setForeground(0, brush3);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem3->setIcon(1, icon2);
        __qtreewidgetitem3->setFont(0, font1);
        __qtreewidgetitem3->setForeground(0, brush4);
        __qtreewidgetitem3->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(twidDetails);
        __qtreewidgetitem4->setIcon(1, icon);
        __qtreewidgetitem4->setFont(0, font);
        __qtreewidgetitem4->setForeground(0, brush5);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setIcon(1, icon2);
        __qtreewidgetitem5->setFont(0, font1);
        __qtreewidgetitem5->setForeground(0, brush6);
        __qtreewidgetitem5->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem6->setIcon(1, icon2);
        __qtreewidgetitem6->setFont(0, font1);
        __qtreewidgetitem6->setForeground(0, brush7);
        __qtreewidgetitem6->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem7->setIcon(1, icon2);
        __qtreewidgetitem7->setFont(0, font1);
        __qtreewidgetitem7->setForeground(0, brush8);
        __qtreewidgetitem7->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem8->setIcon(1, icon2);
        __qtreewidgetitem8->setFont(0, font1);
        __qtreewidgetitem8->setForeground(0, brush9);
        __qtreewidgetitem8->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem9->setIcon(1, icon2);
        __qtreewidgetitem9->setFont(0, font1);
        __qtreewidgetitem9->setForeground(0, brush10);
        __qtreewidgetitem9->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem10->setIcon(1, icon2);
        __qtreewidgetitem10->setFont(0, font1);
        __qtreewidgetitem10->setForeground(0, brush11);
        __qtreewidgetitem10->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem11->setIcon(1, icon2);
        __qtreewidgetitem11->setFont(0, font1);
        __qtreewidgetitem11->setForeground(0, brush12);
        __qtreewidgetitem11->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem12->setIcon(1, icon2);
        __qtreewidgetitem12->setFont(0, font1);
        __qtreewidgetitem12->setForeground(0, brush13);
        __qtreewidgetitem12->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem13->setIcon(1, icon2);
        __qtreewidgetitem13->setFont(0, font1);
        __qtreewidgetitem13->setForeground(0, brush14);
        __qtreewidgetitem13->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem14->setIcon(1, icon2);
        __qtreewidgetitem14->setFont(0, font1);
        __qtreewidgetitem14->setForeground(0, brush15);
        __qtreewidgetitem14->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(twidDetails);
        __qtreewidgetitem15->setIcon(1, icon);
        __qtreewidgetitem15->setFont(0, font);
        __qtreewidgetitem15->setForeground(0, brush16);
        QTreeWidgetItem *__qtreewidgetitem16 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem16->setIcon(1, icon2);
        __qtreewidgetitem16->setFont(0, font1);
        __qtreewidgetitem16->setForeground(0, brush17);
        __qtreewidgetitem16->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem17 = new QTreeWidgetItem(twidDetails);
        __qtreewidgetitem17->setIcon(1, icon);
        __qtreewidgetitem17->setFont(0, font1);
        __qtreewidgetitem17->setForeground(0, brush18);
        QTreeWidgetItem *__qtreewidgetitem18 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem18->setIcon(1, icon2);
        __qtreewidgetitem18->setFont(0, font1);
        __qtreewidgetitem18->setForeground(0, brush19);
        __qtreewidgetitem18->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem19 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem19->setIcon(1, icon2);
        __qtreewidgetitem19->setFont(0, font1);
        __qtreewidgetitem19->setForeground(0, brush20);
        __qtreewidgetitem19->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem20 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem20->setIcon(1, icon2);
        __qtreewidgetitem20->setFont(0, font1);
        __qtreewidgetitem20->setForeground(0, brush21);
        __qtreewidgetitem20->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem21 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem21->setIcon(1, icon2);
        __qtreewidgetitem21->setFont(0, font1);
        __qtreewidgetitem21->setForeground(0, brush22);
        __qtreewidgetitem21->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem22 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem22->setIcon(1, icon2);
        __qtreewidgetitem22->setFont(0, font1);
        __qtreewidgetitem22->setForeground(0, brush23);
        __qtreewidgetitem22->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem23 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem23->setIcon(1, icon2);
        __qtreewidgetitem23->setFont(0, font1);
        __qtreewidgetitem23->setForeground(0, brush24);
        __qtreewidgetitem23->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem24 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem24->setIcon(1, icon2);
        __qtreewidgetitem24->setFont(0, font1);
        __qtreewidgetitem24->setForeground(0, brush25);
        __qtreewidgetitem24->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem25 = new QTreeWidgetItem(twidDetails);
        __qtreewidgetitem25->setIcon(1, icon);
        __qtreewidgetitem25->setFont(0, font);
        __qtreewidgetitem25->setForeground(0, brush26);
        QTreeWidgetItem *__qtreewidgetitem26 = new QTreeWidgetItem(__qtreewidgetitem25);
        __qtreewidgetitem26->setIcon(1, icon2);
        __qtreewidgetitem26->setFont(0, font1);
        __qtreewidgetitem26->setForeground(0, brush27);
        __qtreewidgetitem26->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem27 = new QTreeWidgetItem(__qtreewidgetitem25);
        __qtreewidgetitem27->setIcon(1, icon2);
        __qtreewidgetitem27->setFont(0, font1);
        __qtreewidgetitem27->setForeground(0, brush28);
        __qtreewidgetitem27->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem28 = new QTreeWidgetItem(__qtreewidgetitem25);
        __qtreewidgetitem28->setIcon(1, icon2);
        __qtreewidgetitem28->setFont(0, font1);
        __qtreewidgetitem28->setForeground(0, brush29);
        __qtreewidgetitem28->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem29 = new QTreeWidgetItem(__qtreewidgetitem25);
        __qtreewidgetitem29->setIcon(1, icon2);
        __qtreewidgetitem29->setFont(0, font1);
        __qtreewidgetitem29->setForeground(0, brush30);
        __qtreewidgetitem29->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem30 = new QTreeWidgetItem(__qtreewidgetitem25);
        __qtreewidgetitem30->setIcon(1, icon2);
        __qtreewidgetitem30->setFont(0, font1);
        __qtreewidgetitem30->setForeground(0, brush31);
        __qtreewidgetitem30->setIcon(0, icon8);
        twidDetails->setObjectName(QString::fromUtf8("twidDetails"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(3);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(twidDetails->sizePolicy().hasHeightForWidth());
        twidDetails->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(13);
        twidDetails->setFont(font2);
        twidDetails->setAcceptDrops(true);
        twidDetails->setAutoFillBackground(false);
        twidDetails->setFrameShape(QFrame::NoFrame);
        twidDetails->setFrameShadow(QFrame::Plain);
        twidDetails->setLineWidth(0);
        twidDetails->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        twidDetails->setDefaultDropAction(Qt::CopyAction);
        twidDetails->setAlternatingRowColors(false);
        twidDetails->setIconSize(QSize(12, 12));
        twidDetails->setTextElideMode(Qt::ElideNone);
        twidDetails->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        twidDetails->setIndentation(14);
        twidDetails->setRootIsDecorated(true);
        twidDetails->setUniformRowHeights(false);
        twidDetails->setAnimated(true);
        twidDetails->setColumnCount(2);
        twidDetails->header()->setVisible(false);
        twidDetails->header()->setCascadingSectionResizes(false);
        twidDetails->header()->setDefaultSectionSize(230);
        twidDetails->header()->setHighlightSections(false);
        twidDetails->header()->setProperty("showSortIndicator", QVariant(false));

        verticalLayoutRightSide->addWidget(twidDetails);

        grbxDetails = new QGroupBox(layoutWidget);
        grbxDetails->setObjectName(QString::fromUtf8("grbxDetails"));
        grbxDetails->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(grbxDetails);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayoutName = new QHBoxLayout();
        horizontalLayoutName->setObjectName(QString::fromUtf8("horizontalLayoutName"));
        lblName = new QLabel(grbxDetails);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lblName->sizePolicy().hasHeightForWidth());
        lblName->setSizePolicy(sizePolicy4);
        lblName->setFont(font1);

        horizontalLayoutName->addWidget(lblName);

        ledName = new QLineEdit(grbxDetails);
        ledName->setObjectName(QString::fromUtf8("ledName"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(4);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(ledName->sizePolicy().hasHeightForWidth());
        ledName->setSizePolicy(sizePolicy5);

        horizontalLayoutName->addWidget(ledName);


        verticalLayout_2->addLayout(horizontalLayoutName);

        horizontalLayoutUnit = new QHBoxLayout();
        horizontalLayoutUnit->setObjectName(QString::fromUtf8("horizontalLayoutUnit"));
        lblUnit = new QLabel(grbxDetails);
        lblUnit->setObjectName(QString::fromUtf8("lblUnit"));
        lblUnit->setFont(font1);

        horizontalLayoutUnit->addWidget(lblUnit);

        ledUnit = new QLineEdit(grbxDetails);
        ledUnit->setObjectName(QString::fromUtf8("ledUnit"));
        ledUnit->setFont(font1);

        horizontalLayoutUnit->addWidget(ledUnit);

        lblStatusIcon = new QLabel(grbxDetails);
        lblStatusIcon->setObjectName(QString::fromUtf8("lblStatusIcon"));
        lblStatusIcon->setMaximumSize(QSize(20, 20));
        lblStatusIcon->setPixmap(QPixmap(QString::fromUtf8(":/status_ok.png")));
        lblStatusIcon->setScaledContents(true);

        horizontalLayoutUnit->addWidget(lblStatusIcon);


        verticalLayout_2->addLayout(horizontalLayoutUnit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblInitialValue = new QLabel(grbxDetails);
        lblInitialValue->setObjectName(QString::fromUtf8("lblInitialValue"));
        lblInitialValue->setFont(font1);

        horizontalLayout_3->addWidget(lblInitialValue);

        ledInitialValue = new QLineEdit(grbxDetails);
        ledInitialValue->setObjectName(QString::fromUtf8("ledInitialValue"));
        ledInitialValue->setFont(font1);

        horizontalLayout_3->addWidget(ledInitialValue);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayoutDescription = new QHBoxLayout();
        horizontalLayoutDescription->setObjectName(QString::fromUtf8("horizontalLayoutDescription"));
        lblDescription = new QLabel(grbxDetails);
        lblDescription->setObjectName(QString::fromUtf8("lblDescription"));
        lblDescription->setFont(font1);

        horizontalLayoutDescription->addWidget(lblDescription);

        ledDescription = new QLineEdit(grbxDetails);
        ledDescription->setObjectName(QString::fromUtf8("ledDescription"));
        ledDescription->setFont(font1);

        horizontalLayoutDescription->addWidget(ledDescription);


        verticalLayout_2->addLayout(horizontalLayoutDescription);


        verticalLayoutRightSide->addWidget(grbxDetails);

        splitterHorizTriple->addWidget(layoutWidget);

        gridLayout->addWidget(splitterHorizTriple, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        lblName->setBuddy(ledName);
        lblUnit->setBuddy(ledUnit);
        lblInitialValue->setBuddy(ledInitialValue);
        lblDescription->setBuddy(ledDescription);
#endif // QT_NO_SHORTCUT

        retranslateUi(MadModelManager);

        QMetaObject::connectSlotsByName(MadModelManager);
    } // setupUi

    void retranslateUi(QDialog *MadModelManager)
    {
        MadModelManager->setWindowTitle(QApplication::translate("MadModelManager", "Dialog", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listwidVarList->isSortingEnabled();
        listwidVarList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listwidVarList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MadModelManager", "a", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listwidVarList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MadModelManager", "b", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listwidVarList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MadModelManager", "c", 0, QApplication::UnicodeUTF8));
        listwidVarList->setSortingEnabled(__sortingEnabled);

        txbrDetails->setHtml(QApplication::translate("MadModelManager", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">RCGro is a model for simulation of sap flow dynamics and stem diameter variations in individual trees.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Whole-tree leaf transpiration is used as the only input.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Constant capacitance of the storage tissues (electrical analogue approach).</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-lef"
                        "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Radial stem growth based on Lockhart's equation for irreversible cell expansion.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Constant soil water potential</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------------------</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Steppe K., De Pauw D.J.W., Lemeur R. and Vanrolleghem P.A. (2006). A mathematical model linking tree sap flow dynamics to daily stem diameter fluctuations and radial stem growth. Tree Physiology, 26(3), 257-273.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px;"
                        " margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(http://dx.doi.org/10.1093/treephys/26.3.257)</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------------------</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; ma"
                        "rgin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// --------------------------------------------------------------</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Initial section (calculated once at the start of a simulation)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// --------------------------------------------------------------</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Thickness of the storage compartment (Eq. 18)</p>\n"
"<p style=\" margin-top:0px; mar"
                        "gin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Empirical relationship taken from G\303\203\302\251nard et al. (2001)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">initial( d_S ) = a * ( 1 - exp( -b * initial( D_outer ) ) )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Initial value of the inner stem segment (Eq. 15)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">initial( D_inner ) = initial( D_outer ) - 2 * initial( d_S )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-i"
                        "ndent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Assumed proportional to the water potential of the root xylem</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// For night time conditions (after Fanjul and Rosher (1984)) (Eq. 44)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">initial( Psi_S_stem_p ) = Beta * ( Psi_X_roots - Psi_X_stem_Psi_S_stem_p_0 )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// ------------------------------------------</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Equations (calculated at each solver step)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// ------------------------------------------</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// --- Water transport submodel ---</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Calculate the water potentials of the storage compartments (Eq. 13)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; ma"
                        "rgin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Psi_S_stem = Psi_X_roots + W_stem / C_stem</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Psi_S_crown = Psi_X_roots + W_crown / C_crown</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Calculation of the exchange resistance between the xylem and the storage compartment (Eq. 41)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// This is iversely proportional to the radial hydraulic conductivity L</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">A = pi() * D_inner"
                        " * l</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">R_S = 1.0 / ( A * Rho_w * L ) </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Water exchange between the xylem and the storage compartment of the stem (Eq. 11)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">deriv( W_stem ) = ( R_X + R_S ) </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                  / ( ( R_X + R_S ) * ( R_X + 2.0 * R_S ) - ( R_S * R_S ) )</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px;\">                  * ( Psi_X_roots  + ( ( R_S / ( R_X + R_S ) ) - 2.0 ) * Psi_S_stem</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                  + ( 1.0 - ( R_S / ( R_X + R_S ) ) ) * Psi_S_crown </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                  - E * R_X * R_S / ( R_X + R_S ) )</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f_stem = deriv( W_stem )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Stem xylem water potential (Eq. 8)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Psi_X_stem = deriv( W_stem ) * R_S + Psi_S_stem</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Water exchange between the xylem and the storage compartment of the crown (Eq. 9)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">deriv( W_crown ) = ( Psi_X_stem - Psi_S_crown - R_X * E ) / ( R_X + R_S )</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f_crown = deriv( W_crown )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Crown xylem water potential (Eq. 8)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Psi_X_crown = deriv( W_crown ) * R_S + Psi_S_crown</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Vertical water transport between the roots and the stem (Eq. 1)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F_stem = ( Psi_X_roots - Psi_X_stem ) / R_X</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Vertical water transport between the "
                        "stem and the crown (Eq. 2)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F_crown = ( Psi_X_stem - Psi_X_crown ) / R_X</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// --- Stem diameter submodel ---</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Volume of the storage compartment (assuming d_S much smaller than D_inner) (Eq. 17)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0"
                        "px;\">V_stem = pi() * d_S * D_inner * l</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Change in pressure potential resulting from the flow of water in and out of the</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// stem storage compartment (Eq. 36)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">deriv( Psi_S_stem_p ) = deriv( W_stem ) * Epsilon_0 * Psi_S_stem_p * D_outer </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                        / ( Rho_w * V_stem )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; marg"
                        "in-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Check for growth</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">if ( Psi_S_stem_p &gt; Gamma )</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">{</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  // Stem diameter variation due to elastic changes and growth (Eq. 30)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  deriv( D_outer ) = 2.0 * d_S * deriv( Psi_S_stem_p ) / ( Epsilon_0 * Psi_S_stem_p * D_outer ) </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                     + ( d_S * Phi * ( Psi_S_stem_p - Gamma ) / ( b * ( a - d_S ) ) )</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">}</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">else</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">{</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  // Stem diameter variation due to elastic changes only (Eq. 31)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  deriv( D_outer ) = 2.0 * d_S * deriv( Psi_S_stem_p ) / ( Epsilon_0 * Psi_S_stem_p * D_outer )</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; m"
                        "argin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">}</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Bulk elastic modulus (Eq. 20)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Epsilon = Epsilon_0 * Psi_S_stem_p * D_outer</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Osmotic water potential component (Eq. 37)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-in"
                        "dent:0px;\">Psi_S_stem_o = Psi_S_stem_p - Psi_S_stem</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Thickness change of the storage compartment (Eq. 32)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">deriv( d_S ) = a * b * exp( -b * D_outer ) * deriv( D_outer )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">// Inner diameter variation (Eq. 33)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\">deriv( D_inner ) = deriv( D_outer ) - 2.0 * deriv( d_S )</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = twidDetails->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MadModelManager", "Add", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MadModelManager", "Specifics", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = twidDetails->isSortingEnabled();
        twidDetails->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = twidDetails->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MadModelManager", "Independent Variable", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MadModelManager", "t", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = twidDetails->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MadModelManager", "Constants", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MadModelManager", "Rho_w", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = twidDetails->topLevelItem(2);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MadModelManager", "Parameters", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MadModelManager", "Psi_soil", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MadModelManager", "R_X", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MadModelManager", "C_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem5->child(3);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MadModelManager", "I", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem5->child(4);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MadModelManager", "Phi", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem5->child(5);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MadModelManager", "Gamma", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem5->child(6);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MadModelManager", "Epsilon_0", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem5->child(7);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MadModelManager", "a", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem5->child(8);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MadModelManager", "b", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem5->child(9);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MadModelManager", "R_S", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem16 = twidDetails->topLevelItem(3);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MadModelManager", "Data Variables", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem16->child(0);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MadModelManager", "F_crown", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem18 = twidDetails->topLevelItem(4);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MadModelManager", "Algebraic Variables", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MadModelManager", "Psi_S_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem18->child(1);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MadModelManager", "Psi_S_stem_o", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem18->child(2);
        ___qtreewidgetitem21->setText(0, QApplication::translate("MadModelManager", "Psi_X_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem18->child(3);
        ___qtreewidgetitem22->setText(0, QApplication::translate("MadModelManager", "F_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem18->child(4);
        ___qtreewidgetitem23->setText(0, QApplication::translate("MadModelManager", "f_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem18->child(5);
        ___qtreewidgetitem24->setText(0, QApplication::translate("MadModelManager", "V_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem18->child(6);
        ___qtreewidgetitem25->setText(0, QApplication::translate("MadModelManager", "Epsilon", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem26 = twidDetails->topLevelItem(5);
        ___qtreewidgetitem26->setText(0, QApplication::translate("MadModelManager", "Derived Variables", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem27 = ___qtreewidgetitem26->child(0);
        ___qtreewidgetitem27->setText(0, QApplication::translate("MadModelManager", "W_stem", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem28 = ___qtreewidgetitem26->child(1);
        ___qtreewidgetitem28->setText(0, QApplication::translate("MadModelManager", "Psi_S_stem_p", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem29 = ___qtreewidgetitem26->child(2);
        ___qtreewidgetitem29->setText(0, QApplication::translate("MadModelManager", "D_outer", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem30 = ___qtreewidgetitem26->child(3);
        ___qtreewidgetitem30->setText(0, QApplication::translate("MadModelManager", "d_S", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem31 = ___qtreewidgetitem26->child(4);
        ___qtreewidgetitem31->setText(0, QApplication::translate("MadModelManager", "D_inner", 0, QApplication::UnicodeUTF8));
        twidDetails->setSortingEnabled(__sortingEnabled1);

        grbxDetails->setTitle(QString());
        lblName->setText(QApplication::translate("MadModelManager", "Name", 0, QApplication::UnicodeUTF8));
        lblUnit->setText(QApplication::translate("MadModelManager", "Unit", 0, QApplication::UnicodeUTF8));
        lblStatusIcon->setText(QString());
        lblInitialValue->setText(QApplication::translate("MadModelManager", "Initial Value", 0, QApplication::UnicodeUTF8));
        lblDescription->setText(QApplication::translate("MadModelManager", "Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MadModelManager: public Ui_MadModelManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADMODELMANAGERBASE_H
