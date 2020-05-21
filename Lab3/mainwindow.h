#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "builder.h"
#include "facade.h"

#include <windows.h>
static HANDLE hMutex;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_2_cellDoubleClicked(int row, int column);

private:
    Facade facade;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
