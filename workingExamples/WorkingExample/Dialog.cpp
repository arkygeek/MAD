#include "Dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));
}


void Dialog::setText(const QString &t)
{
    lineEdit->setText(t);
}
