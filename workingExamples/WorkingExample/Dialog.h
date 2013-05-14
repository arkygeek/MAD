#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "ui_Dialog.h"


class Dialog : public QDialog, private Ui::Dialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    void setText(const QString& t);
};

#endif // DIALOG_H
