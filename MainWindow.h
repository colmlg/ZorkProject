#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZorkUL.h"
#include <QMainWindow>
#include <QPushButton>

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


    void on_teleportButton_clicked();
    void on_takeButton_clicked();
    void on_putButton_clicked();
    void on_inventoryButton_clicked();

    void on_roomItem0_clicked();
    void on_roomItem1_clicked();
    void on_roomItem2_clicked();
    void on_roomItem3_clicked();



private:
    Ui::MainWindow *ui;
    ZorkUL zork;
    QPushButton* roomItemButtons[Room::itemSlots];
    QPushButton* inventoryItemButtons[Room::itemSlots];
    void displayCurrentRoomInfo();
    void updateInventoryLabel();
    void setRoomItems();
    void setInventoryItems();
    void selectRoomItem(QPushButton* button);
    void goToRoom(std::string direction);
    void removeItemSelectionFrame();
};

#endif // MAINWINDOW_H
