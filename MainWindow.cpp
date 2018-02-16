#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    displayCurrentRoomInfo();
    updateInventoryLabel();

//    zork.getCurrentRoomInventory()->items[0]
    for (const Item &item : zork.getCurrentRoomInventory()->items) {
       ui->item0->setIcon(*item.icon);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::displayCurrentRoomInfo() {
    QString roomInfo = QString::fromStdString(zork.getCurrentRoomInfo());
    ui->mainDisplayLabel->setText(roomInfo);
}

void MainWindow::updateInventoryLabel() {
     QString inventory = QString::fromStdString(zork.getCharacterInventory());
     ui->inventoryLabel->setText(inventory);
}

void MainWindow::on_northButton_clicked(){
    zork.go("north");
    displayCurrentRoomInfo();
}

void MainWindow::on_southButton_clicked() {
    zork.go("south");
    displayCurrentRoomInfo();
}

void MainWindow::on_eastButton_clicked() {
    zork.go("east");
    displayCurrentRoomInfo();
}

void MainWindow::on_westButton_clicked() {
    zork.go("west");
    displayCurrentRoomInfo();
}

void MainWindow::on_teleportButton_clicked() {
    zork.teleport();
    displayCurrentRoomInfo();
}

void MainWindow::on_takeButton_clicked() {
    zork.takeItem("x");
    updateInventoryLabel();
    displayCurrentRoomInfo();
}

void MainWindow::on_putButton_clicked() {
    zork.placeItem("x");
    updateInventoryLabel();
    displayCurrentRoomInfo();
}

void MainWindow::on_inventoryButton_clicked() {
   updateInventoryLabel();
}

void MainWindow::on_item0_clicked() {
    ui->item0->setStyleSheet("border: 2px solid blue; QPushButton::checked {};");
}
