#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>


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
    model_raw.clear();
    model_optimized.clear();
    ui->treeView_2->setModel(&model_clear);

    Lexer lexer;
    Parser parser;

    parser.model_raw = &model_raw;
    parser.model_optimized = &model_optimized;

    ui->textEdit_2->setText( lexer.BREAK_DOWN(ui->textEdit->toPlainText()));

    parser.tokens = *lexer.tokens;

    parser.parse();

    parser.optimize();

    ui->treeView->setModel(parser.model_raw);
    ui->treeView_2->setModel(parser.model_optimized);


}
