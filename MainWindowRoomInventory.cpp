#include "MainWindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_roomItem0_clicked() {
    zork.getCurrentRoomInventory()->items[0]->isSelected = true;
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
    deselectItems();
    button->setStyleSheet("border: 2px solid blue; QPushButton::checked {};");
}

void MainWindow::deselectItems() {
    for (int i = 0; i < Room::itemSlots; i++) {
        roomItemButtons[i]->setStyleSheet("");
    }
}
