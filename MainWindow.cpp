#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    roomItemButtons[0] = ui->roomItem0;
    roomItemButtons[1] = ui->roomItem1;
    roomItemButtons[2] = ui->roomItem2;
    roomItemButtons[3] = ui->roomItem3;

    inventoryItemButtons[0] = ui->inventoryItem0;
    inventoryItemButtons[1] = ui->inventoryItem1;
    inventoryItemButtons[2] = ui->inventoryItem2;
    inventoryItemButtons[3] = ui->inventoryItem3;

    displayCurrentRoomInfo();
}

void MainWindow::setRoomItems() {
    vector<Item*> items = zork.getCurrentRoomInventory()->getItems();
    for (unsigned int i = 0; i < Room::itemSlots; i++) {
        bool itemExists = i < items.size();
        QIcon icon = itemExists ? *items[i]->icon : QIcon(":/images/emptyItemSlot.png");

        roomItemButtons[i]->setEnabled(itemExists);
        roomItemButtons[i]->setIcon(icon);
    }
}

void MainWindow::setInventoryItems() {
    vector<Item*> items = zork.getCharacterInventory()->getItems();
	for (unsigned int i = 0; i < Room::itemSlots; i++) {
        bool itemExists = i < items.size();
        QIcon icon = itemExists ? *items[i]->icon : QIcon(":/images/emptyItemSlot.png");

        inventoryItemButtons[i]->setEnabled(itemExists);
		inventoryItemButtons[i]->setIcon(icon);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayCurrentRoomInfo() {
    QString roomInfo = QString::fromStdString(zork.getCurrentRoomInfo());
    ui->mainDisplayLabel->setText(roomInfo);

    setRoomItems();
    setInventoryItems();
}

void MainWindow::goToRoom(string direction) {
    zork.getCurrentRoomInventory()->deselectItems();
    removeRoomItemSelectionFrame();
    ui->takeButton->setEnabled(false);
    zork.go(direction);
    displayCurrentRoomInfo();
}

void MainWindow::on_northButton_clicked(){
    goToRoom("north");
}

void MainWindow::on_southButton_clicked() {
    goToRoom("south");
}

void MainWindow::on_eastButton_clicked() {
    goToRoom("east");
}

void MainWindow::on_westButton_clicked() {
    goToRoom("west");
}

void MainWindow::on_teleportButton_clicked() {
    zork.teleport();
    displayCurrentRoomInfo();
}

void MainWindow::on_takeButton_clicked() {
    if (zork.getCharacterInventory()->getNumberOfItems() >= Room::itemSlots) {
        displayAlert("Your inventory is full!\nTry placing an item in the room before taking another one.");
        return;
    }

    for (Item *item : zork.getCurrentRoomInventory()->getItems()) {
        //Todo: put room inventory into a local var
        if (item->isSelected) {
            zork.takeItem(item->getShortDescription());
            log("You took a " + item->getShortDescription() + " from the room.");
            break;
        }
    }
    removeRoomItemSelectionFrame();
    ui->takeButton->setEnabled(false);
    displayCurrentRoomInfo();
}

void MainWindow::on_putButton_clicked() {
    if (zork.getCurrentRoomInventory()->getNumberOfItems() >= Room::itemSlots) {
        displayAlert("The room is full of items!\nTry taking an item from the room before placing another one.");
        return;
    }

    for(Item* item : zork.getCharacterInventory()->getItems()) {
        if (item->isSelected) {
            zork.placeItem(item->getShortDescription());
            log("You placed a " + item->getShortDescription() + " in the room.");
            break;
        }
    }
    removeInventoryItemSelectionFrame();
    ui->putButton->setEnabled(false);
	ui->useButton->setEnabled(false);

    displayCurrentRoomInfo();
}

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
	Inventory* inventory = zork.getCharacterInventory();
	ui->useButton->setEnabled(inventory->getItems()[itemIndex]->action != NULL);
	ui->putButton->setEnabled(true);

	inventory->selectItem(itemIndex);
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

void MainWindow::on_inventoryItem0_clicked() {
    selectInventoryItem(0);
}

void MainWindow::on_inventoryItem1_clicked() {
    selectInventoryItem(1);
}

void MainWindow::on_inventoryItem2_clicked() {
    selectInventoryItem(2);
}

void MainWindow::on_inventoryItem3_clicked() {
    selectInventoryItem(3);
}

void MainWindow::log(string input) {
    ui->gameLog->append(QString::fromStdString(input));
}

void MainWindow::displayAlert(string message) {
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setText(QString::fromStdString(message));
    messageBox.exec();
}

void MainWindow::on_useButton_clicked() {
	vector<Item*> items = zork.getCharacterInventory()->getItems();
	for (int i = 0 ; i < items.size(); i++) {
		if (items[i]->isSelected && items[i]->action != NULL) {
			items[i]->action();
			log(items[i]->getActionDescription());

			if(items[i]->isConsumable()) {
				log("The " + items[i]->getShortDescription() + " is nowhere to be found...");
				zork.getCharacterInventory()->removeItem(i);
				removeInventoryItemSelectionFrame();
				ui->putButton->setEnabled(false);
				ui->useButton->setEnabled(false);
			}

			displayCurrentRoomInfo();
			return;
		}
	}
}
