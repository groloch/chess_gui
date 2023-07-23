#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui/chessboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    ui->boardView->setScene(new ChessBoard(ui->boardView));
}

MainWindow::~MainWindow()
{
    delete ui;
}

