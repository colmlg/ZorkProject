#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ZorkUL zork;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_northButton_released() {
    ui->mainDisplayLabel->setText("North");
}

void MainWindow::on_eastButton_released() {
    ui->mainDisplayLabel->setText("East");
}

void MainWindow::on_southButton_released() {
    ui->mainDisplayLabel->setText("South");
}

void MainWindow::on_westButton_released() {
    ui->mainDisplayLabel->setText("West");
}
