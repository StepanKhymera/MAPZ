#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //change status->location
    facade.moveUp();
    //update map
    facade.updateMap(ui->tableWidget_2, ui->label);
   }

void MainWindow::on_pushButton_3_clicked()
{
    facade.moveLeft();
    facade.updateMap(ui->tableWidget_2, ui->label);

}

void MainWindow::on_pushButton_4_clicked()
{
    facade.moveRight();

    facade.updateMap(ui->tableWidget_2, ui->label);

}

void MainWindow::on_pushButton_2_clicked()
{
    facade.moveDown();
    facade.updateMap(ui->tableWidget_2, ui->label);

}

void MainWindow::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    facade.consume(row);
    facade.updateInventory(ui->tableWidget);

    ui->tableWidget_2->removeRow(row);
}
