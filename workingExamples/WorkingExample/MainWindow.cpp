#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    dial = new Dialog(this);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButton()));
}


void MainWindow::pushButton()
{
    dial->setText(lineEdit->text());
    dial->setVisible(true);
}
