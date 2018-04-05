#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "battledialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->attackValue->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);

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
		QString toolTipText = itemExists ? QString::fromStdString(items[i]->getLongDescription()) : "";

        roomItemButtons[i]->setEnabled(itemExists);
        roomItemButtons[i]->setIcon(icon);
		roomItemButtons[i]->setToolTip(toolTipText);
    }
}

void MainWindow::setInventoryItems() {
	vector<Item*> items = zork.getPlayerInventory()->getItems();
	for (unsigned int i = 0; i < Room::itemSlots; i++) {
        bool itemExists = i < items.size();
        QIcon icon = itemExists ? *items[i]->icon : QIcon(":/images/emptyItemSlot.png");
		QString toolTipText = itemExists ? QString::fromStdString(items[i]->getLongDescription()) : "";

        inventoryItemButtons[i]->setEnabled(itemExists);
		inventoryItemButtons[i]->setIcon(icon);
		inventoryItemButtons[i]->setToolTip(toolTipText);
    }
}

void MainWindow::setPlayerEquipment() {
    Weapon* weapon = zork.getPlayer()->getWeapon();
    bool hasWeapon = weapon != NULL;
    QIcon icon = hasWeapon ? *weapon->icon : QIcon(":/images/emptyItemSlot.png");
    QString toolTipText = hasWeapon ? QString::fromStdString(weapon->getLongDescription()) : "";

    ui->weaponSlot->setIcon(icon);
    ui->weaponSlot->setToolTip(toolTipText);
    ui->weaponSlot->setEnabled(hasWeapon);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayCurrentRoomInfo() {
    QString roomInfo = QString::fromStdString(zork.getCurrentRoomInfo());
    ui->mainDisplayLabel->setText(roomInfo);
    ui->healthBar->setValue(zork.getPlayer()->getHealth());
    ui->attackValue->display(zork.getPlayer()->getAttack());
    setRoomItems();
    setInventoryItems();
	setPlayerEquipment();
}

void MainWindow::goToRoom(string direction) {
    zork.getCurrentRoomInventory()->deselectItems();
    removeRoomItemSelectionFrame();
    ui->takeButton->setEnabled(false);
    Room* newRoom = zork.go(direction);
    displayCurrentRoomInfo();
    if (newRoom->hasEnemy()) {
        BattleDialog* dialog = new BattleDialog();
        dialog->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);
        dialog->show();
    }
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
	if (zork.getPlayerInventory()->getNumberOfItems() >= Room::itemSlots) {
        displayAlert("Your inventory is full!\nTry placing an item in the room before taking another one.");
        return;
    }

	zork.takeSelectedItem();
    removeRoomItemSelectionFrame();
    ui->takeButton->setEnabled(false);
    displayCurrentRoomInfo();
}

void MainWindow::on_putButton_clicked() {
    if (zork.getCurrentRoomInventory()->getNumberOfItems() >= Room::itemSlots) {
        displayAlert("The room is full of items!\nTry taking an item from the room before placing another one.");
        return;
    }

	zork.placeSelectedItem();
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

void MainWindow::selectRoomItem(const int itemIndex) {
	removeRoomItemSelectionFrame();
	ui->takeButton->setEnabled(true);
	zork.getCurrentRoomInventory()->selectItem(itemIndex);
	roomItemButtons[itemIndex]->setStyleSheet("QPushButton { border: 2px solid blue; border-radius: 3px; outline: none; }");
}

void MainWindow::selectInventoryItem(const int itemIndex) {
	removeInventoryItemSelectionFrame();
	Inventory* inventory = zork.getPlayerInventory();
	ui->useButton->setEnabled(inventory->getItems()[itemIndex]->action != NULL);
    ui->equipButton->setEnabled(inventory->getItems()[itemIndex]->isWeapon() && zork.getPlayer()->getWeapon() == NULL);
	ui->putButton->setEnabled(true);
	inventory->selectItem(itemIndex);
	inventoryItemButtons[itemIndex]->setStyleSheet("QPushButton { border: 2px solid red; border-radius: 3px; outline: none; }");
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
    ui->weaponSlot->setStyleSheet("");
}

void MainWindow::on_inventoryItem0_clicked() { selectInventoryItem(0); }
void MainWindow::on_inventoryItem1_clicked() { selectInventoryItem(1); }
void MainWindow::on_inventoryItem2_clicked() { selectInventoryItem(2); }
void MainWindow::on_inventoryItem3_clicked() { selectInventoryItem(3); }

void MainWindow::log(string input) {
    ui->gameLog->append(QString::fromStdString(input));
}

void MainWindow::displayAlert(const string message) {
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setText(QString::fromStdString(message));
    messageBox.exec();
}

void MainWindow::on_useButton_clicked() {
	vector<Item*> items = zork.getPlayerInventory()->getItems();
	for (unsigned int i = 0 ; i < items.size(); i++) {
		if (items[i]->isSelected() && items[i]->action != NULL) {
			items[i]->action();
			log(items[i]->getActionDescription());

			if(items[i]->isConsumable()) {
				zork.getPlayerInventory()->removeItem(i);
				removeInventoryItemSelectionFrame();
				ui->putButton->setEnabled(false);
				ui->useButton->setEnabled(false);
			}

			displayCurrentRoomInfo();
			return;
		}
	}
}

void MainWindow::on_weaponSlot_clicked() {
    removeInventoryItemSelectionFrame();
    ui->weaponSlot->setStyleSheet("QPushButton { border: 2px solid red; border-radius: 3px; outline: none; }");
    ui->unequipButton->setEnabled(true);
    ui->putButton->setEnabled(false);
    ui->useButton->setEnabled(false);
}

void MainWindow::on_equipButton_clicked() {
    removeInventoryItemSelectionFrame();
    vector<Item*> items = zork.getPlayerInventory()->getItems();
    for(unsigned int i = 0 ; i < items.size(); i++) {
        if(items[i]->isSelected()) {
            zork.getPlayer()->setWeapon((Weapon*) items[i]);
            zork.getPlayerInventory()->removeItem(i);
            ui->putButton->setEnabled(false);
            ui->equipButton->setEnabled(false);
            displayCurrentRoomInfo();
            return;
        }
    }
}

void MainWindow::on_unequipButton_clicked() {
    vector<Item*> items = zork.getPlayerInventory()->getItems();
    if (items.size() >= 4) {
        displayAlert("Your inventory is too full to unequip this item.");
        return;
    }

    Item* weapon = (Item*) zork.getPlayer()->takeWeapon();
    zork.getPlayerInventory()->addItem(weapon);
    ui->unequipButton->setEnabled(false);
    ui->weaponSlot->setStyleSheet("");
    displayCurrentRoomInfo();
}
