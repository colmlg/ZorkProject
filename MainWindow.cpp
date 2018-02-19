#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    roomItemButtons[0] = ui->roomItem0;
    roomItemButtons[1] = ui->roomItem1;
    roomItemButtons[2] = ui->roomItem2;
    roomItemButtons[3] = ui->roomItem3;

    displayCurrentRoomInfo();
}

void MainWindow::setRoomItems() {
    vector<Item*> items = zork.getCurrentRoomInventory()->items;
    for (unsigned int i = 0; i < Room::itemSlots; i++) {
        bool itemExists = i < items.size();
        QIcon icon = itemExists ? *items[i]->icon : QIcon();

        roomItemButtons[i]->setEnabled(itemExists);
        roomItemButtons[i]->setIcon(icon);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayCurrentRoomInfo() {
    QString roomInfo = QString::fromStdString(zork.getCurrentRoomInfo());
    ui->mainDisplayLabel->setText(roomInfo);

    updateInventoryLabel();
    setRoomItems();
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
    displayCurrentRoomInfo();
}

void MainWindow::on_putButton_clicked() {
    zork.placeItem("x");
    displayCurrentRoomInfo();
}

void MainWindow::on_inventoryButton_clicked() {
   updateInventoryLabel();
}

void MainWindow::on_roomItem0_clicked() {
    selectRoomItem(ui->roomItem0);
}

void MainWindow::on_roomItem1_clicked() {
    selectRoomItem(ui->roomItem1);
}

void MainWindow::on_roomItem2_clicked() {
    selectRoomItem(ui->roomItem2);
}

void MainWindow::on_roomItem3_clicked() {
    selectRoomItem(ui->roomItem2);
}


void MainWindow::selectRoomItem(QPushButton* button) {
    for (int i = 0; i < Room::itemSlots; i++) {
        roomItemButtons[i]->setStyleSheet("");
    }
    button->setStyleSheet("border: 2px solid blue; QPushButton::checked {};");
}

