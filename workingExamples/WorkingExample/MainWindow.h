#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Dialog.h"
#include "ui_MainWindow.h"


class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void pushButton();
    
private:
    Dialog* dial;
};

#endif // MAINWINDOW_H
