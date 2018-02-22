#include "MainWindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_roomItem0_clicked() {
    selectRoomItem(0);
}

void MainWindow::on_roomItem1_clicked() {
    selectRoomItem(1);
}

void MainWindow::on_roomItem2_clicked() {
    selectRoomItem(2);
}

void MainWindow::on_roomItem3_clicked() {
    selectRoomItem(3);
}

void MainWindow::selectRoomItem(int itemIndex) {
    ui->takeButton->setEnabled(true);
    zork.getCurrentRoomInventory()->selectItem(itemIndex);
    removeRoomItemSelectionFrame();
    roomItemButtons[itemIndex]->setStyleSheet("border: 2px solid blue; outline: none;");
}

void MainWindow::selectInventoryItem(int itemIndex) {
    ui->putButton->setEnabled(true);
    zork.getCharacterInventory()->selectItem(itemIndex);
    removeInventoryItemSelectionFrame();
    inventoryItemButtons[itemIndex]->setStyleSheet("border: 2px solid red; outline: none;");
}

void MainWindow::removeRoomItemSelectionFrame() {
    for (QPushButton* button : roomItemButtons) {
        button->setStyleSheet("");
    }
}

void MainWindow::removeInventoryItemSelectionFrame() {
    for (QPushButton* button : inventoryItemButtons) {
        button->setStyleSheet("");
    }
}

