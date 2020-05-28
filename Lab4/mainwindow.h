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

    void on_actionf_2_triggered();

    void on_actionLOAD_triggered();

    void on_actionPeacefull_triggered();

    void on_actionEasy_triggered();


    void on_actionMedium_triggered();

    void on_actionHard_triggered();

    void on_actionRestart_day_triggered();

    void on_actionsave_to_the_server_triggered();

    void on_actionload_from_the_server_triggered();

private:
    Facade* facade;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
