
#include <fstream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "statussingleton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    facade = new Facade(ui->tableWidget_2, ui->label, ui->tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //change status->location
    facade->moveUp();
    //update map
//    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_pushButton_3_clicked()
{
    facade->moveLeft();
//    facade->updateMap(ui->tableWidget_2, ui->label);

}

void MainWindow::on_pushButton_4_clicked()
{
    facade->moveRight();

//    facade->updateMap(ui->tableWidget_2, ui->label);

}

void MainWindow::on_pushButton_2_clicked()
{
    facade->moveDown();
//    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    facade->consume(row);
//    facade->updateInventory(ui->tableWidget);

    ui->tableWidget_2->removeRow(row);
}

void MainWindow::on_actionf_2_triggered()
{
    facade->save();
}

void MainWindow::on_actionLOAD_triggered()
{
    facade->load();
    facade->updateMap(ui->tableWidget_2, ui->label);
    facade->updateInventory(ui->tableWidget);

}

void MainWindow::on_actionPeacefull_triggered()
{
    facade->setDifficultyPeacefull();
    facade->restartDay();
    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_actionEasy_triggered()
{
    facade->setDifficultyEasy();
    facade->restartDay();
    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_actionMedium_triggered()
{
    facade->setDifficultyMedium();
    facade->restartDay();
    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_actionHard_triggered()
{
    facade->setDifficultyHard();
    facade->restartDay();
    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_actionRestart_day_triggered()
{
    facade->restartDay();
    facade->updateMap(ui->tableWidget_2, ui->label);
}

void MainWindow::on_actionsave_to_the_server_triggered()
{
    facade->save();
    facade->saveToServer();
}

void MainWindow::on_actionload_from_the_server_triggered()
{
    facade->loadFromServer();
    facade->updateMap(ui->tableWidget_2, ui->label);
    facade->updateInventory(ui->tableWidget);
}
