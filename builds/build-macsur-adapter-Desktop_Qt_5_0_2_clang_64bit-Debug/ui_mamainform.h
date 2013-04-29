/********************************************************************************
** Form generated from reading UI file 'mamainform.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAMAINFORM_H
#define UI_MAMAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaMainForm
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MaMainForm)
    {
        if (MaMainForm->objectName().isEmpty())
            MaMainForm->setObjectName(QStringLiteral("MaMainForm"));
        MaMainForm->resize(400, 300);
        menuBar = new QMenuBar(MaMainForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MaMainForm->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MaMainForm);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MaMainForm->addToolBar(mainToolBar);
        centralWidget = new QWidget(MaMainForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MaMainForm->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MaMainForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MaMainForm->setStatusBar(statusBar);

        retranslateUi(MaMainForm);

        QMetaObject::connectSlotsByName(MaMainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MaMainForm)
    {
        MaMainForm->setWindowTitle(QApplication::translate("MaMainForm", "MaMainForm", 0));
    } // retranslateUi

};

namespace Ui {
    class MaMainForm: public Ui_MaMainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAMAINFORM_H
