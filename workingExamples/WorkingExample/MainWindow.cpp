#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dial = new Dialog(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButton()
{
    dial->setText(ui->lineEdit->text());
    dial->setVisible(true);
}
