#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZorkUL.h"
#include <QMainWindow>
#include <QPushButton>
#include "Constants.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_eastButton_clicked();
    void on_westButton_clicked();

    void on_takeButton_clicked();
    void on_putButton_clicked();

    void on_roomItem0_clicked();
    void on_roomItem1_clicked();
    void on_roomItem2_clicked();
    void on_roomItem3_clicked();

	void on_inventoryItem0_clicked();
    void on_inventoryItem1_clicked();
    void on_inventoryItem2_clicked();
    void on_inventoryItem3_clicked();


    void on_useButton_clicked();

	void on_weaponSlot_clicked();

    void on_equipButton_clicked();

    void on_unequipButton_clicked();

	void on_dialog_finished(int result);

private:
    Ui::MainWindow *ui;
	ZorkUL* zork;
	QPushButton* roomItemButtons[Constants::itemSlots];
	QPushButton* inventoryItemButtons[Constants::itemSlots];
    void displayCurrentRoomInfo();
    void updateInventoryLabel();
	void setItems(QPushButton** buttons, vector<Item*> items);
    void setRoomItems();
    void setInventoryItems();
	void setWeapon();
    void selectRoomItem(int itemIndex);
    void selectInventoryItem(int itemIndex);
    void goToRoom(std::string direction);
    void removeRoomItemSelectionFrame();
    void removeInventoryItemSelectionFrame();
    void log(string input);
    void displayAlert(string message);
	void displayBattleDialog();
	void executeBattleOption(string logMessage);
	void checkGameState();
};

#endif // MAINWINDOW_H
