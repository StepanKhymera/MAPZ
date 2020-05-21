#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>




#include "lexer.h"
#include "parser.h"
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

private:
    Ui::MainWindow *ui;
    QStandardItemModel model_raw;

    QStandardItemModel model_optimized;

    QStandardItemModel model_clear;


};

#endif // MAINWINDOW_H
