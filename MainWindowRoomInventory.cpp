#include "MainWindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_roomItem0_clicked() {
    zork.getCurrentRoomInventory()->selectItem(0);
    selectRoomItem(ui->roomItem0);
}

void MainWindow::on_roomItem1_clicked() {
    zork.getCurrentRoomInventory()->selectItem(1);
    selectRoomItem(ui->roomItem1);
}

void MainWindow::on_roomItem2_clicked() {
    zork.getCurrentRoomInventory()->selectItem(2);
    selectRoomItem(ui->roomItem2);
}

void MainWindow::on_roomItem3_clicked() {
    zork.getCurrentRoomInventory()->selectItem(3);
    selectRoomItem(ui->roomItem2);
}

void MainWindow::selectRoomItem(QPushButton* button) {
    removeItemSelectionFrame();
    button->setStyleSheet("border: 2px solid blue; QPushButton::checked {};");
}

void MainWindow::removeItemSelectionFrame() {
    for (QPushButton* button : roomItemButtons) {
        button->setStyleSheet("");
    }
}
