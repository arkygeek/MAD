#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    //connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButton()));
}


void MainWindow::on_pushButton_clicked()
{
    dial = new Dialog(this);

    dial->setText(lineEdit->text());
    dial->setModal(true);
    dial->setVisible(true);
}
