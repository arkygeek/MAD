#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setText(const QString &t)
{
    ui->lineEdit->setText(t);
}
